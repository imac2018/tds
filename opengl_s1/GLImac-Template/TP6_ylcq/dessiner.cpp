// NE ME JUGEZ PAS CE CODE N'EST PAS BEAU NI OPTIMISE NE ME JUGEZ PAS SVP THX

#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/FreeflyCamera.hpp>
#include <glimac/glm.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>

using namespace glimac;
using namespace glm;

void logActiveUniforms(GLuint progid) {
    glUseProgram(progid);
    int total = -1;
    glGetProgramiv( progid, GL_ACTIVE_UNIFORMS, &total ); 
    for(int i=0; i<total; ++i)  {
        int name_len=-1, num=-1;
        GLenum type = GL_ZERO;
        char name[100];
        glGetActiveUniform( progid, GLuint(i), sizeof(name)-1,
                            &name_len, &num, &type, name );
        name[name_len] = 0;
        std::cout << "Active uniform : " << std::string(name) << std::endl;
        GLuint location = glGetUniformLocation( progid, name );
    }
}



struct EarthProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uEarthTexture;
    GLint uCloudTexture;

    EarthProgram(const FilePath& applicationPath)
        : m_Program(loadProgram(
            applicationPath.dirPath() + "shaders/3D.vs.glsl",
            applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl")) 
    {
        uMVPMatrix    = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix     = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uEarthTexture = glGetUniformLocation(m_Program.getGLId(), "uEarthTexture");
        uCloudTexture = glGetUniformLocation(m_Program.getGLId(), "uCloudTexture");
        assert(uMVPMatrix != -1);
        assert(uMVMatrix != -1);
        assert(uNormalMatrix != -1);
        assert(uEarthTexture != -1);
        assert(uCloudTexture != -1);
    }
};

struct MoonProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;

    MoonProgram(const FilePath& applicationPath)
        : m_Program(loadProgram(
            applicationPath.dirPath() + "shaders/3D.vs.glsl",
            applicationPath.dirPath() + "shaders/tex3D.fs.glsl")) 
    {
        uMVPMatrix    = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix     = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTexture      = glGetUniformLocation(m_Program.getGLId(), "uTexture");
        assert(uMVPMatrix != -1);
        assert(uMVMatrix != -1);
        assert(uNormalMatrix != -1);
        assert(uTexture != -1);
    }
};


int main(int argc, char** argv) {
    static const size_t win_w = 800, win_h = 600;
    // Initialize SDL and open a window
    SDLWindowManager windowManager(win_w, win_h, "Ce n'est même pas ma forme finale !");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    Sphere sphere(1, 32, 16);

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    size_t ShapeVertex_size = sizeof(ShapeVertex);//4*(3+2+2);
    glBufferData(GL_ARRAY_BUFFER, 
        sphere.getVertexCount()*ShapeVertex_size, 
        sphere.getDataPointer(), GL_STATIC_DRAW
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));
    }
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    FilePath applicationPath(argv[0]);


    std::string earth_map_path = applicationPath.dirPath() 
        + "../../GLImac-Template/assets/textures/EarthMap.jpg";
    std::string moon_map_path = applicationPath.dirPath() 
        + "../../GLImac-Template/assets/textures/MoonMap.jpg";
    std::string cloud_map_path = applicationPath.dirPath() 
        + "../../GLImac-Template/assets/textures/CloudMap.jpg";


    std::unique_ptr<Image> earth_map_img = loadImage(earth_map_path);
    if(!earth_map_img) {
        std::cerr << "N'a pas pu charger " << earth_map_path << " !" << std::endl;
        return EXIT_FAILURE;
    }
    std::unique_ptr<Image> moon_map_img = loadImage(moon_map_path);
    if(!moon_map_img) {
        std::cerr << "N'a pas pu charger " << moon_map_path << " !" << std::endl;
        return EXIT_FAILURE;
    }
    std::unique_ptr<Image> cloud_map_img = loadImage(cloud_map_path);
    if(!cloud_map_img) {
        std::cerr << "N'a pas pu charger " << cloud_map_path << " !" << std::endl;
        return EXIT_FAILURE;
    }


    GLuint earth_map_tex=0, moon_map_tex=0, cloud_map_tex=0;
    glGenTextures(1, &earth_map_tex);
    glGenTextures(1, &moon_map_tex);
    glGenTextures(1, &cloud_map_tex);

    glBindTexture(GL_TEXTURE_2D, earth_map_tex);
    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA, 
        earth_map_img->getWidth(), earth_map_img->getHeight(), 0, 
        GL_RGBA, GL_FLOAT, earth_map_img->getPixels()
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, moon_map_tex);
    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA, 
        moon_map_img->getWidth(), moon_map_img->getHeight(), 0, 
        GL_RGBA, GL_FLOAT, moon_map_img->getPixels()
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, cloud_map_tex);
    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA, 
        cloud_map_img->getWidth(), cloud_map_img->getHeight(), 0, 
        GL_RGBA, GL_FLOAT, cloud_map_img->getPixels()
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glBindTexture(GL_TEXTURE_2D, 0);


    static const size_t EARTH_TEXUNIT = 1;
    static const size_t MOON_TEXUNIT = 2;
    static const size_t CLOUD_TEXUNIT = 3;
    glActiveTexture(GL_TEXTURE0 + EARTH_TEXUNIT);
    glBindTexture(GL_TEXTURE_2D, earth_map_tex);
    glActiveTexture(GL_TEXTURE0 + MOON_TEXUNIT);
    glBindTexture(GL_TEXTURE_2D, moon_map_tex);
    glActiveTexture(GL_TEXTURE0 + CLOUD_TEXUNIT);
    glBindTexture(GL_TEXTURE_2D, cloud_map_tex);
    glActiveTexture(GL_TEXTURE0);


    EarthProgram earthProgram(applicationPath);
    MoonProgram moonProgram(applicationPath);

    glEnable(GL_DEPTH_TEST);

#define ORBIT_CNT 32
    vec3 orbit_axes[ORBIT_CNT];
    float orbit_distances[ORBIT_CNT];
    float orbit_speeds[ORBIT_CNT];
    for(size_t i=0 ; i<ORBIT_CNT ; ++i) {
        orbit_axes[i] = normalize(sphericalRand(1.f));
        orbit_distances[i] = (i%2 ? -1.f : 1.f)*linearRand(2.f, 4.f);
        orbit_speeds[i] = linearRand(0.2f, 1.f);
    }


    //TrackballCamera camera;
    FreeflyCamera camera;
    ivec2 prev_mouse(0,0);
    ivec2 move(0,0);
    bool rotate_camera = false;

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            switch(e.type) {
            case SDL_QUIT: done = true; break;
            case SDL_MOUSEBUTTONDOWN: 
                switch(e.button.button) {
                case SDL_BUTTON_WHEELUP:   camera.moveFront(.2f); break;
                case SDL_BUTTON_WHEELDOWN: camera.moveFront(-.2f); break;
                case SDL_BUTTON_RIGHT:     rotate_camera = true; prev_mouse = ivec2(e.button.x, e.button.y); break;
                }
                break;
            case SDL_MOUSEBUTTONUP: 
                switch(e.button.button) {
                case SDL_BUTTON_RIGHT:     rotate_camera = false; break;
                }
                break;
            case SDL_MOUSEMOTION:
                if(rotate_camera) {
                    ivec2 mouse(e.motion.x, e.motion.y);
                    camera.rotateLeft((mouse.x-prev_mouse.x)*-0.4f);
                    camera.rotateUp((mouse.y-prev_mouse.y)*-0.4f);
                    prev_mouse = mouse;
                }
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                case SDLK_RIGHT: case SDLK_d: move.x += 1; break;
                case SDLK_UP:    case SDLK_z: move.y += 1; break;
                case SDLK_LEFT:  case SDLK_q: move.x -= 1; break;
                case SDLK_DOWN:  case SDLK_s: move.y -= 1; break;
                }
                break;
            case SDL_KEYUP:
                switch(e.key.keysym.sym) {
                case SDLK_RIGHT: case SDLK_d: move.x -= 1; break;
                case SDLK_UP:    case SDLK_z: move.y -= 1; break;
                case SDLK_LEFT:  case SDLK_q: move.x += 1; break;
                case SDLK_DOWN:  case SDLK_s: move.y += 1; break;
                }
                break;
            }
        }


        camera.moveLeft (-move.x*0.1);
        camera.moveFront(move.y*0.1);


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(vao);

#define EARTH_Z 0.f // C'était -6.f

    mat4 ProjMatrix, MVMatrix, NormalMatrix, MVPMatrix;
    ProjMatrix = perspective(radians(70.f), win_w/(float)win_h, .1f, 100.f);
    MVMatrix = camera.getViewMatrix();
    MVMatrix = translate(MVMatrix, vec3(0,0,EARTH_Z));
    MVMatrix = rotate(MVMatrix, windowManager.getTime(), vec3(0,1,0));
    NormalMatrix = transpose(inverse(MVMatrix));
    MVPMatrix = ProjMatrix * MVMatrix;

    earthProgram.m_Program.use();
    glUniform1i(earthProgram.uEarthTexture, EARTH_TEXUNIT);
    glUniform1i(earthProgram.uCloudTexture, CLOUD_TEXUNIT);
    glUniformMatrix4fv(earthProgram.uMVPMatrix,    1, GL_FALSE, value_ptr(MVPMatrix));
    glUniformMatrix4fv(earthProgram.uMVMatrix,     1, GL_FALSE, value_ptr(MVMatrix));
    glUniformMatrix4fv(earthProgram.uNormalMatrix, 1, GL_FALSE, value_ptr(NormalMatrix));

        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

    moonProgram.m_Program.use();
    glUniform1i(moonProgram.uTexture, MOON_TEXUNIT);

        for(size_t i=0 ; i<ORBIT_CNT ; ++i) {

    mat4 MVMatrix = camera.getViewMatrix();
         MVMatrix = translate(MVMatrix, vec3(0,0,EARTH_Z));
         //MVMatrix = rotate(MVMatrix, 8*windowManager.getTime(), sphericalRand(1.f));
         MVMatrix = rotate(MVMatrix, orbit_speeds[i]*windowManager.getTime(), orbit_axes[i]);
         MVMatrix = translate(MVMatrix, 
             orbit_distances[i]*normalize(cross(orbit_axes[i], vec3(0,0,1)))
         );
         MVMatrix = scale(MVMatrix, vec3(.2f,.2f,.2f));
    mat4 MVPMatrix = ProjMatrix * MVMatrix;
    mat4 NormalMatrix = transpose(inverse(MVMatrix));

    glUniformMatrix4fv(moonProgram.uMVPMatrix,    1, GL_FALSE, value_ptr(MVPMatrix));
    glUniformMatrix4fv(moonProgram.uMVMatrix,     1, GL_FALSE, value_ptr(MVMatrix));
    glUniformMatrix4fv(moonProgram.uNormalMatrix, 1, GL_FALSE, value_ptr(NormalMatrix));

    glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        }

        glBindVertexArray(0);
        windowManager.swapBuffers();
    }

    glDeleteTextures(1, &earth_map_tex);
    glDeleteTextures(1, &moon_map_tex);

    return EXIT_SUCCESS;
}

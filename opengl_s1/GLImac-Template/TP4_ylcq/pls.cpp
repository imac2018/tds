// PLS : Préparer La Suite

#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/glm.hpp>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace glimac;
using namespace glm;

struct Vertex2DUV {
    vec2 position, texcoords;
    Vertex2DUV(float x, float y, float u, float v) 
        : position(x,y), texcoords(u,v) {}
};

mat3 translate(vec2 v) {
    return mat3(vec3(1,0,0), vec3(0,1,0), vec3(v.x,v.y,1));
}
mat3 scale(vec2 v) {
    return mat3(vec3(v.x,0,0), vec3(0,v.y,0), vec3(0,0,1));
}
float radians(float deg) {
    return 2.f*M_PI*deg/360.f;
}
mat3 rotate(float deg) {
    float a = radians(deg);
    return mat3(vec3(cos(a),sin(a),0), vec3(-sin(a),cos(a),0), vec3(0,0,1));
}


int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;


    static const Vertex2DUV vdata[] = {
        Vertex2DUV(-1, -1,  0, 1),
        Vertex2DUV( 1, -1,  1, 1),
        Vertex2DUV( 0,  1, .5, 0)
    };

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vdata), vdata, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, position));
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, texcoords));
    }
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    FilePath applicationPath(argv[0]);
    std::string triforcepath 
        = applicationPath.dirPath() 
        + "../../GLImac-Template/assets/textures/triforce.png";
    std::unique_ptr<Image> img = loadImage(triforcepath);
    if(!img) {
        std::cerr << "N'a pas pu charger " << triforcepath << " !" << std::endl;
        return EXIT_FAILURE;
    }
    Program program = loadProgram(
        applicationPath.dirPath() + "shaders/tex2D.vs.glsl",
        applicationPath.dirPath() + "shaders/tex2D.fs.glsl"
    );

    GLuint tex = 0;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA, img->getWidth(), img->getHeight(), 0, 
        GL_RGBA, GL_FLOAT, img->getPixels()
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    program.use();
    GLuint progid = program.getGLId();
    GLint uModelMatrixLoc = glGetUniformLocation(progid, "uModelMatrix");
    GLint uColorLoc = glGetUniformLocation(progid, "uColor");
    GLint uTexture  = glGetUniformLocation(progid, "uTexture");
    float time = 0.f;

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        time += 1.f;

        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(vao);
        for(size_t y=0 ; y<2 ; ++y) for(size_t x=0 ; x<2 ; ++x) {
            mat3 model 
                = rotate(time*.86f)
                * translate(vec2(x-.5f, y-.5f)) 
                * rotate(x ? time : -time)
                * scale(vec2(0.25f, 0.25f))
                ;
            glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, value_ptr(model));
            glUniform3f(uColorLoc, x, y, !x && !y);
            static const size_t TEXUNIT = 0;
            glUniform1i(uTexture, TEXUNIT);
            glActiveTexture(GL_TEXTURE0 + TEXUNIT);
            glBindTexture(GL_TEXTURE_2D, tex);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glBindTexture(GL_TEXTURE_2D, 0);
            glActiveTexture(GL_TEXTURE0);
        }
        glBindVertexArray(0);
        windowManager.swapBuffers();
    }

    glDeleteTextures(1, &tex);

    return EXIT_SUCCESS;
}

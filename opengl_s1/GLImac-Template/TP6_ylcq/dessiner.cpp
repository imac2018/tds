// PLS : Préparer La Suite

#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
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
    /*
    std::string triforcepath 
        = applicationPath.dirPath() 
        + "../../GLImac-Template/assets/textures/triforce.png";
    std::unique_ptr<Image> img = loadImage(triforcepath);
    if(!img) {
        std::cerr << "N'a pas pu charger " << triforcepath << " !" << std::endl;
        return EXIT_FAILURE;
    }
    */
    Program program = loadProgram(
        applicationPath.dirPath() + "shaders/3D.vs.glsl",
        applicationPath.dirPath() + "shaders/normals.fs.glsl"
    );
    /*
    std::ifstream src(applicationPath.dirPath() + "shaders/3D.vs.glsl");
    std::cout << src.rdbuf() << std::endl;
    */

    /*
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
    */

    program.use();
    GLuint progid = program.getGLId();

    logActiveUniforms(progid);

    GLint uMVPMatrixLoc     = glGetUniformLocation(progid, "uMVPMatrix");
    GLint uMVMatrixLoc      = glGetUniformLocation(progid, "uMVMatrix");
    GLint uNormalMatrixLoc  = glGetUniformLocation(progid, "uNormalMatrix");
    assert(uMVPMatrixLoc != -1);
    assert(uNormalMatrixLoc != -1);
    assert(uMVMatrixLoc != -1);

    glEnable(GL_DEPTH_TEST);
    mat4 ProjMatrix, MVMatrix, NormalMatrix, MVPMatrix;
    ProjMatrix = perspective(radians(70.f), win_w/(float)win_h, .1f, 100.f);
    MVMatrix = translate(mat4(), vec3(0,0,-6.f));
    NormalMatrix = transpose(inverse(MVMatrix));

    MVPMatrix = ProjMatrix * MVMatrix;
    glUniformMatrix4fv(uMVPMatrixLoc,    1, GL_FALSE, value_ptr(MVPMatrix));
    glUniformMatrix4fv(uMVMatrixLoc,     1, GL_FALSE, value_ptr(MVMatrix));
    glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, value_ptr(NormalMatrix));

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

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(vao);

    glUniformMatrix4fv(uMVPMatrixLoc,    1, GL_FALSE, value_ptr(MVPMatrix));
    glUniformMatrix4fv(uMVMatrixLoc,     1, GL_FALSE, value_ptr(MVMatrix));
    glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, value_ptr(NormalMatrix));

        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        {
    mat4 MVMatrix = translate(mat4(), vec3(0,0,-6.f));
         MVMatrix = rotate(MVMatrix, 8*windowManager.getTime(), sphericalRand(1.f));
         MVMatrix = translate(MVMatrix, vec3(2,0,0));
         MVMatrix = scale(MVMatrix, vec3(.2f,.2f,.2f));
    mat4 MVPMatrix = ProjMatrix * MVMatrix;
    mat4 NormalMatrix = transpose(inverse(MVMatrix));

    glUniformMatrix4fv(uMVPMatrixLoc,    1, GL_FALSE, value_ptr(MVPMatrix));
    glUniformMatrix4fv(uMVMatrixLoc,     1, GL_FALSE, value_ptr(MVMatrix));
    glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, value_ptr(NormalMatrix));
        }


        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        glBindVertexArray(0);
        windowManager.swapBuffers();
    }

    //glDeleteTextures(1, &tex);

    return EXIT_SUCCESS;
}

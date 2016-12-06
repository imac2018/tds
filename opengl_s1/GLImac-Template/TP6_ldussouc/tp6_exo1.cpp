#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <assert.h>

using namespace glimac;

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


    FilePath applicationPath(argv[0]);
    Program program = loadProgram(
      applicationPath.dirPath() + "shaders/3D.vs.glsl",
      applicationPath.dirPath() + "shaders/normals.fs.glsl"
    );
    program.use();

    GLint locationMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint locationMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint locationNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    // assert(locationMVMatrix != -1 );

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    Sphere sphere(1,32,16);

    GLuint vbo, vao;

    // Gestion du VBO

    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(
      GL_ARRAY_BUFFER,
      sphere.getVertexCount()*sizeof(ShapeVertex),
      sphere.getDataPointer(),
      GL_STATIC_DRAW
    );

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Gestion du VAO

    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(
      VERTEX_ATTR_POSITION,
      3,
      GL_FLOAT,
      GL_FALSE,
      sizeof(ShapeVertex),
      (const GLvoid*)offsetof(ShapeVertex, position)
    );

    const GLuint VERTEX_ATTR_NORMAL = 1;
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glVertexAttribPointer(
      VERTEX_ATTR_NORMAL,
      3,
      GL_FLOAT,
      GL_FALSE,
      sizeof(ShapeVertex),
      (const GLvoid*)offsetof(ShapeVertex, normal)
    );

    const GLuint VERTEX_ATTR_TEXCOORDS = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);
    glVertexAttribPointer(
      VERTEX_ATTR_TEXCOORDS,
      2,
      GL_FLOAT,
      GL_FALSE,
      sizeof(ShapeVertex),
      (const GLvoid*)offsetof(ShapeVertex, texCoords)
    );

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Les matrices
    glm::mat4 ProjMatrix = glm::perspective(
      glm::radians(70.f),
      800.f / 600.f,
      0.1f,
      100.f
    );

    int i;
    glm::mat4 MVMatrix = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -5.0f));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    glm::mat4 MVPMatrix = ProjMatrix * MVMatrix ;

    glEnable(GL_DEPTH_TEST);

    glm::vec3 axesRotation[32];
    for(i = 0; i < 32; i++){
      axesRotation[i] = glm::sphericalRand(1.3f); 
    }

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

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(vao);

        glUniformMatrix4fv(
          locationMVPMatrix,
          1,
          GL_FALSE,
          glm::value_ptr(MVPMatrix)
        );

        glUniformMatrix4fv(
          locationMVMatrix,
          1,
          GL_FALSE,
          glm::value_ptr(MVMatrix)
        );

        glUniformMatrix4fv(
          locationNormalMatrix,
          1,
          GL_FALSE,
          glm::value_ptr(NormalMatrix)
        );

        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
        for(i = 1; i <= 32; i++){
          MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
          MVMatrix = glm::rotate(MVMatrix, windowManager.getTime()*0.2f*i, axesRotation[i]);
          MVMatrix = glm::translate(MVMatrix, glm::vec3(-2, 0, 0));
          MVMatrix = glm::scale(MVMatrix, glm::vec3(0.3f, 0.3f, 0.3f));

          glUniformMatrix4fv(locationMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
          glUniformMatrix4fv(locationNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
          glUniformMatrix4fv(locationMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));

          glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
        }
        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}

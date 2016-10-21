#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <cstddef>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>

using namespace glimac;

struct Vertex2DColor{
  glm::vec2 position;
  glm::vec3 color;

public:
  Vertex2DColor();
  Vertex2DColor(glm::vec2 position, glm::vec3 color) : position(position), color(color) {}
};

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "Ldussouc - GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl",
                                  applicationPath.dirPath() + "shaders/triangle.fs.glsl");
    program.use();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    GLuint vbo, vao;

    // Gestion du VBO

    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    std::vector<Vertex2DColor> vertices; 

    static const float r = 0.5f;
    static const size_t reso = 32;
    vertices.push_back(Vertex2DColor(glm::vec2(0,0), glm::vec3(0,1,0)));
    for(size_t i=0 ; i<reso ; ++i) {
      float theta = 2.f*glm::pi<float>()*(float)i/(float)reso;
      vertices.push_back(Vertex2DColor(glm::vec2(r*glm::cos<float>(theta), r*glm::sin<float>(theta)), glm::vec3(1,0,0)));
    }
    vertices.push_back(Vertex2DColor(glm::vec2(r*1.f, 0), glm::vec3(1,0,0)));
    

    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex2DColor), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Gestion du VAO

    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

      glBindBuffer(GL_ARRAY_BUFFER, vbo);

      const GLuint VERTEX_ATTR_POSITION = 3;
      glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
      glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*)offsetof(Vertex2DColor, position));

      const GLuint VERTEX_ATTR_COLOURS = 8;
      glEnableVertexAttribArray(VERTEX_ATTR_COLOURS);
      glVertexAttribPointer(VERTEX_ATTR_COLOURS, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*)offsetof(Vertex2DColor, color));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

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

        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);

        glDrawArrays(GL_TRIANGLE_FAN, 0, reso+2);

        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}

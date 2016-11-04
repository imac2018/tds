 #include <glimac/SDLWindowManager.hpp>
 #include <GL/glew.h>
 #include <iostream>
 #include <cstddef>
 #include <glimac/Program.hpp>
 #include <glimac/FilePath.hpp>
 #include <glimac/glm.hpp>

 using namespace glimac;

// struct Vertex2DUV{
//   glm::vec2 position;
//   glm::vec2 texture;
// public:
//   Vertex2DUV(glm::vec2 position, glm::vec2 texture) : position(position), texture(texture) {}
// };

// glm::mat3 rotate(float deg){
//   return glm::mat3(glm::vec3(cos(deg), sin(deg),0), glm::vec3(-sin(deg), cos(deg),0), glm::vec3(0,0,1));
// }

// glm::mat3 scale(float sx, float sy){
//   return glm::mat3(glm::vec3(sx,0,0), glm::vec3(0,sy,0), glm::vec3(0,0,1));
// }

 int main(int argc, char** argv) {
//     // Initialize SDL and open a window
//     SDLWindowManager windowManager(800, 600, "Ldussouc - GLImac");

//     // Initialize glew for OpenGL3+ support
//     GLenum glewInitError = glewInit();
//     if(GLEW_OK != glewInitError) {
//         std::cerr << glewGetErrorString(glewInitError) << std::endl;
//         return EXIT_FAILURE;
//     }

//     std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
//     std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

//     FilePath applicationPath(argv[0]);
//     Program program = loadProgram(applicationPath.dirPath() + "shaders/tex2D.vs.glsl",
//                                   applicationPath.dirPath() + "shaders/tex2D.fs.glsl");
//     program.use();

//     /*********************************
//      * HERE SHOULD COME THE INITIALIZATION CODE
//      *********************************/

//     GLint location = glGetUniformLocation(program.getGLId(), "uModelMatrix");
//     GLint locationTexture = glGetUniformLocation(program.getGLId(), "uTexture");

//     GLuint vbo, vao, texture;

//     // Gestion du VBO

//     glGenBuffers(1, &vbo);

//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     Vertex2DUV vertices[] = {
//       Vertex2DUV( glm::vec2(-1, -1), glm::vec2(0, 1) ), // Sommet 1
//       Vertex2DUV( glm::vec2(1, -1), glm::vec2(1, 1) ), // Sommet 2
//       Vertex2DUV( glm::vec2(0, 1), glm::vec2(0.5, 0) ) // Sommet 3
//     };

//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     // Gestion du VAO

//     glGenVertexArrays(1, &vao);

//     glBindVertexArray(vao);

//       glBindBuffer(GL_ARRAY_BUFFER, vbo);

//       const GLuint VERTEX_ATTR_POSITION = 0;
//       glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
//       glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, position));

//       const GLuint VERTEX_ATTR_COLOURS = 1;
//       glEnableVertexAttribArray(VERTEX_ATTR_COLOURS);
//       glVertexAttribPointer(VERTEX_ATTR_COLOURS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, texture));


//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);

//    // Gestion de la texture

//     loadimage("/home/6im2/ldussouc/Documents/c++/tds/opengl_s1/GLImac-Template/assets/textures/triforce.png");

//     glGenTextures(1, &texture);
//     glBindTextures(GL_TEXTURE_2D, texture);

//     glTexImage2D( 	pImage,
//                     0,
//                     GL_RGBA,
//                     pImage->getWidth(),
//                     pImage->getHeight(),
//                     0,
//                     GL_RGBA,
//                     GL_FLOAT,
//                     pImage->getPixels());

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     glBindTextures(GL_TEXTURE_2D, 0);
//     float tack = 0;
//     float tack2 = 0;

//     // Application loop:
//     bool done = false;
//     while(!done) {
//         // Event loop:
//         SDL_Event e;
//         while(windowManager.pollEvent(e)) {
//             if(e.type == SDL_QUIT) {
//                 done = true; // Leave the loop after this iteration
//             }
//         }

//         /*********************************
//          * HERE SHOULD COME THE RENDERING CODE
//          *********************************/
//         tack+=0.045f;
//         tack2+=0.035f;
//         glClear(GL_COLOR_BUFFER_BIT);

//         glBindVertexArray(vao);

//         glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(scale(0.5f,0.5f)*rotate(tack)));
//         glUniform1i(locationTexture, 0);
//         glDrawArrays(GL_TRIANGLES, 0, 3);

//         glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(scale(0.5f,0.5f)*rotate(tack2)));
//         glDrawArrays(GL_TRIANGLES, 0, 3);
//         glBindVertexArray(0);

//         // Update the display
//         windowManager.swapBuffers();
//     }

//     glDeleteBuffers(1, &vbo);
//     glDeleteVertexArrays(1, &vao);
//     glDeleteTextures(1, &texture);

     return EXIT_SUCCESS;
 }

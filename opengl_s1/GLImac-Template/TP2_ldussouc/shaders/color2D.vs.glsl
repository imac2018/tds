#version 330 core

layout(location = 0) in vec2 aVertexPosition;

out vec3 vFragColor;
out vec2 vFragPosition;

void main() {
  vFragColor = vec3(aVertexPosition, 1);
  vFragPosition = aVertexPosition;
  gl_Position = vec4(aVertexPosition, 0, 1);
};


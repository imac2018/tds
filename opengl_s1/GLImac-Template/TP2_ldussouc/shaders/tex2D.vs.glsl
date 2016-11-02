#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexColor;

uniform mat3 uModelMatrix;

out vec3 vFragColor;

void main() {
  vFragColor = vec3(aVertexColor,0);
  gl_Position = vec4(uModelMatrix*vec3(aVertexPosition,1), 1);
};

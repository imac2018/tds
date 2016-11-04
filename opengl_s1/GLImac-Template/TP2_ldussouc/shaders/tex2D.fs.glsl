#version 330 core

in vec3 vFragPosition;
in vec3 vFragColor;

uniform vec3 uTexture;

out vec4 fFragColor;

void main() {
  fFragColor = texture(uTexture, vFragColor);
};

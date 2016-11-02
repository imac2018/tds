#version 330

uniform mat3 uModelMatrix;

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexTexCoords;

out vec2 vTexCoords;
out vec2 vPos;

void main() {
    vTexCoords  = aVertexTexCoords;
    vPos        = aVertexPosition;
    vec3 rpos   = uModelMatrix * vec3(aVertexPosition, 1);
    gl_Position = vec4(rpos, 1);
}

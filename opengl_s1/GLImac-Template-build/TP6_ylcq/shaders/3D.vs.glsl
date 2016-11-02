#version 330

layout(location=0) in vec3 aPosition;
layout(location=1) in vec3 aNormal;
layout(location=2) in vec2 aTexCoords;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

out vec3 vPosition;
out vec3 vNormal;
out vec2 vTexCoords;

void main() {
    vTexCoords  = aTexCoords;
    vPosition   = vec4(uMVMatrix * vec4(aPosition, 1)).xyz;
    vNormal     = vec4(uNormalMatrix * vec4(aNormal, 0)).xyz;
    gl_Position = uMVPMatrix * vec4(aPosition, 1);
}

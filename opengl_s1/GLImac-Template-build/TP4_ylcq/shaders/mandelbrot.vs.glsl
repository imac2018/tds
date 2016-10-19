#version 330

layout(location = 0) in vec2 aVertexPosition;

out vec3 vColor;
out vec2 vPos;

void main() {
    vColor = vec3(aVertexPosition, 1);
    vPos = aVertexPosition;
    gl_Position = vec4(aVertexPosition, 0, 1);
}

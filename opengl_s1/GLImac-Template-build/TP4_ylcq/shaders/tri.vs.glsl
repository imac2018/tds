#version 330

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vColor;
out vec2 vPos;

mat3 translate(vec2 v) {
    return mat3(vec3(1,0,0), vec3(0,1,0), vec3(v.x,v.y,1));
}
mat3 scale(vec2 v) {
    return mat3(vec3(v.x,0,0), vec3(0,v.y,0), vec3(0,0,1));
}
mat3 rotate(float deg) {
    float a = radians(deg);
    return mat3(vec3(cos(a),sin(a),0), vec3(-sin(a),cos(a),0), vec3(0,0,1));
}

void main() {
    vColor = aVertexColor;
    vPos = aVertexPosition;
    gl_Position = vec4(rotate(180)*vec3(aVertexPosition,1), 1);
}

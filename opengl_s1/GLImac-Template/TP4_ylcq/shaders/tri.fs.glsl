#version 330

in vec3 vColor;
in vec2 vPos;

out vec3 fFragColor;

float att(float alpha, float beta, float dist) {
    return alpha*exp(-beta*dist*dist);
}

void main() {
    // float a = att(2, 20, distance(vec2(0,0), vPos));
    // fFragColor = vec3(a)*vColor;
    vec2 P = vPos;
    //fFragColor = vColor * length(fract(5.0 * P));
    //fFragColor = vColor * length(abs(fract(5.0 * P) * 2.0 - 1.0));
    //fFragColor = vColor * mod(floor(10.0 * P.x) + floor(10.0 * P.y), 2.0);
    //fFragColor = vColor * smoothstep(0.3, 0.32, length(fract(5.0 * P) - 0.5));
    fFragColor = vColor * smoothstep(0.4, 0.5, max(abs(fract(8.0 * P.x - 0.5 * mod(floor(8.0 * P.y), 2.0)) - 0.5), abs(fract(8.0 * P.y) - 0.5)));
}

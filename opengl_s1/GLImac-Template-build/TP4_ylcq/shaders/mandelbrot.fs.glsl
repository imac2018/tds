#version 330

in vec3 vColor;
in vec2 vPos;

out vec3 fFragColor;

vec2 complexSqr(vec2 z) {
    //   (a+ib)²
    // = a² + 2aib + (ib)²
    // = a² + 2aib - b²
    // D'où que
    // Re = a²-b²
    // Im = 2ab
    float a = z.x;
    float b = z.y;
    return vec2(a*a-b*b, 2*a*b);
}

void main() {
    const int N = 42;
    vec2 z_prev = vPos;
    vec2 zn = z_prev;
    for(int n=0 ; n<N ; ++n) {
        if(length(zn) > 2) {
            fFragColor = vec3(float(n)/N, float(n/3)/N, 0);
            return;
        }
        z_prev = zn;
        zn = complexSqr(z_prev) + vPos;
    }
    fFragColor = vec3(0);
}

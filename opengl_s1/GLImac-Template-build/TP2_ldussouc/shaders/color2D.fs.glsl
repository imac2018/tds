#version 330 core

in vec2 vFragPosition;
in vec3 vFragColor;

out vec3 fFragColor;

vec2 complexSqr(vec2 z) {
     return vec2(z.x*z.x - z.y*z.y, 2*z.x*z.y);
}

void main() {
    int prec = 60;
    vec2 z_minus = vFragPosition; 
    vec2 z = z_minus;

    for(int n=0 ; n<prec ; n++) {
        if(length(z) > 2) {
            fFragColor = vec3(float(n)/prec);
            return;
        }
        else{
           z_minus = z;
           z = complexSqr(z) + vFragPosition;
        }
    }
    fFragColor = vec3(0);
};

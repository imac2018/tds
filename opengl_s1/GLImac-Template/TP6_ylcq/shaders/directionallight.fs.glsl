#version 330 

uniform mat4 uMVMatrix;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightDir_vs; //vs = view space
uniform vec3 uLightIntensity;

vec3 blinnPhong(vec3 normal, vec3 vPosition_vs) {
    vec3 Li = uLightIntensity;
    vec3 N  = normalize(normal);
    vec3 wi = normalize(uLightDir_vs);
    vec3 wo = normalize(-vPosition_vs);
    vec3 halfVector = normalize((wo+wi)/2.f);
    return max(uKd, uKd+Li*(uKd*dot(wi,N) + uKs*pow(dot(halfVector,N), uShininess)));
}

in vec3 vPosition;
in vec3 vNormal;
in vec2 vTexCoords;

out vec3 fFragColor;

void main() {
    // Ce truc sert à faire croire au driver que uMVMatrix est utilisée ._.
    // Sinon sa location renvoie -1.
    vec3 fake = normalize(vNormal)*vPosition*vec3(0.000001);
    // vPosition est déjà dans le view space : voir mon 3D.vs.glsl.
    vec3 vNormal_vs = vec4(uMVMatrix*vec4(vNormal, 0)).xyz;
    fFragColor = blinnPhong(vNormal, vPosition) + fake;
}

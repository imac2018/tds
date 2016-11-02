#version 330 

in vec3 vPosition;
in vec3 vNormal;
in vec2 vTexCoords;

out vec3 fFragColor;

void main() {
    // Ce truc sert à faire croire au driver que uMVMatrix est utilisée ._.
    // Sinon sa location renvoie -1.
    vec3 fake = vPosition*vec3(0.000001);
    fFragColor = normalize(vNormal) + fake;
}

#version 330 

uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

in vec3 vPosition;
in vec3 vNormal;
in vec2 vTexCoords;

out vec3 fFragColor;

void main() {
    // Ce truc sert à faire croire au driver que uMVMatrix est utilisée ._.
    // Sinon sa location renvoie -1.
    vec3 fake = normalize(vNormal)*vPosition*vec3(0.000001);
    //fFragColor = normalize(vNormal) + fake;
    fFragColor = texture2D(uEarthTexture, vTexCoords).rgb 
               + texture2D(uCloudTexture, vTexCoords).rgb 
               + fake;
}

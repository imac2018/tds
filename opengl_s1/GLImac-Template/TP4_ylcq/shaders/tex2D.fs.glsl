#version 330
uniform vec3 uColor;
uniform sampler2D uTexture;
in  vec2 vTexCoords;
out vec3 fFragColor;
void main() {
    //fFragColor = uColor;
    fFragColor = texture(uTexture, vTexCoords).rgb;
}

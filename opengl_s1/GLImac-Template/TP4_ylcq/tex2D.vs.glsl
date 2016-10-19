#version 330

in vec2 aPosition;
in vec2 aTexCoord;

out vec2 vTexCoord;

int main() {
    gl_Position = aPosition;
    vTexCoord = aTexCoord;
}

#version 330 core

in vec3 vFragColor;
in vec3 vFragPosition;

out vec3 fFragColor;

float attenuation(float a, float b, float distance){
  return a * exp(-b * pow(distance,2) );
}

void main() {
  float dist = distance(vec3(0), vFragPosition);
  fFragColor = vFragColor * attenuation(0.5, 50, dist);
};



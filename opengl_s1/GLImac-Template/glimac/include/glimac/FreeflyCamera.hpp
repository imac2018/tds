#pragma once

#include "glm.hpp"
#include <iostream>
#include <cmath>

namespace glimac {

class FreeflyCamera {
    glm::vec3 m_Position;
    float m_fPhi, m_fTheta;
    glm::vec3 m_FrontVector, m_LeftVector, m_UpVector;
    // La fonction dans l'énoncé a un problème majeur :
    // Le leftVector devient facilement très similaire au front vector,
    // de telle sorte que se déplacer latéralement devient de plus
    // en plus équivalent à avancer et reculer.
    // J'ai donc changé le calcul de UpVector et LeftVector.
    void computeDirectionVectors() {
        m_FrontVector = glm::vec3(
            cosf(m_fTheta)*sinf(m_fPhi),
            sinf(m_fTheta),
            cosf(m_fTheta)*cosf(m_fPhi)
        );
        m_UpVector = glm::vec3(0,1,0);
        m_LeftVector = glm::cross(m_UpVector, m_FrontVector);
    }
public:
    FreeflyCamera() : m_Position(0,0,0), m_fPhi(M_PI), m_fTheta(0) {
        computeDirectionVectors();
    }
    void moveLeft(float t)  { m_Position += t*m_LeftVector;  }
    void moveFront(float t) { m_Position += t*m_FrontVector; }
    void rotateLeft(float t){ 
        m_fPhi   += glm::radians(t); 
        computeDirectionVectors();
    }
    void rotateUp(float t)  { 
        m_fTheta += glm::radians(t); 
        computeDirectionVectors();
    }
    glm::mat4 getViewMatrix() {
        return glm::lookAt(m_Position, m_Position+m_FrontVector, m_UpVector);
    }
};

}

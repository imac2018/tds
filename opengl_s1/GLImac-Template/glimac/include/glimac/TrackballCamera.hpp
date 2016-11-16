#pragma once

#include "glm.hpp"

namespace glimac {

class TrackballCamera {
    float m_fDistance, m_fAngleX, m_fAngleY;
public:
    TrackballCamera() : m_fDistance(5), m_fAngleX(0), m_fAngleY(0) {}
    ~TrackballCamera() {}
    void moveFront(float delta)    { m_fDistance -= delta; }
    void rotateLeft(float degrees) { m_fAngleY += degrees; }
    void rotateUp(float degrees)   { m_fAngleX += degrees; }
    glm::mat4 getViewMatrix() const {
        return glm::translate(glm::mat4(), glm::vec3(0,0,-m_fDistance))
             * glm::rotate(glm::mat4(), glm::radians(m_fAngleX), glm::vec3(1,0,0))
             * glm::rotate(glm::mat4(), glm::radians(m_fAngleY), glm::vec3(0,1,0));
    }
};

}

#ifndef SHOOTER2DSFML_VECTORMATH_H
#define SHOOTER2DSFML_VECTORMATH_H

#include <SFML/System/Vector2.hpp>
#include <cmath>

static const float pi = 3.14159265359f;

inline float degreeToRadian(float angle) {
    return angle * pi / 180.0f;
}

inline sf::Vector2f radianToVector(float angle) {
    return {cos(angle), sin(angle)};
}

inline sf::Vector2f degreeToVector(float angle) {
    angle = degreeToRadian(angle);
    return radianToVector(angle);
}

inline sf::Vector2f normalizeVector(sf::Vector2f vec) {
    float length = vec.x*vec.x + vec.y*vec.y;
    if (length == 0.f)
        return vec;
    length = sqrt(length);
    vec.x = vec.x / length;
    vec.y = vec.y / length;
    return vec;
}


#endif //SHOOTER2DSFML_VECTORMATH_H

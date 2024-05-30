// Copyright 2024 Nedelin Dmitry
#define _USE_MATH_DEFINES

#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

double Circle::GetArea() const {
    return area;
}

double Circle::GetRadius() const {
    return radius;
}

double Circle::GetFerence() const {
    return ference;
}

void Circle::SetArea(double _area) {
    if (_area < 0) {
        throw std::invalid_argument("Invalid Value - Area");
    }
    area = _area;
    radius = std::sqrt(area / M_PI);
    ference = 2 * radius * M_PI;
}


void Circle::SetRadius(double _radius) {
    if (_radius < 0) {
        throw std::invalid_argument("Invalid Value - Radius");
    }
    radius = _radius;
    ference = radius * 2 * M_PI;
    area = radius * M_PI * radius;
}


void Circle::SetFerence(double _ference) {
    if (_ference < 0) {
        throw std::invalid_argument("Invalid Value - Ference");
    }
    ference = _ference;
    radius = ference / (2 * M_PI);
    area = radius * M_PI * radius;
}

Circle::Circle(double radius) {
    SetRadius(radius);
}

// Copyright 2024 Nedelin Dmitry

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
 private:
    static const double PI;
    double radius;
    double ference;
    double area;

 public:
    explicit Circle(double raduisValue = 0);

    double GetArea() const;
    double GetRadius() const;
    double GetFerence() const;

    void SetArea(double value);
    void SetRadius(double value);
    void SetFerence(double value);
};

#endif  // INCLUDE_CIRCLE_H_

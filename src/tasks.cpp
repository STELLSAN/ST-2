// Copyright 2024 Nedelin Dmitry
#include"circle.h"
#include"tasks.h"

double TaskEarthAndRope(double earthRad, double ropeLenght) {
    Circle circle(earthRad);
    Circle tmp_circle;
    tmp_circle.SetFerence(circle.GetFerence() + ropeLenght);

    return tmp_circle.GetRadius() - circle.GetRadius();
}

double TaskSwimmingPool(
    double poolrad, double areaWidth,
    double areaPricePerSqM, double ferencePricePerM) {
    Circle Pool(poolrad);
    Circle poolWithArea(poolrad + areaWidth);
    double Area = poolWithArea.GetArea() - Pool.GetArea();

    return Area * areaPricePerSqM + poolWithArea.GetFerence()
        * ferencePricePerM;
}

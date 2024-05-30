// Copyright 2024 Nedelin Dmitry
#define _USE_MATH_DEFINES

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

//  CIRCLE TEST

TEST(circle, checkArea) {
    Circle tmp_cirle(9);
    ASSERT_DOUBLE_EQ(9 * 9 * M_PI, tmp_cirle.GetArea());
}

TEST(circle, checkRadius) {
    Circle tmp_cirle(2);
    ASSERT_DOUBLE_EQ(2, tmp_cirle.GetRadius());
}

TEST(circle, checkFerence) {
    Circle tmp_cirle(5);
    ASSERT_DOUBLE_EQ(5 * 2 * M_PI, tmp_cirle.GetFerence());
}

TEST(circle, setArea) {
    double area = 7;
    Circle tmp_cirle;
    tmp_cirle.SetArea(area);
    ASSERT_DOUBLE_EQ(area, tmp_cirle.GetArea());
}

TEST(circle, setRadius) {
    double rad = 5.0;
    Circle tmp_cirle;
    tmp_cirle.SetRadius(rad);
    ASSERT_DOUBLE_EQ(rad, tmp_cirle.GetRadius());
}

TEST(circle, setFerence) {
    double fer = 3;
    Circle tmp_cirle;
    tmp_cirle.SetFerence(fer);
    ASSERT_DOUBLE_EQ(fer, tmp_cirle.GetFerence());
}

TEST(circle, checkCreateRad) {
    ASSERT_ANY_THROW(Circle(-15));
}

TEST(circle, checkSetNegativeRad) {
    Circle tmp_cirle;
    ASSERT_ANY_THROW(tmp_cirle.SetRadius(-10));
}

TEST(circle, checkSetNegativeFerence) {
    Circle tmp_cirle;
    ASSERT_ANY_THROW(tmp_cirle.SetFerence(-10));
}

TEST(circle, checkSetNegativeArea) {
    Circle tmp_cirle;
    ASSERT_ANY_THROW(tmp_cirle.SetArea(-10));
}

TEST(circle, checkSetAreaAndRadius) {
    double area = 3;
    Circle tmp_cirle;
    tmp_cirle.SetArea(area);
    ASSERT_DOUBLE_EQ(sqrt(area / M_PI), tmp_cirle.GetRadius());
}

TEST(circle, checkSetRadiusAndFerecne) {
    double rad = 3.0;
    Circle tmp_cirle;
    tmp_cirle.SetRadius(rad);
    ASSERT_DOUBLE_EQ(rad * 2 * M_PI, tmp_cirle.GetFerence());
}

TEST(circle, checkSetRadiusAndArea) {
    double rad = 3.0;
    Circle tmp_cirle;
    tmp_cirle.SetRadius(rad);
    ASSERT_DOUBLE_EQ(rad * rad * M_PI, tmp_cirle.GetArea());
}

TEST(circle, checkSetAreaAndFerecne) {
    double area = 3;
    Circle tmp_cirle;
    tmp_cirle.SetArea(area);
    ASSERT_DOUBLE_EQ(sqrt(area / M_PI) * 2 * M_PI, tmp_cirle.GetFerence());
}

TEST(circle, checkSetFerenceAndRadius) {
    double ference = 3;
    Circle tmp_cirle;
    tmp_cirle.SetFerence(ference);
    ASSERT_DOUBLE_EQ(ference / 2 / M_PI, tmp_cirle.GetRadius());
}

TEST(circle, checkFerenceAndAarea) {
    double ference = 3;
    Circle tmp_cirle;
    tmp_cirle.SetFerence(ference);
    ASSERT_DOUBLE_EQ(pow(ference / 2 / M_PI, 2) * M_PI, tmp_cirle.GetArea());
}

TEST(circle, eqCirclesFerence) {
    Circle tmp_cirle_1(3), tmp_cirle_2(3);
    ASSERT_DOUBLE_EQ(tmp_cirle_1.GetFerence(), tmp_cirle_2.GetFerence());
}

TEST(circle, eqCirclesArea) {
    Circle tmp_cirle_1(3), tmp_cirle_2(3);
    ASSERT_DOUBLE_EQ(tmp_cirle_1.GetArea(), tmp_cirle_2.GetArea());
}

//   TASK TEST
TEST(tasks, earthAndRopeTT) {
    double earthRadM = 6378.1 * 1e3;
    double earthL = earthRadM * M_PI * 2;
    double actualResM = (earthL + 1)
        / 2 / M_PI - earthRadM;

    ASSERT_DOUBLE_EQ(TaskEarthAndRope(earthRadM, 1)
        , actualResM);
}

TEST(tasks, swimmingPoolTT) {
    double poolRad = 3;
    double areaWidth = 1;

    double mFerencePrice = 2000;
    double sqMAreaPrice = 1000;

    double ferencePrice = 2 * M_PI * (poolRad + areaWidth)
        * mFerencePrice;
    double areaPrice = M_PI * areaWidth * (areaWidth + 2 * poolRad)
        * sqMAreaPrice;

    ASSERT_DOUBLE_EQ(TaskSwimmingPool(poolRad, areaWidth,
        sqMAreaPrice, mFerencePrice),
        ferencePrice + areaPrice);
}

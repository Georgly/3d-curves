#pragma once
#include <memory>
#include <random>
#include "curve.hpp"


class CurveGenerator
{
public:
    std::shared_ptr<Curve> GenerateCurve();

private:
    std::shared_ptr<Curve> GenerateCircle();
    std::shared_ptr<Curve> GenerateEllipse();
    std::shared_ptr<Curve> GenerateHelix();

    enum Curves
    {
        circle,
        ellipse,
        helix
    };
    std::random_device rd_;
    std::mt19937 gen_{rd_()};
    std::uniform_int_distribution<int> curve_rnd_{circle, helix};
    std::uniform_real_distribution<float> curve_param_rnd_{0.5, 3.5};
    
};

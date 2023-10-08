#pragma once
#include <memory>
#include <random>
#include "curve.hpp"


class CurveGenerator
{
private:
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
    
    std::shared_ptr<Curve> GenerateCircle()
    {
        return std::make_shared<Circle>(curve_param_rnd_(gen_));
    }

    std::shared_ptr<Curve> GenerateEllipse()
    {
        return std::make_shared<Ellipse>(curve_param_rnd_(gen_), curve_param_rnd_(gen_));
    }

    std::shared_ptr<Curve> GenerateHelix()
    {
        return std::make_shared<Helix>(curve_param_rnd_(gen_), curve_param_rnd_(gen_));
    }

public:
    std::shared_ptr<Curve> GenerateCurve()
    {
        switch (curve_rnd_(gen_))
        {
            case circle:
            {
                return GenerateCircle();
            }
            case ellipse:
            {
                return GenerateEllipse();
            }
            case helix:
            {
                return GenerateHelix();
            }
            default:
                return GenerateCircle();
        }
    }

};

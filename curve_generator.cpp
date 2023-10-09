#include "curve_generator.h"

std::shared_ptr<Curve> CurveGenerator::GenerateCircle()
{
    return std::make_shared<Circle>(curve_param_rnd_(gen_));
}

std::shared_ptr<Curve> CurveGenerator::GenerateEllipse()
{
    return std::make_shared<Ellipse>(curve_param_rnd_(gen_), curve_param_rnd_(gen_));
}

std::shared_ptr<Curve> CurveGenerator::GenerateHelix()
{
    return std::make_shared<Helix>(curve_param_rnd_(gen_), curve_param_rnd_(gen_));
}

std::shared_ptr<Curve> CurveGenerator::GenerateCurve()
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
        {
            return GenerateCircle();
        }
    }
}

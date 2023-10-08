#pragma once

struct vector3d
{
    float e[3];
};

class Curve
{
public:
    virtual vector3d getPointAt(float p) const = 0;
    virtual vector3d getDerivativeAt(float p) const = 0;
    virtual vector3d getRadius() const = 0;
};

#pragma once

#include <cmath>

#define PI 3.14

struct vector3d
{
    vector3d() : e{0,0,0} {}
    vector3d(float x, float y, float z = 0) : e{x, y, z} {}
    float e[3];
};

using point3d = vector3d;

class Curve
{
public:
    virtual point3d GetPointAt(float p) const = 0;
    virtual vector3d GetDerivativeAt(float p) const = 0;
};

/*
*   Parametric equation of a circle: x=rcost; y=rsint;0<=t<2π
*/
class Circle : Curve
{
public:
    explicit Circle(float radius)
    {
        radius_ = fabsf(radius);
    }

    point3d GetPointAt(float p) const 
    {
        point3d result = {radius_*cosf(p),radius_*sinf(p),0};
        return result;
    }
    vector3d GetDerivativeAt(float p) const 
    {
        vector3d result = {radius_*sinf(p)*(-1),radius_*cosf(p),0};
        return result;
    }
    float GetRadius() const 
    {
        return radius_;
    }

private:
    float radius_;
};

/*
*   Parametric equation of an ellipse : x=a*cost; y=b*sint;0<=t<2π
*/
class Ellipse : Curve
{
public:
    explicit Ellipse(float xRadius, float yRadius)
    {
        xRadius_ = fabsf(xRadius);
        yRadius_ = fabsf(yRadius);
    }

    point3d GetPointAt(float p) const 
    {
        point3d result = {xRadius_*cosf(p),yRadius_*sinf(p),0};
        return result;
    }
    vector3d GetDerivativeAt(float p) const 
    {
        vector3d result = {xRadius_*sinf(p)*(-1),yRadius_*cosf(p),0};
        return result;
    }
    float GetYRadius() const 
    {
        return yRadius_;
    }
    float GetXRadius() const 
    {
        return xRadius_;
    }

private:
    float xRadius_;
    float yRadius_;
};

/*
*   Parametric equation of a helix: x=rcost; y=rsint; z=st;0<=t<2π
*/
class Helix : Curve
{
public:
    explicit Helix(float radius, float step)
    {
        radius_ = fabsf(radius);
        step_ = fabsf(step);
    }

    point3d GetPointAt(float p) const 
    {
        point3d result = {radius_*cosf(p),radius_*sinf(p),step_*p};
        return result;
    }
    vector3d GetDerivativeAt(float p) const 
    {
        vector3d result = {radius_*sinf(p)*(-1),radius_*cosf(p),step_};
        return result;
    }
    float GetRadius() const 
    {
        return radius_;
    }

private:
    float radius_;
    float step_;
};

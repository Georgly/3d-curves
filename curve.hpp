#pragma once

#include <cmath>

class Vector3d
{
public:
    explicit Vector3d(float x, float y, float z = 0) : e{x, y, z} {}
    float e[3];
};

using Point3d = Vector3d;

class Curve
{
public:
    virtual Point3d GetPointAt(float p) const = 0;
    virtual Vector3d GetDerivativeAt(float p) const = 0;
    virtual ~Curve() = default;
};

class Circle : public Curve
{
public:
    explicit Circle(float radius) : radius_(fabsf(radius)) { }

    Point3d GetPointAt(float p) const 
    {
        return Point3d(radius_*cosf(p),radius_*sinf(p));
    }
    Vector3d GetDerivativeAt(float p) const 
    {
        return Vector3d(radius_*sinf(p)*(-1),radius_*cosf(p));
    }
    float GetRadius() const 
    {
        return radius_;
    }

private:
    float radius_;
};

class Ellipse : public Curve
{
public:
    explicit Ellipse(float xRadius, float yRadius) 
        : xRadius_(fabsf(xRadius)), yRadius_(fabsf(yRadius)) { }

    Point3d GetPointAt(float p) const 
    {
        return Point3d(xRadius_*cosf(p),yRadius_*sinf(p),0);
    }
    Vector3d GetDerivativeAt(float p) const 
    {
        return Vector3d(xRadius_*sinf(p)*(-1),yRadius_*cosf(p),0);
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

class Helix : public Curve
{
public:
    explicit Helix(float radius, float step) 
        : radius_(fabsf(radius)), step_(fabsf(step)) { }

    Point3d GetPointAt(float p) const 
    {
        return Point3d(radius_*cosf(p),radius_*sinf(p),step_*p);
    }
    Vector3d GetDerivativeAt(float p) const 
    {
        return Vector3d(radius_*sinf(p)*(-1),radius_*cosf(p),step_);
    }
    float GetRadius() const 
    {
        return radius_;
    }
    float GetStep() const 
    {
        return step_;
    }

private:
    float radius_;
    float step_;
};

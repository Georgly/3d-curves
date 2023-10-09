#include <iostream>
#include <typeinfo>

#include "utils.h"
#include "curve_generator.h"

using namespace std;

ostream& operator<<(std::ostream& out, const Vector3d& v)
{
    return out << "{" << v.e[0] << "; " << v.e[1] << "; " << v.e[2] << "}";
}

void PopulateVectorWithCurves(vector<shared_ptr<Curve>> & curves, size_t n)
{
    CurveGenerator g;
    for (size_t i = 0; i != n; i++)
    {
        curves.push_back(g.GenerateCurve());
    }
}

/*
*   Populate a second vector with only circles from the first vector
*/
void PopulateVectorWithCircles(const vector<shared_ptr<Curve>> & curves, 
                               vector<shared_ptr<Circle>> & circles)
{
    for (auto curve : curves)
    {
        if(typeid(*curve) == typeid(Circle))
            circles.push_back(dynamic_pointer_cast<Circle>(curve));
    }
}

void PrintCurves(const vector<shared_ptr<Curve>> & curves, float param)
{
    cout << "Coordinates of points and derivatives of all curves in the container at t=" << param << endl;
    for (auto curve : curves)
    {
        cout << "point: " << curve->GetPointAt(param) 
            << "; derivative: " << curve->GetDerivativeAt(param) << endl;
    }
}

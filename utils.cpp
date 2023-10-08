#include <iostream>
#include <vector>
#include <memory>
#include "curve.hpp"

using namespace std;

ostream& operator<<(std::ostream& out, const Vector3d& v)
{
    return out << "{" << v.e[0] << "; " << v.e[1] << "; " << v.e[2] << "}";
}

void populateContainerWithCurves(vector<shared_ptr<Curve>> & curves)
{
    curves.push_back(make_shared<Circle>(1.));
    curves.push_back(make_shared<Ellipse>(1., 0.5));
    curves.push_back(make_shared<Helix>(1., 1.));
}

void printCurves(const vector<shared_ptr<Curve>> & curves, float param)
{
    cout << "Coordinates of points and derivatives of all curves in the container at t=" << param << endl;
    for (auto curve : curves)
    {
        cout << "point: " << curve->GetPointAt(param) 
            << "; derivative: " << curve->GetDerivativeAt(param) << endl;
    }
}

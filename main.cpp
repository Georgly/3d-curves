#include <vector>
#include <memory>
#include <algorithm>
#include "curve.hpp"

using namespace std;

void populateVectorWithCurves(vector<shared_ptr<Curve>> & curves);
void printCurves(const std::vector<shared_ptr<Curve>> & curves, float param);
void populateVectorWithCircles(const vector<shared_ptr<Curve>> & curves, 
                                  vector<shared_ptr<Circle>> & circles);

int main()
{
    vector<shared_ptr<Curve>> curves;
    vector<shared_ptr<Circle>> circles;
    float param = M_PI/4.0;

    populateVectorWithCurves(curves);
    printCurves(curves, param);

    populateVectorWithCircles(curves, circles);
    sort(circles.begin(), 
         circles.end(), 
         [](shared_ptr<Circle> l, shared_ptr<Circle> r)
         {
             return l->GetRadius() < r->GetRadius();
         });

    float radiiSum = 0;
    for (auto circle : circles)
        radiiSum += circle->GetRadius();

    return 0;
}

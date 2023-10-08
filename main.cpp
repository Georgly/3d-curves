#include <vector>
#include <memory>
#include <algorithm>

#include "curve.hpp"
#include "utils.hpp"

using namespace std;

int main()
{
    vector<shared_ptr<Curve>> curves;
    vector<shared_ptr<Circle>> circles;
    size_t n = 10;
    float param = M_PI/4.0;

    PopulateVectorWithCurves(curves, n);
    PrintCurves(curves, param);

    PopulateVectorWithCircles(curves, circles);
    sort(circles.begin(), 
         circles.end(), 
         [](shared_ptr<Circle> l, shared_ptr<Circle> r)
         {
             return l->GetRadius() < r->GetRadius();
         });

    float radii_sum = 0;
    for (auto circle : circles)
        radii_sum += circle->GetRadius();

    return 0;
}

#include <vector>
#include <memory>
#include "curve.hpp"

using namespace std;

void populateContainerWithCurves(vector<shared_ptr<Curve>> & curves);
void printCurves(const std::vector<shared_ptr<Curve>> & curves, float param);

int main()
{
    vector<shared_ptr<Curve>> curves;
    float param = M_PI/4.0;
    populateContainerWithCurves(curves);
    printCurves(curves, param);
    return 0;
}

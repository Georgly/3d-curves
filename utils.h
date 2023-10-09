#pragma once

#include <vector>
#include <memory>

#include "curve.hpp"


void PopulateVectorWithCurves(std::vector<std::shared_ptr<Curve>> & curves, size_t n);
void PrintCurves(const std::vector<std::shared_ptr<Curve>> & curves, float param);
void PopulateVectorWithCircles(const std::vector<std::shared_ptr<Curve>> & curves,
                               std::vector<std::shared_ptr<Circle>> & circles);

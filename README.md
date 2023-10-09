# 3D Curves
## About The Project

Console program in C++ that implement support of 3D curves hierarchy.
1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
definitions are below). Each curve is able to return a 3D point and a first derivative (3D
vector) per parameter 't' along the curve.
2. Populate a vector of objects of these types created in random manner with
random parameters.
3. Print coordinates of points and derivatives of all curves in the vector at t=PI/4.
4. Populate a second vector with only circles from the first vector. 
The second vector shares circles of the first one, e.g. via pointers.
5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
smallest radius, the last - the greatest.
6. Compute the total sum of radii of all curves in the second container.

Curve definitions:
- All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.
- Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
- Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.
- Helix is spatial and is defined by its radius and step. It takes 2 * PI in
parametric space to make a round, i.e. any point on helix satisfies the condition C(t + 2*PI) = C(t) +
{0, 0, step}.

## How To Use

To clone and run this application, you'll need Git and CMake installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://gitlab.com/kiber_gorg/3d-curves.git

# Go into the repository
$ cd 3d-curves

# Create build directory 
$ mkdir build && cd build

# Configure
$ cmake ..

# Build
$ cmake --build .

# Run the app
$ ./3d-curves
```

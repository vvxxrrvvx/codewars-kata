#include <cmath>

using namespace std; 

double areaOfPolygonInsideCircle(double circleRadius, int numberOfSides)
{
  const double PI = 3.14159265;
  double area = (0.5 * numberOfSides * pow(circleRadius, 2)) * sin((2 * PI) / numberOfSides);
  return round(area * 1000) / 1000; // Round to 3 decimal places
}
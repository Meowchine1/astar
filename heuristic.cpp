#include "heuristic.h"
#include <cmath>

int heuristic_Manhattan(Node &v1, Node &v2)
{
    return abs(v1.x - v2.x) + abs(v1.y - v2.y);
}

int heuristic_Chebyshev(Node &v1, Node &v2)
{
    return std::max(abs(v1.x - v2.x), abs(v1.y - v2.y));
}

int heuristic_Euclid(Node &v1, Node &v2)
{
    return sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
}

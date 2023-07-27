#ifndef HEURISTIC_H
#define HEURISTIC_H
#include "node.h"

int heuristic_Manhattan(Node &v1, Node &v2);
int heuristic_Chebyshev(Node &v1, Node &v2);
int heuristic_Euclid(Node &v1, Node &v2);

#endif // HEURISTIC_H

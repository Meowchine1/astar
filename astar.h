#ifndef ASTAR_H
#define ASTAR_H
#include "astar.h"
#include "node.h"
#include "graph.h"
#include <queue>

class Astar
{
public:
    Astar();
    std::string run(Node* start, Node* goal, Graph graph);


private:
    std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> queue;
    std::vector<Node*> visited;
    std::unordered_map<Node*, Node*> parent;
    std::unordered_map<Node*, int> minWay;

};

#endif // ASTAR_H
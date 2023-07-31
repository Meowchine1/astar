#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include "node.h"
#include <string>

template <>
struct std::hash<Node>
{
  std::size_t operator()(const Node& k) const
  {
    using std::size_t;
    using std::hash;

    // Compute individual hash values for first,
    // second and third and combine them using XOR
    // and bit shifting:

    return ((hash<int>()(k.distance)
             ^ (hash<std::string>()(k.name) << 1)) >> 1);
  }
};

class Graph
{
private:
    std::unordered_map<Node*, std::unordered_map<Node*, int>> edges_weights;
    void readtxt(std::string filePath);
public:
    Graph(std::string filePath);
    Graph();
    void set_relation(Node* from, Node* to, int weight);
    int get_edge_weight(const Node* keyNode, const Node* childNode);
    void printGraph();
    ~Graph();
};

#endif // GRAPH_H

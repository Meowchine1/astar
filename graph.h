#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include "node.h"
#include <string>
#include <QObject>
typedef std::unordered_map<Node*, std::unordered_map<Node*, int>> specified_map;
typedef std::unordered_map<Node*, int> inner_map;

class Graph : public QObject
{

    Q_OBJECT

private:
    specified_map edges_weights;
    void readtxt(std::string filePath);
public:
    Graph(std::string filePath);
    Graph();
    specified_map get_edges_weights(){return edges_weights;}
    inner_map get_edges_weights(Node* keyNode)
    {
        return edges_weights[keyNode];
    }

    void addNode(Node* node);
    void set_relation(Node* from, Node* to, int weight);
    int get_edge_weight(const Node* keyNode, const Node* childNode);
    void printGraph();
    ~Graph();

 signals:
    void sendGraph(Graph* graph);


 public slots:
    void createEmptyGraphRequest();
    void readGraphFromTxtRequest(std::string path);
    void addNodeRequest(Node* node);
    void addRelationsRequest(Node* from, Node* to, int weight);

};

#endif // GRAPH_H

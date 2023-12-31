
#include <iostream>
#include <fstream>
#include<algorithm>
#include <bits/stdc++.h>

#include "splitter.h"
#include "graph.h"

Graph* Graph::instance = nullptr;


void Graph::addNode(Node* node)
{
    auto it = std::find_if(nodes.begin(),
                           nodes.end(), [&](const Node* elem) {
        return elem == node;
    });
    if(it == nodes.end())
    {
        edges_weights[node] = std::unordered_map<Node*, int>();
        nodes.push_back(node);
    }
    else{

        // node already exist
    }
}

void Graph::addNode(QString name, QString x, QString y){

    auto it = std::find_if(nodes.begin(),
                           nodes.end(), [&](const Node* elem) {
        return elem->name == name;
    });
    if(it == nodes.end()){
        Node node(name, x.toInt(), y.toInt());
        edges_weights[&node] =
                std::unordered_map<Node*, int>();
        nodes.push_back(&node);
    }
    else{
        // node already exist
    }

}

int Graph::get_edge_weight(const Node* keyNode, const Node* childNode)
{
    auto it = edges_weights.find(const_cast<Node*>(keyNode));
    if (it != edges_weights.end()) {
        const std::unordered_map<Node*, int>& innerMap = it->second;

        auto innerIt = innerMap.find(const_cast<Node*>(childNode));
        if (innerIt != innerMap.end())
        {
            return innerIt->second;
        }
        else
        {
            QString ss;
            ss + "Realtions between " + keyNode->name + " and " + childNode->name
                    + " aren't exist.";
            throw ss;
        }
    } else
    {
        QString ss;
        ss + "The node" + keyNode->name + " unexists.";
        throw ss;
    }
}

QVector<QVector<QString>> Graph::getNodes()
{
    QVector<QVector<QString>> result;
    result.append({"Node name", "Coordinate X", "Coordinate Y"});
    for(Node* node: nodes){
        result.append({node->name, QString::number(node->getX()), QString::number(node->getY())});
    }

    return result;
}

Node* Graph::findNodeByName(QString name){

    auto it = std::find_if(nodes.begin(),
                           nodes.end(), [&](const Node* elem) {
        return elem->name == name;
    });
    if(it != nodes.end())
    {
        return *it;
    }
    else
    {
        std::stringstream ss;
        ss << "Node with name '" << name.toStdString() << "'  is't exist.";
        throw ss;
    }
}

void Graph::set_relation(Node *from, Node *to, int weight)
{

    auto itFrom = std::find_if(nodes.begin(),
                               nodes.end(), [&](const auto& elem) {
        return elem == from;
    });

    auto itTo = std::find_if(nodes.begin(),
                             nodes.end(), [&](const auto& elem) {
        return elem == to;
    });

    if(itFrom != nodes.end())
    {
        if(itTo != nodes.end()){
            edges_weights[from][to] = weight;

        }else{
            edges_weights[to] = std::unordered_map<Node*, int>();
            edges_weights[from][to] = weight;
        }
    }else{
        if(itTo != nodes.end()){
            edges_weights[from] = std::unordered_map<Node*, int>();
            edges_weights[from][to] = weight;

        }else{
            edges_weights[to] = std::unordered_map<Node*, int>();
            edges_weights[from] = std::unordered_map<Node*, int>();
            edges_weights[from][to] = weight;
        }
    }
}

Graph::~Graph()
{
    for (auto& pair : edges_weights)
    {
        pair.second.clear();
    }
    edges_weights.clear();
}

Graph* Graph::getInstance()
{
    if(instance == nullptr){
        instance = new Graph();
    }
    return instance;
}

void Graph::readtxt(QString filePath)
{
    edges_weights.clear();
    std::string line;
    char lineSeparator = '\n';
    char innerSeparator = ' ';
    char coordinateSeparator = '(';

    int i;
    size_t pos = 0;
    std::ifstream in(filePath.toStdString());
    std::cout<<std::endl;

    std::vector<Node*> nodes;

    if (in.is_open())
    {
        while (std::getline(in, line, lineSeparator))
        {
            i = 0;

            QString nodename;
            int weight;
            int x, y;
            Node* ptrMainNode{nullptr};
            Node* ptrNeighborNode{nullptr};

            std::stringstream ss(line);
            std::string word;
            while (ss >> word) { // Extract word from the stream.

                if(i == 0){ // way for node with coordinates (first elem in line)
                    nodename = QString::fromStdString(getSubstring(word, pos, '('));
                    x = std::stoi(getSubstring(word, pos, ','));
                    y = std::stoi(getSubstring(word, pos, ')'));

                    // iterator to find vector element
                    auto it = std::find_if(nodes.begin(),
                                           nodes.end(), [&](const Node* elem) {
                        return elem->name == nodename;
                    });

                    if (it != nodes.end()) { // if node has already initialized
                        ptrMainNode = *it;
                        ptrMainNode->setX(x);
                        ptrMainNode->setY(y);
                    }
                    else // if uninitialized node
                    {
                        ptrMainNode = new Node(nodename, x, y);
                        edges_weights[ptrMainNode] =
                                std::unordered_map<Node*, int>();
                        nodes.push_back(ptrMainNode);
                    }
                }
                else{
                    // for neighbors
                    nodename =  QString::fromStdString(getSubstring(word, pos, '('));
                    weight = std::stoi(getSubstring(word, pos, ')'));
                    auto it = std::find_if(nodes.begin(),
                                           nodes.end(), [&](const Node* elem) {
                        return elem->name == nodename;
                    });

                    if (it != nodes.end()) {
                        ptrNeighborNode = *it;
                    }
                    else
                    {
                        ptrNeighborNode = new Node(nodename);
                        nodes.push_back(ptrNeighborNode);
                    }

                    edges_weights[ptrMainNode][ptrNeighborNode] = weight;
                }
                i++;
            }
            std::cout << std::endl;std::cout << std::endl;
            //            delete ptrMainNode;
            //            delete ptrNeighborNode;

        }
        std::cout << std::endl;
    }

    in.close();

    return;
}

void Graph::printGraph()
{
    for (auto& pair : edges_weights) {
        const Node* keyNode = pair.first;
        std::unordered_map<Node*, int>& innerMap = pair.second;
        QString message = "Vertex is " + keyNode->name + " coordinates("
                + keyNode->getX() + ";" + keyNode->getY() + ")\t neighbors: ";
        std::cout<< message.toStdString();
        for (auto& innerPair : innerMap) {
            const Node* childNode = innerPair.first;
            int value = innerPair.second;
            message = "name:" + childNode->name + " coordinates("
                    + childNode->getX() + ";" + childNode->getY() +
                    ") " + " weight = " + value + "\n";
            std::cout<< message.toStdString();

        }
    }

}


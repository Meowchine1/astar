#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include<algorithm>
#include <bits/stdc++.h>
#include "splitter.h"

Graph::Graph(std::string filePath){readtxt(filePath);}

void Graph::readtxt(std::string filePath)
{
    std::string line;
    char lineSeparator = '\n';
    char innerSeparator = ' ';
    char coordinateSeparator = '(';

    int i;
    size_t pos = 0;
    std::ifstream in(filePath);
    std::cout<<std::endl;

    std::vector<Node*> nodes;

    if (in.is_open())
    {
        while (std::getline(in, line, lineSeparator))
        {
            i = 0;

            std::string nodename;
            int weight;
            int x, y;
            Node* ptrMainNode{nullptr};
            Node* ptrNeighborNode{nullptr};

            std::stringstream ss(line);
            std::string word;
            while (ss >> word) { // Extract word from the stream.

                if(i == 0){ // way for node with coordinates (first elem in line)
                    nodename = getSubstring(word, pos, '(');
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
                    nodename = getSubstring(word, pos, '(');
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

int Graph::get_edge_weight(const Node& keyNode, const Node& childNode)
{
    return 0;
}

void Graph::printGraph()
{
    // std::unordered_map<Node, std::unordered_map<Node, int>>
    for (auto& pair : edges_weights) {
        const Node* keyNode = pair.first;
        std::unordered_map<Node*, int>& innerMap = pair.second;
        std::cout<<"Vertex is "<< keyNode->name << " coordinates("
                <<keyNode->getX()<<";"<<keyNode->getY()<<")\t neighbors: ";
        // Перебор внутреннего unordered_map
        for (auto& innerPair : innerMap) {
            const Node* childNode = innerPair.first;
            int value = innerPair.second;
            std::cout<< "name:" << childNode->name << " coordinates("
                     << childNode->getX() << ";" << childNode->getY() <<
                       ") " << " weight = " << value << "\n";

        }
    }

}


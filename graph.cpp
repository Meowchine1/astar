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

    std::vector<Node> nodes;

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

                if(i == 0){ // for node with coordinates (first elem in line)
                    nodename = getSubstring(word, pos, '(');
                    x = std::stoi(getSubstring(word, pos, ','));
                    y = std::stoi(getSubstring(word, pos, ')'));

                    // iterator to find vector element
                    auto it = std::find_if(nodes.begin(),
                                           nodes.end(), [&](const Node& elem) {
                        return elem.name == nodename;
                    });

                    if (it != nodes.end()) {
                        ptrMainNode = &(*it);

                        it->setX(x);
                        it->setY(y);
                    }
                    else
                    {
                        Node node(nodename, x, y);
                        ptrMainNode = &node;
                        edges_weights[*ptrMainNode] =
                                std::unordered_map<Node, int>();

                    }
                }
                else{
                // for neighbors
                    nodename = getSubstring(word, pos, '(');
                    weight = std::stoi(getSubstring(word, pos, ')'));
                    auto it = std::find_if(nodes.begin(),
                                           nodes.end(), [&](const Node& elem) {
                        return elem.name == nodename;
                    });

                    if (it != nodes.end()) {
                        ptrNeighborNode = &(*it);
                    }
                    else
                    {
                        Node neighbornode(nodename);
                        ptrNeighborNode = &neighbornode;
                    }

                    edges_weights[*ptrMainNode][*ptrNeighborNode] = weight;

                    break;
                }
                i++;
            }

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


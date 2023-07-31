#include "astar.h"
#include "node.h"
#include "graph.h"
#include "heuristic.h"
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <string>

Astar::Astar(){}

/*
    std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> queue;
    std::vector<Node> visited;
    std::unordered_map<Node*, Node*> parent;
    std::unordered_map<Node*, int> minWay;
*/

void fill(std::unordered_map<Node*, int>& minWay, Graph& graph)
{
    for (auto& pair : graph.get_edges_weights())
    {
        minWay[pair.first] = INT_MAX;
    }
}

std::string Astar::restorePath(Node* start, Node* goal)
{
    std::string path;
    Node* ptrNode = goal;
    Node* ptrtemp{nullptr};
    while (ptrNode != start)
    {
        path+ptrNode->name+" -> ";
        ptrtemp = parent[ptrNode];
        ptrNode = ptrtemp;
    }

    return path;
}

std::string Astar::run(Node* start, Node* goal, Graph& graph)
{
    queue.push(start);
    fill(minWay, graph);
    minWay[start] = 0;
    Node* currentptr = {nullptr};
    while(!queue.empty())
    {
       currentptr = queue.top();
       queue.pop();
       if(currentptr == goal)
       {
           return restorePath(start, goal);
       }

       visited.push_back(currentptr);
       auto it = graph.get_edges_weights().find(const_cast<Node*>(currentptr));
       if(it != graph.get_edges_weights().end())
       {

            //const std::unordered_map<Node*, int>& innerMap = it->second;
            for(auto& pair : graph.get_edges_weights(currentptr))
            {
                Node* child = pair.first;
                int pathWeight = pair.second;

                if(std::find(visited.begin(),
                             visited.end(), child) == visited.end()
                        || minWay[currentptr] + pathWeight < minWay[child])
                {
                    parent[child] = currentptr;
                    minWay[child] = minWay[currentptr] + pathWeight;
                    unsigned int heuristic =
                            heuristic_Manhattan(child, goal);
                    child->setDistance(heuristic + pathWeight);
                    queue.push(child);

                }
            }
       }
       //for(auto& pair : graph.get_edges_weights())
    }

    return "";
}

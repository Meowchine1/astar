#include "astar.h"
#include "node.h"
#include "graph.h"
#include "heuristic.h"
#include <algorithm>

Astar::Astar(){}

/*
    std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> queue;
    std::vector<Node> visited;
    std::unordered_map<Node*, Node*> parent;
    std::unordered_map<Node*, int> minWay;
*/
std::string Astar::run(Node* start, Node* goal, Graph graph)
{
    queue.push(start);
    minWay[start] = 0;
  //  minWay  все вершины большим числом
    parent[start] = start;
    Node* currentptr = {nullptr};
    while(queue.size() != 0)
    {
       currentptr = queue.top();
       queue.pop();
       if(currentptr == goal)
       {
           return "true"; // вызов функции восстановления пути
       }
       visited.push_back(currentptr);
       auto it = graph.get_edges_weights().find(const_cast<Node*>(currentptr));
       if(it != graph.get_edges_weights().end())
       {
            const std::unordered_map<Node*, int>& innerMap = it->second;
            for(auto& pair : innerMap)
            {
                Node* child = pair.first;
                int pathWeight = pair.second;

                if(std::find(visited.begin(),
                             visited.end(), child) != visited.end()
                        || minWay[currentptr] + pathWeight < minWay[child])
                {
                    parent[child] = currentptr;
                    minWay[child] = pathWeight;
                    unsigned int heuristic =
                            heuristic_Manhattan(currentptr, child);
                    child->setDistance(heuristic + pathWeight);

                }
            }
       }
       //for(auto& pair : graph.get_edges_weights())
    }

    return "";
}

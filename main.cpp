#include "node.h"
#include "graph.h"
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
//    std::string path = fs::current_path()
//            .append("../astar/data/graph.txt");
//    std::cout<<path;
//    Graph graph(path);
//    graph.printGraph();
    Node elem1("a", 12, 111), elem2("b", -114, 59);
    Graph graph;
    graph.set_relation(&elem1, &elem2, 45);
    graph.printGraph();
    std::cout<< "\n weight = " <<graph.get_edge_weight(&elem1, &elem2) << std::endl;

    return 0;
}

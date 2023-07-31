#include "node.h"
#include "graph.h"
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    std::string path = fs::current_path()
            .append("../astar/data/graph.txt");
    std::cout<<path;
    Graph graph(path);
    graph.printGraph();
    return 0;
}

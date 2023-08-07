#include "node.h"
#include "graph.h"
#include "astar.h"
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
//    std::string path = fs::current_path()
//            .append("../astar/data/graph.txt");
//    std::cout<<path;
//    Graph graph(path);



    Node a("a", 0, 0), b("b", 2, 0), c("c", 5, 3),
            d("d", 0, 5), e("e", 5, 5);
    Graph graph;
    graph.addNode(&a);
    graph.set_relation(&a, &b, 30);
    graph.set_relation(&a, &e, 1);
    graph.set_relation(&a, &d, 40);
    graph.set_relation(&d, &e, 40);
    graph.set_relation(&b, &c, 10);
    graph.set_relation(&c, &e, 10);
    Astar astar;
    std::cout << astar.run(&a, &e, graph);

    return 0;
}

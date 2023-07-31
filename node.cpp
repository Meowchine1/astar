#include "node.h"

Node::Node(const std::string _name): name{_name}
{}

Node::Node(const std::string _name, int _x, int _y):
    name{_name}, x{_x}, y{_y}
{}
Node::~Node(){}


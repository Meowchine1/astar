#ifndef NODE_H
#define NODE_H
#include <string>
class Node
{
public:
    const int x, y;
    const std::string name;
    int distance = 0; // f(v)

    Node(const std::string _name, const int _x, const int _y);

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

    bool operator>(const Node& node) const
    {
        return this->distance > node.distance;
    }

    bool operator<(const Node& node) const
    {
        return !(this->distance > node.distance);
    }

    bool operator>=(const Node& node) const
    {
        return this->distance >= node.distance;
    }

    bool operator<=(const Node& node) const
    {
        return !(this->distance >= node.distance);
    }

    bool operator==(const Node& node) const
     { return (this->distance == node.distance
               && this->name == node.name
               && this->x == node.x
               && this->y == node.y);
     }

};

#endif // NODE_H

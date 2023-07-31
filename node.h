#ifndef NODE_H
#define NODE_H
#include <string>

#define UNDEFINED 1435483
class Node
{

private:
    int x = UNDEFINED, y = UNDEFINED;
public:
    const std::string name;
    int distance = 0; // f(v)

    Node(const std::string _name);
    Node(const std::string _name, int _x, int _y);
    ~Node();

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

    int getX() const {return x;}
    int getY() const {return y;}
    void setX(const int value)
    {
        if(x == UNDEFINED)
        {
            x = value;
        }
        else
        {
            throw "coordinate 'x' was initialized";
        }
    }
     void  setY(const int value)
    {
        if(y == UNDEFINED)
        {
           y = value;
        }
        else
        {
            throw "coordinate 'y' was initialized";
        }
    }

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
     { return this->name == node.name;
     }

};

#endif // NODE_H

#ifndef NODE_H
#define NODE_H
#include <QString>
#include <QObject>
#include <QDataStream>
#define UNDEFINED 1435483

class Node : public QObject
{
    Q_OBJECT

private:
    int x = UNDEFINED, y = UNDEFINED;
    unsigned int distance = 0; // f(v);
public:
    QString name;
    Node(const QString _name);
    Node(const QString _name, int _x, int _y);

    Node(){}
    // ////
    bool isolated;
    std::vector<Node*> children;
    Node(int _x, int _y, bool _isolated): x(_x), y(_y), isolated(_isolated) {}
    // ////

    Node(const Node& other) : QObject(), name(other.name), x(other.getX()), y(other.getY()), distance(other.getDistance()) {}
    Node* operator= (Node& other){
        x = other.getX();
        y = other.getY();
        distance = other.getDistance();
        name = other.name;
        return this;
    }

    ~Node();

    int getX() const {return x;}
    int getY() const {return y;}
    int getDistance() const {return distance;}
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
    void setDistance(unsigned int value)
    {
        distance = value;
    }


};

//std::ostream& operator << (std::ostream &os, const Node &node)
//{
//    return os << node.name;
//}

#endif // NODE_H

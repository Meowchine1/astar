#ifndef NODE_H
#define NODE_H
#include <string>
#include <QObject>
#define UNDEFINED 1435483

class Node : public QObject
{

    Q_OBJECT

private:
    int x = UNDEFINED, y = UNDEFINED;
    unsigned int distance = 0; // f(v);
public:
    const std::string name;
    Node(const std::string _name);
    Node(const std::string _name, int _x, int _y);
    ~Node();

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

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

signals:

    void sendNode(Node* node);

public slots:
    void createNodeRequest(std::string name, int x, int y);
};

#endif // NODE_H

#ifndef PROJECT3_NODE_H
#define PROJECT3_NODE_H

#include <vector>
#include <ostream>

class Node;

typedef std::vector<Node*> NodeList;

class Node {

public:
    NodeList edges;
    bool visited = false;
    unsigned int id;

    Node(unsigned int id);

    void visit();

    friend std::ostream& operator<<(std::ostream& os, const Node& node);

    void reset();
};

#endif //PROJECT3_NODE_H

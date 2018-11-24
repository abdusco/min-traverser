#ifndef PROJECT3_NODE_H
#define PROJECT3_NODE_H

#include <vector>
#include <ostream>

class Node;

typedef std::vector<Node*> NodeList;

class Node {
public:
    long index = -1;
    long lowLink = -1;
    long id;
    bool stacked = false;
    bool visited = false;

    NodeList neighbors;

    explicit Node(long id);

    friend std::ostream& operator<<(std::ostream& os, const Node& node);

    bool operator!=(const Node& rhs) const;

    bool operator==(const Node& rhs) const;

    void reset();
};

#endif //PROJECT3_NODE_H

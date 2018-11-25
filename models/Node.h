#ifndef PROJECT3_NODE_H
#define PROJECT3_NODE_H

#include <vector>
#include <ostream>

class Node;

typedef std::vector<Node*> NodeList;

class Node {
public:
    long id;
    bool marked = false;
    bool visited = false;

    NodeList neighbors;

    explicit Node(long id);

    friend std::ostream& operator<<(std::ostream& os, const Node& node);

    bool operator!=(const Node& rhs) const;

    bool operator==(const Node& rhs) const;
};

#endif //PROJECT3_NODE_H

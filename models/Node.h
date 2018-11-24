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

    long getIndex() const;

    bool onStack() const;

    void onStack(bool isStacked);

    void setLowLink(long lowLink);

    NodeList neighbors;

    long getLowLink() const;

    bool isRoot() const;

    explicit Node(long id);

    bool isVisited();

    void setIndex(long index);

    friend std::ostream& operator<<(std::ostream& os, const Node& node);

    bool operator!=(const Node& rhs) const;

    bool operator==(const Node& rhs) const;
};

#endif //PROJECT3_NODE_H

#ifndef PROJECT3_NODE_H
#define PROJECT3_NODE_H

#include <vector>
#include <ostream>

class Node;

typedef std::vector<Node*> NodeList;

class Node {
private:
    bool marked = false;
    bool markDeleted = false;
public:
    long id;
    bool visited = false;

    NodeList neighbors;

    explicit Node(long id);

    friend std::ostream& operator<<(std::ostream& os, const Node& node);

    bool operator!=(const Node& rhs) const;

    bool operator==(const Node& rhs) const;

    bool isMarked();
    void mark();
    void deleteMark();

};

#endif //PROJECT3_NODE_H

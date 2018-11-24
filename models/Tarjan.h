#ifndef PROJECT3_TARJAN_H
#define PROJECT3_TARJAN_H

#include <stack>

#include "Node.h"

class Tarjan {
    const NodeList& nodes;

    long index = 0;
    std::vector<NodeList> sccs;
    std::stack<Node*> stack;

    void connect(Node& v);

public:
    const std::vector<NodeList>& getSCCs() const;

    explicit Tarjan(const NodeList& nodes);

};


#endif //PROJECT3_TARJAN_H

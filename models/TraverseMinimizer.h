#ifndef PROJECT3_SAFEBROKER_H
#define PROJECT3_SAFEBROKER_H

#include <stack>
#include <set>
#include "Node.h"

class TraverseMinimizer {
public:
    std::vector<Node*> markedNodes;

    explicit TraverseMinimizer(const NodeList& nodes);

private:
    const NodeList& nodes;

    void dfs(Node& node);

    void removeMark(Node& marked);
};


#endif //PROJECT3_SAFEBROKER_H

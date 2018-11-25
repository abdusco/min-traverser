#include <algorithm>
#include "TraverseMinimizer.h"

TraverseMinimizer::TraverseMinimizer(const NodeList& nodes) : nodes(nodes) {
    for (auto node : nodes) {
        if (node->visited) continue;

        node->marked = true;
        markedNodes.push_back(node);
        dfs(*node);
    }
}


void TraverseMinimizer::dfs(Node& node) {
    auto pile = new std::stack<Node*>;
    pile->push(&node);

    while (!pile->empty()) {
        auto v = pile->top();
        pile->pop();

        if (v->visited) continue;
        v->visited = true;

        for (auto neighbor : v->neighbors) {
            if (neighbor->marked) {
                removeMark(*neighbor);
                continue;
            }
            if (neighbor->visited) continue;
            pile->push(neighbor);
        }
    }
    delete pile;
}


void TraverseMinimizer::removeMark(Node& marked) {
    for (auto it = markedNodes.begin(); it != markedNodes.end(); it++) {
        if (*it != &marked) continue;
        marked.marked = false;
        markedNodes.erase(it);
        return;
    }
}


#include <algorithm>
#include "TraverseMinimizer.h"

TraverseMinimizer::TraverseMinimizer(const NodeList& nodes) : nodes(nodes) {
    for (auto node : nodes) {
        if (node->visited) continue;

        node->marked = true;
        startingPoints.push_back(node);
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
    for (auto it = startingPoints.begin(); it != startingPoints.end(); it++) {
        if (*it != &marked) continue;
        marked.marked = false;
        startingPoints.erase(it);
        return;
    }
}


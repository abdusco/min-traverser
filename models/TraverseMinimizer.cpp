#include <algorithm>
#include "TraverseMinimizer.h"

TraverseMinimizer::TraverseMinimizer(const NodeList& nodes) : nodes(nodes) {
    for (Node* node : nodes) {
        if (node->visited) continue;

        node->mark();
        markedNodes.push_back(node);
        dfsStack(node);
    }
}

void TraverseMinimizer::dfs(Node* v) {
    if (v->visited) return;
    v->visited = true;

    for (Node* neighbor : v->neighbors) {
        if (neighbor->isMarked()) {
            removeMark(neighbor);
            continue;
        }

        if (neighbor->visited) continue;
        dfs(neighbor);
    }
}


void TraverseMinimizer::dfsStack(Node* node) {
    std::stack<Node*> recursion;
    recursion.push(node);

    while (!recursion.empty()) {
        auto v = recursion.top();
        recursion.pop();

        if (v->visited) continue;
        v->visited = true;

        for (Node* neighbor : v->neighbors) {
            if (neighbor->isMarked()) {
                removeMark(neighbor);
                continue;
            }
            if (neighbor->visited) continue;
            recursion.push(neighbor);
        }
    }
}


void TraverseMinimizer::removeMark(Node* marked) {
    for (auto& markedNode : markedNodes) {
        if (markedNode != marked) continue;
        marked->deleteMark();
        return;
    }
}


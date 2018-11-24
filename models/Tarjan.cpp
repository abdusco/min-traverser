#include <istream>
#include <iostream>
#include "Tarjan.h"

Tarjan::Tarjan(const NodeList& nodes) : nodes(nodes) {
    for (Node* v : nodes) {
        if (!v->visited) connect(*v);
    }
}

void Tarjan::connect(Node& v) {
    v.index = v.lowLink = index++;
    stack.push(&v);
    v.visited = v.stacked = true;

    for (Node* w : v.neighbors) {
        if (w->index == -1) {
            connect(*w);
            v.lowLink = std::min(v.lowLink, w->lowLink);
        } else if (w->stacked) {
            v.lowLink = std::min(v.lowLink, w->index);
        }
    }

    if (v.lowLink == v.index) {
        NodeList scc;
        Node* w;
        do {
            w = stack.top();
            stack.pop();
            w->stacked = false;
            scc.push_back(w);
        } while (v != *w);

        if (!scc.empty())
            sccs.push_back(scc);
    }
}

const std::vector<NodeList>& Tarjan::getSCCs() const {
    return sccs;
}

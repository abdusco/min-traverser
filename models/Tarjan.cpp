#include <istream>
#include <iostream>
#include "Tarjan.h"

Tarjan::Tarjan(const NodeList& nodes) : nodes(nodes) {}

void Tarjan::sortTopological() {
    for (Node* node : nodes) {
        if (node->visited) continue;
        startingPoints.push_back(node);
        NodeList visited;
        depthFirstSearch(*node, visited);
        for (Node* visitedNode : visited) {
            ordering.insert(ordering.begin(), visitedNode);
        }
    }

    sorted = true;
}

void Tarjan::depthFirstSearch(Node& current, NodeList& visited) {
    current.visit();
    for (Node* edge : current.edges) {
        if (edge->visited) continue;
        depthFirstSearch(*edge, visited);
    }
    visited.push_back(&current);
}

NodeList Tarjan::getTopologicalOrdering() {
    if (!sorted) sortTopological();
    return ordering;
}

NodeList Tarjan::getStartingPoints() {
    if (!sorted) sortTopological();
    return startingPoints;
}

void Tarjan::reset() {
    sorted = false;
    startingPoints = NodeList();
    ordering = NodeList();

    for (Node* node : nodes) {
        node->reset();
    }
}
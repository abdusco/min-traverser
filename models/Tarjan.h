#ifndef PROJECT3_TARJAN_H
#define PROJECT3_TARJAN_H

#include "Node.h"

class Tarjan {
    const NodeList& nodes;
    NodeList ordering;
    NodeList startingPoints;
    bool sorted = false;

    void depthFirstSearch(Node& current, NodeList& visited);

    void sortTopological();

public:
    Tarjan(const NodeList& nodes);

    NodeList getTopologicalOrdering();

    NodeList getStartingPoints();

    void reset();
};


#endif //PROJECT3_TARJAN_H

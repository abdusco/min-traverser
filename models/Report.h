#ifndef PROJECT3_REPORT_H
#define PROJECT3_REPORT_H

#include <ostream>
#include "Node.h"

class Report {
    NodeList& nodes;
public:
    explicit Report(NodeList& nodes) : nodes(nodes) {}

    friend std::ostream& operator<<(std::ostream& os, const Report& writer) {
        os << writer.nodes.size();
        for (Node* node : writer.nodes) {
            os << " " << node->id;
        }
        return os;
    }
};


#endif //PROJECT3_REPORT_H

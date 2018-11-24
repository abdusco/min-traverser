#include <iostream>
#include "Node.h"

Node::Node(long id) : id(id) {}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << "N("
       << node.id
       //       << ":"
       //       << node.index
       //       << ","
       //       << node.lowLink
       << ")";
    return os;
}

bool Node::operator==(const Node& rhs) const {
    return id == rhs.id;
}

bool Node::operator!=(const Node& rhs) const {
    return !(*this == rhs);
}

void Node::reset() {
    index = -1;
    lowLink = -1;
    stacked = false;
    visited = false;
}


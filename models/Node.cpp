#include <iostream>
#include "Node.h"

Node::Node(long id) : id(id) {}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << node.id;
    return os;
}

bool Node::operator==(const Node& rhs) const {
    return id == rhs.id;
}

bool Node::operator!=(const Node& rhs) const {
    return !(*this == rhs);
}
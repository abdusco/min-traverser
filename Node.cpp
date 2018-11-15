#include <iostream>
#include "Node.h"

Node::Node(unsigned int id) : id(id) {}

void Node::visit() {
    visited = true;
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << "N("
       << node.id << ","
       << (node.visited ? '+' : '-')
       << ")";
    return os;
}
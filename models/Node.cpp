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

void Node::setIndex(long index) {
    this->index = index;
}

void Node::setLowLink(long lowLink) {
    this->lowLink = lowLink;
}

long Node::getLowLink() const {
    return lowLink;
}

long Node::getIndex() const {
    return index;
}

bool Node::isRoot() const {
    return index == lowLink;
}

bool Node::operator==(const Node& rhs) const {
    return id == rhs.id;
}

bool Node::operator!=(const Node& rhs) const {
    return !(*this == rhs);
}

bool Node::onStack() const {
    return stacked;
}

void Node::onStack(bool isStacked) {
    this->stacked = isStacked;
}

bool Node::isVisited() {
    return index >= 0;
}


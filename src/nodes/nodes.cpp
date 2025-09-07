#include "nodes/nodes.hpp"

std::string Node::getName() const {
    return _name;
}

bool Node::operator==(const Node& other) const {
    return this == &other;
}
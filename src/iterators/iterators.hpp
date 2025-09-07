#pragma once
#include <algorithm>
#include <memory>
#include <iostream>
#include <deque>

#include "nodes/nodes.hpp"

class Iter {
protected:
    std::shared_ptr<Node> _current = nullptr;
    /// @brief Nodes which is need to visit
    std::deque<std::shared_ptr<Node> > _deque; 
public:
    Iter(std::shared_ptr<Node>) : _current(nullptr) {}
    virtual ~Iter() = default;

    bool operator==(const Iter& other) const;
    bool operator!=(const Iter& other) const;
    Node& operator*() const;

    virtual bool next(bool) = 0;
};


class DFSIter : public Iter {
protected:
    bool next(bool skip_dirs) override;
public:
    DFSIter(std::shared_ptr<Node> root, bool skip_dirs = false) : Iter(nullptr) {
        if (root) {
            _deque.push_back(root);
            next(skip_dirs);
        }
    }
    DFSIter& operator++();
};

class FilesIter : public DFSIter {
public:
    FilesIter(std::shared_ptr<Dir> node) : DFSIter(node, true) {}
    FilesIter& operator++();
};
#pragma once
#include <algorithm>
#include <memory>
#include <iostream>
#include <deque>

#include "nodes/nodes.hpp"

template <typename Derived> 
class Iter {
    using iterator_category = std::forward_iterator_tag;
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

    Derived& operator++();
    Derived operator++(int);
};


class DFSIter : public Iter<DFSIter> {
protected:
    bool next(bool skip_dirs) override;
public:
    DFSIter(std::shared_ptr<Node> root, bool skip_dirs = false) : Iter(nullptr) {
        if (root) {
            _deque.push_back(root);
            next(skip_dirs);
        }
    }
};

class FilesIter : public DFSIter {
public:
    FilesIter(std::shared_ptr<Dir> node) : DFSIter(node, true) {}
};

class BFSIter : public Iter<DFSIter> {
protected:
    bool next(bool) override;
public:
    BFSIter(std::shared_ptr<Node> root, bool skip_dirs = false) : Iter(nullptr) {
        if (root) {
            _deque.push_front(root);
            next(skip_dirs);
        }
    }
};
#pragma once
#include <memory>

#include "iterators/iterators.hpp"
#include "nodes/nodes.hpp"

template <typename It>
class Range {
   std::shared_ptr<Dir> _root = nullptr;
public:
    Range(std::shared_ptr<Node> root) 
        : _root(std::static_pointer_cast<Dir>(root)) {}
    
    It begin();
    It begin() const;
    It end();
    It end() const;
    
    using value_type = Node;
};

class DFSRange : public Range<DFSIter> {
public:
    DFSRange(std::shared_ptr<Node> root) : Range<DFSIter>(root) {}
};

class FilesRange : public Range<FilesIter> {
public:
    FilesRange(std::shared_ptr<Node> root) : Range<FilesIter>(root) {}
    using value_type = File;
};

class BFSRange : public Range<BFSIter> {
public: 
    BFSRange(std::shared_ptr<Node> root) : Range<BFSIter>(root) {}
};

template <typename It>
It Range<It>::begin() {
    return It{_root};
}

template <typename It>
It Range<It>::begin() const {
    return It{_root};
}

template <typename It>
It Range<It>::end() {
    return It{nullptr};
}

template <typename It>
It Range<It>::end() const {
    return It{nullptr};
}


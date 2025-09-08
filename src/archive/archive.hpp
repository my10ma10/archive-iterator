#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "ranges/ranges.hpp"

class Archive {
    std::shared_ptr<Dir> _root = nullptr;
public:
    Archive(std::shared_ptr<Dir> root) : _root(root) {}
    DFSRange dfs() const;
    FilesRange files() const;
    BFSRange bfs() const;
};



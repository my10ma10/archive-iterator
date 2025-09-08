#include "archive/archive.hpp"

DFSRange Archive::dfs() const {
    return DFSRange(_root);
}

FilesRange Archive::files() const {
    return FilesRange(_root);
}

BFSRange Archive::bfs() const {
    return BFSRange(_root);
}
#include "archive/archive.hpp"

DFSRange Archive::dfs() const {
    return DFSRange{_root};
}

FilesRange Archive::files() const {
    return FilesRange(_root);
}

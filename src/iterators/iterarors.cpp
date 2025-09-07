#include "iterators/iterators.hpp"

bool Iter::operator==(const Iter& other) const {
    return _current == other._current;
}

bool Iter::operator!=(const Iter& other) const {
    return !(*this == other);
}

Node& Iter::operator*() const {
    return *_current;
}

DFSIter& DFSIter::operator++() {
    next(false);
    return *this;
}

bool DFSIter::next(bool skip_dirs) {
    while (!_deque.empty()) {
        _current = _deque.back();
        _deque.pop_back();

        if (std::shared_ptr<Dir> root = std::dynamic_pointer_cast<Dir>(_current)) {
            for (auto it = root->_children.rbegin(); it != root->_children.rend(); ++it) {
                _deque.push_back(*it);
            }
            if (!skip_dirs) {
                return true;
            }
        }
        else
            return true;
    }
    _current = nullptr;
    return false;
}

FilesIter& FilesIter::operator++() {
    next(true);
    return *this;
}

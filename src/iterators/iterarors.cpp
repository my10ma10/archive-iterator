#include "iterators/iterators.hpp"

template <typename Derived>
bool Iter<Derived>::operator==(const Iter& other) const {
    return _current == other._current;
}

template <typename Derived>
bool Iter<Derived>::operator!=(const Iter& other) const {
    return !(*this == other);
}

template <typename Derived>
Node& Iter<Derived>::operator*() const {
    return *_current;
}

template <typename Derived>
Derived& Iter<Derived>::operator++() {
    next(false);
    return *this;
}

template <typename Derived>
Derived Iter<Derived>::operator++(int) {
    Derived temp = *this;
    next(false);
    return temp;
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

bool BFSIter::next(bool) {
    while (!_deque.empty()) {
        _current = _deque.back();
        _deque.pop_back();

        if (std::shared_ptr<Dir> root = std::dynamic_pointer_cast<Dir>(_current)) {
            for (auto it = root->_children.begin(); it != root->_children.end(); ++it) {
                _deque.push_front(*it);
            }
        }
        return true;
    }
    _current = nullptr;
    return false;
}
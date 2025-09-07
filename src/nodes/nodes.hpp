#pragma once
#include <vector>
#include <string>
#include <memory>

class Node {
protected:
    std::string _name;
public:
    Node(const std::string name) : _name(name) {}
    virtual ~Node() = default;

    std::string getName() const;

    bool operator==(const Node& other) const;
};

class File : public Node {
    size_t _size;
public:
    File(const std::string name, size_t size) : Node(name), _size(size) {} 
    size_t size() {return _size;}
};

class Dir : public Node {
    friend class DFSIter;
    friend class FilesIter;
protected:
    std::vector<std::shared_ptr<Node> > _children;
public:
    Dir(const std::string name) : Node(name) {}

    void addFile(const std::string& name, size_t size) {
        _children.emplace_back(std::make_shared<File>(name, size));
    }
    void addFile(std::shared_ptr<File> file) {
        _children.emplace_back(file);
    }

    void addDir(const std::string& name) {
        _children.emplace_back(std::make_shared<Dir>(name));
    }
    void addDir(std::shared_ptr<Dir> dir) {
        _children.emplace_back(dir);
    }
};
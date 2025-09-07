#include "archive/archive.hpp"

int main() {
    try {
        auto img = std::make_shared<Dir>("img");
        img->addFile("logo.png", 7);

        auto docs = std::make_shared<Dir>("docs");
        docs->addFile("readme.md", 5);
        docs->addDir(img);

        auto bin = std::make_shared<Dir>("bin");
        bin->addFile("app", 3);
        
        auto root = std::make_shared<Dir>("root");
        root->addFile("a.txt", 2);
        root->addDir(docs);
        root->addDir(bin);

        Archive arch(root);

        for (const auto& node : arch.files()) {
            std::cout << node.getName() << std::endl;
        }
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    
    return 0;
}
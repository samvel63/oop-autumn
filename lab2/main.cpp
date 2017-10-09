#include <iostream>
#include <cstdlib>
#include <cstring>
#include "hexagon.h"
#include "TBinaryTree.h"

const int MAX_SIZE = 16;


int main(int argc, char** argv)
{
    TBinaryTree *tree = new TBinaryTree();
    char s[MAX_SIZE];

    std::cout << "Use 'help' or 'h' to get help." << std::endl;

    while (1) {
        std::cin.getline(s, MAX_SIZE);
        std::cin.clear();
        std::cin.sync();
        if (!strcmp(s, "insert") || !strcmp(s, "ins")) {
            int32_t side;
            if (!(std::cin >> side)) {
                std::cout << "Wrong value." << std::endl;
                continue;
            }
            tree->insert(Hexagon(side));
        } else if (!strcmp(s, "remove") || !strcmp(s, "rm")) {
            int32_t side;
            if (!(std::cin >> side)) {
                std::cout << "Wrong value." << std::endl;
                continue;
            }
            tree->remove(side);
        } else if (!strcmp(s, "find") || !strcmp(s, "f")) {
            if (tree->empty()) {
                std::cout << "Tree is empty." << std::endl;
                continue;
            }
            int32_t side;
            if (!(std::cin >> side)) {
                std::cout << "Wrong value." << std::endl;
                continue;
            }
            TBinaryTreeItem* rect = tree->find(side);
            if (rect != nullptr) {
                rect->GetHexagon().Print();
            } else {
                std::cout << "Hexagon not found." << std::endl;
            }
        } else if (!strcmp(s, "destroy") || !strcmp(s, "d")) {
            delete tree;
            tree = new TBinaryTree();
            std::cout << "Tree destroy." << std::endl;
        } else if (!strcmp(s, "print") || !strcmp(s, "pr")) {
            if (!tree->empty()) {
                std::cout << *tree << std::endl;
            } else {
                std::cout << "Tree is empty." << std::endl;
            }
        } else if (!strcmp(s, "quit") || !strcmp(s, "exit") || !strcmp(s, "q")) {
            delete tree;
            break;
        } else if (!strcmp(s, "help") || !strcmp(s, "h")) {
            std::cout << "Commands 'insert' and 'ins' create new triagle with your parameters." << std::endl;
            std::cout << "Commands 'remove' and 'rm' create new hexagon with your parameters." << std::endl;
            std::cout << "Commands 'find' and 'f' create new octagon with your parameters." << std::endl;
            std::cout << "Commands 'destroy' and 'd' output parameters of triagle." << std::endl;
            std::cout << "Commands 'print' and 'pr' output parameters of hexagon."  << std::endl;
            std::cout << "Commands 'quit' and 'q' exit the program." << std::endl;
        }
    }
    return 0;
}
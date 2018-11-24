#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "models/InputParser.h"
#include "models/Node.h"
#include "models/Tarjan.h"


int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Syntax: ./project3 <input_file> <output_file> [verbose]" << std::endl;
        std::cout << "(add any character to the end to output results to the console)" << std::endl;
        return 1;
    }
    bool verbose = argc > 3;

    std::ifstream input(argv[1]);
    NodeList adjList = InputParser(input).parse();

    Tarjan tarjan(adjList);

    for (const NodeList& component : tarjan.getSCCs()) {
        std::cout << "SCC:\t";
        for (Node* item : component) {
            std::cout << *item << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
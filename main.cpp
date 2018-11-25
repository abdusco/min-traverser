#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "models/InputParser.h"
#include "models/Node.h"
#include "models/TraverseMinimizer.h"


int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Syntax: ./project3 <input_file> <output_file> [verbose]" << std::endl;
        std::cout << "(add any character to the end to output results to the console)" << std::endl;
        return 1;
    }
    bool verbose = argc > 3;

    std::ifstream input(argv[1]);
    NodeList adjList = InputParser(input).parse();
    TraverseMinimizer sb(adjList);

    if (verbose) {
        int realSize = 0;
        for (Node* n : sb.markedNodes) {
            if (n->isMarked()) realSize++;
        }
        std::cout << realSize << " ";
        for (Node* n : sb.markedNodes) {
            if (!n->isMarked()) continue;
            std::cout << n->id << " ";
        }
        std::cout << std::endl;
    }

    std::ofstream outfile(argv[2]);
    int realSize = 0;
    for (Node* n : sb.markedNodes) {
        if (n->isMarked()) realSize++;
    }
    outfile << realSize << " ";
    for (Node* n : sb.markedNodes) {
        if (!n->isMarked()) continue;
        outfile << n->id << " ";
    }
    outfile << std::endl;
}
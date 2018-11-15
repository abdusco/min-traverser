#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "InputParser.h"
#include "Node.h"
#include "Tarjan.h"
#include "Report.h"


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
    NodeList ordering = tarjan.getTopologicalOrdering();
    NodeList necessary = tarjan.getStartingPoints();

    std::ofstream outfile(argv[2], std::ios::app);
    outfile << Report(necessary) << std::endl;

    if (verbose) {
        std::cout << "ORDERING" << std::endl;
        for (Node* n : ordering) {
            std::cout << *n << " ";
        }
        std::cout << std::endl;

        std::cout << "NECESSARY" << std::endl;
        for (Node* n : necessary) {
            std::cout << *n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
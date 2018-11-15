#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Node.h"
#include "Tarjan.h"


NodeList parseInput(const std::string& filename);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Syntax: ./project3 <input_file> <output_file> [verbose]" << std::endl;
        std::cout << "(add any character to the end to output results to the console)" << std::endl;
        return 1;
    }
    bool verbose = argc > 3;

    NodeList nodes = parseInput(argv[1]);

    Tarjan tarjan(nodes);
    NodeList ordering = tarjan.getTopologicalOrdering();
    NodeList necessary = tarjan.getStartingPoints();

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

NodeList parseInput(const std::string& filename) {
    std::ifstream infile(filename);

    std::string line;
    getline(infile, line);
    std::istringstream lss(line);

    unsigned int numNodes;
    lss >> numNodes;

    NodeList nodes;
    for (unsigned int i = 1; i <= numNodes; ++i) {
        nodes.emplace_back(new Node(i));
    }

    for (unsigned int i = 0;
         std::getline(infile, line) && i < numNodes;
         ++i) {
        Node* curr = nodes.at(i);
        std::istringstream ss(line);

        unsigned int numNeighbors, neighborId;
        ss >> numNeighbors;

        while (numNeighbors--) {
            ss >> neighborId;
            Node* neighbor = nodes.at(neighborId - 1);
            curr->edges.emplace_back(neighbor);
        }
    }
    return nodes;
}

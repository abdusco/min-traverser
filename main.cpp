#include <iostream>
#include <vector>
#include <fstream>

#include "models/InputParser.h"
#include "models/TraverseMinimizer.h"

void report(std::basic_ostream<char>& stream, NodeList& points);

int main(int argc, char* argv[]) {
    bool verbose = argc > 3;
    if (argc < 3) {
        std::cout << "Syntax: ./project3 <input_file> <output_file> [verbose]" << std::endl;
        std::cout << "(add any character to the end to output results to the console)" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    NodeList adjList = InputParser(input).parse();
    TraverseMinimizer sb(adjList);

    if (verbose) {
        report(std::cout, sb.startingPoints);
    }

    std::ofstream outfile(argv[2]);
    report(outfile, sb.startingPoints);
}

void report(std::basic_ostream<char>& stream, NodeList& points) {
    stream << points.size() << " ";
    for (Node* n : points) {
        stream << n->id << " ";
    }
    stream << std::endl;
}

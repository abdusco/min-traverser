#include <sstream>
#include "InputParser.h"

InputParser::InputParser(std::ifstream& input) : input(input) {}

NodeList& InputParser::parse() {
    std::string line;
    getline(input, line);
    std::istringstream listProps(line);

    // read # of nodes
    unsigned long numNodes;
    listProps >> numNodes;

    // create nodes
    auto nodes = new NodeList;
    for (unsigned long i = 1; i <= numNodes; ++i) {
        nodes->emplace_back(new Node(i));
    }

    // build adjacency list
    for (unsigned long i = 0;
         std::getline(input, line) && i < numNodes;
         ++i) {
        auto curr = nodes->at(i);
        std::istringstream nodeProps(line);

        unsigned long numNeighbors, neighborId;
        nodeProps >> numNeighbors;

        while (numNeighbors--) {
            nodeProps >> neighborId;
            auto neighbor = nodes->at(neighborId - 1);
            curr->neighbors.emplace_back(neighbor);
        }
    }
    return *nodes;
}

#include <sstream>
#include "InputParser.h"

InputParser::InputParser(std::ifstream& input) : input(input) {}

NodeList InputParser::parse() {
    std::string line;
    getline(input, line);
    std::istringstream listProps(line);

    // read # of nodes
    unsigned int numNodes;
    listProps >> numNodes;

    // create nodes
    NodeList nodes;
    for (unsigned int i = 1; i <= numNodes; ++i) {
        nodes.emplace_back(new Node(i));
    }

    // build adjacency list
    for (unsigned int i = 0;
         std::getline(input, line) && i < numNodes;
         ++i) {
        auto curr = nodes.at(i);
        std::istringstream nodeProps(line);

        unsigned int numNeighbors, neighborId;
        nodeProps >> numNeighbors;

        while (numNeighbors--) {
            nodeProps >> neighborId;
            auto neighbor = nodes.at(neighborId - 1);
            curr->edges.emplace_back(neighbor);
        }
    }
    return nodes;
}

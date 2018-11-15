#ifndef PROJECT3_INPUTPARSER_H
#define PROJECT3_INPUTPARSER_H


#include <fstream>
#include "Node.h"

class InputParser {
    std::ifstream& input;
public:
    explicit InputParser(std::ifstream& input);

    NodeList parse();
};


#endif //PROJECT3_INPUTPARSER_H

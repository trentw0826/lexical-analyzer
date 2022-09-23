#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
//        std::cout << "STRING.S0 has detected an \'" << std::endl;
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (input[index] != '\'' && input[index] != 0) {
//        std::cout << "STRING.S1 has detected an \'" << input[index] << "\' as non EOF char" << std::endl;
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\''){
//        std::cout << "STRING.S1 has detected a 2nd \'" << std::endl;
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == 0){
//        std::cout << "EOF reached while parsing string, undefined" << std::endl;
        this->type = TokenType::UNDEFINEDSTR;
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (input[index] == '\'') {
//        std::cout << "STRING has detected that the last \' was an escape" << std::endl;
        inputRead++;
        index++;
        S1(input);
    }
    else{
        inputRead++;
    }
//    std::cout << "STRING.S2 has finished a valid string" << std::endl;
}
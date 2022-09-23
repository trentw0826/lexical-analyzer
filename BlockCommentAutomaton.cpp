#include "BlockCommentAutomaton.h"

void BlockCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|' && input[index] != 0) {
        checkNewLine(input[index]);
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] != '|'){
        Serr();
    }
    else if(input[index] == 0){
        this->type = TokenType::UNDEFINEDCMT;
    }
}

void BlockCommentAutomaton::S2(const std::string& input) {
    if (input[index] != '|' && input[index] != 0) {
        checkNewLine(input[index]);
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '|'){
        checkNewLine(input[index]);
        inputRead++;
        index++;
        S3(input);
    }
    else if(input[index] == 0){
        this->type = TokenType::UNDEFINEDCMT;
    }
}

void BlockCommentAutomaton::S3(const std::string& input) {
    if (input[index] != '#' && input[index] != 0) {
        //Accept
    }
    else if (input[index] != '#'){
        Serr();
    }
    else if(input[index] == 0){
        this->type = TokenType::UNDEFINEDCMT;
    }
}
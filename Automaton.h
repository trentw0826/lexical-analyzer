#ifndef AUTOMATON_H
#define AUTOMATON_H
#include "Token.h"

class Automaton
{
protected:
    int inputRead = 0;
    int newLines = 0;
    int index = 0;
    TokenType type;

public:
    // Default constructor -- since we have a constructor that takes a parameter,
    //   the compiler will autogenerate a default constructor if not explicit.
    Automaton() : Automaton(TokenType::UNDEFINED) {}

    Automaton(TokenType type) { this->type = type; }

    virtual ~Automaton() = default;

    std::string getAutoType(){
        switch(type) {
            case TokenType::COLON:
                return "COLON";
            case TokenType::COLON_DASH:
                return "COLON_DASH";
            case TokenType::COMMA:
                return "COMMA";
            case TokenType::PERIOD:
                return "PERIOD";
            case TokenType::Q_MARK:
                return "Q_MARK";
            case TokenType::LEFT_PAREN:
                return "lEFT_PAREN";
            case TokenType::RIGHT_PAREN:
                return "RIGHT_PAREN";
            case TokenType::MULTIPLY:
                return "MULTIPLY";
            case TokenType::ADD:
                return "ADD";
            case TokenType::SCHEMES:
                return "SCHEMES";
            case TokenType::FACTS:
                return "FACTS";
            case TokenType::RULES:
                return "RULES";
            case TokenType::QUERIES:
                return "QUERIES";
            case TokenType::ID:
                return "ID";
            case TokenType::STRING:
                return "STRING";
            case TokenType::COMMENT:
                return "COMMENT";
            case TokenType::LINECOMMENT:
                return "COMMENT";
            case TokenType::BLOCKCOMMENT:
                return "COMMENT";
            case TokenType::UNDEFINED: //TODO: Improve efficiency of returning "UNDEFINED"
                return "UNDEFINED";
            case TokenType::UNDEFINEDSTR:
                return "UNDEFINED";
            case TokenType::UNDEFINEDCMT:
                return "UNDEFINED";
            case TokenType::END_OF_FILE:
                return "EOF";
            default:
                std::cerr << "Unknown Token Type\n";
                exit(1);
        }
    }

    // Start the automaton and return the number of characters read
    //   read == 0 indicates the input was rejected
    //   read  > 0 indicates the input was accepted
    int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }

    // Every subclass must define this method
    virtual void S0(const std::string& input) = 0;

    void Serr() {
        // Indicate the input was rejected
        inputRead = 0;
    }

    virtual Token* CreateToken(std::string input, int lineNumber) { return new Token(type, input, lineNumber); }

    int NewLinesRead() const { return newLines; }
};

#endif // AUTOMATON_H


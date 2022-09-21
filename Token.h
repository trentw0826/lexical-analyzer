#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END_OF_FILE
};

class Token
{
private:
    TokenType type;
    std::string description;
    int line;

public:
    Token(TokenType type, std::string description, int line);

    std::string typeToString(TokenType type){
        switch(type){
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
            case TokenType::UNDEFINED:
                return "UNDEFINED";
            case TokenType::END_OF_FILE:
                return "EOF";
            default:
                std::cerr << "Unknown Token Type\n";
                exit(1);
        }
    }

    std::string toString(){
        std::string typeString = typeToString(type);
        return ("(" + typeString + ",\"" + description + "\"," + std::to_string(line) + ")");
    }

    // TODO: add other needed methods
};

#endif // TOKEN_H


#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    //Verify command line has 2 arguments, an executable and .txt input
    if (argc < 2){
        std::cerr << "2 arguments required!\n";
    }

    //Verify that given .txt is usable
    std::string inputText;
    std::ifstream inputFile;
    inputFile.open(argv[1]);
    if (!inputFile) {
        std::cerr << "Input file " << argv[1] << " could not be opened\n";
        return 1;
    }

    //Convert .txt into an input string
    std::stringstream bufferStream;
    bufferStream << inputFile.rdbuf();
    inputText = bufferStream.str();

    std::cout << "Input String: \"" << inputText << "\"\n";

//    lexer->Run(inputText);

    delete lexer;

    inputFile.close();
    return 0;
}
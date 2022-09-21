#include <cctype>
#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    while(!automata.empty()) delete automata.back(), automata.pop_back();
    while(!tokens.empty()) delete tokens.back(), tokens.pop_back();


}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {

    int lineNumber = 1;
    int iteration = 0;
    while (!input.empty()){
        int maxRead = 0;

        iteration++;
        std::cout << "    -=-<Iteration #" << iteration << ">-=-" << std::endl;
        std::cout << "Current String: \"" << input << "\"" << std::endl;

        Automaton* maxAutomaton = automata.at(0);

        while(std::isspace(input.front())){
            if(input.front() == '\n'){
                std::cout << "Newline detected, incrementing lineNumber" << std::endl;
                lineNumber++;
            }
            std::cout << "Erasing leading whitespace" << std::endl;
            input.erase(0,1);
            std::cout << "Updated String: \"" << input << "\"" << std::endl;
        }
        if(input.empty()){
            std::cout << "Updated String is empty, breaking loop" << std::endl;
            break;
        }

        for (Automaton* currAutomaton : automata){
            int inputRead = currAutomaton->Start(input);
            if (inputRead > maxRead){
                std::cout << "Updating maxRead to " << std::to_string(inputRead) << std::endl;
                std::cout << "Updating maxAutomaton to " << currAutomaton->getAutoType() << " type" << std::endl;
                maxRead = inputRead;
                maxAutomaton = currAutomaton;
            }
        }
        if (maxRead > 0){
            std::cout << "<=> Creating new " << maxAutomaton->getAutoType() << " token <=>" << std::endl;
            Token* newToken = maxAutomaton->CreateToken(input, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        else{ //No token accepted, make undefined token
            std::cout << "Creating an undefined Token" << std::endl;
            maxRead = 1;
            //TODO:Create undefined token class and assign Token* newToken = UndefinedAutomaton->CreateToken(input, lineNumber);
            //TODO:Then add newToken to 'tokens' vector
        }
        std::cout << "Erasing " << std::to_string(maxRead) << " characters from current input" << std::endl;
        input.erase(input.begin(), input.begin() + maxRead);
    }
    std::cout << "EOF reached" << std::endl;
    //TODO:Add EOF token here


    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
}

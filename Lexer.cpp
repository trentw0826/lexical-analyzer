#include <cctype>

#include "Lexer.h"
#include "ColonAutomaton.h"
#include "AddAutomaton.h"
#include "CommaAutomaton.h"
#include "Left_ParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "ColonDashAutomaton.h"
#include "End_Of_FileAutomaton.h"
#include "UndefinedAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "LineCommentAutomaton.h"
#include "BlockCommentAutomaton.h"

//TODO: Finish including all automaton classes

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    while(!automata.empty()) delete automata.back(), automata.pop_back();
    while(!tokens.empty()) delete tokens.back(), tokens.pop_back();
}

void Lexer::CreateAutomata() {
    automata.push_back(new AddAutomaton());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new Left_ParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton());
    automata.push_back(new Right_ParenAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new End_Of_FileAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new BlockCommentAutomaton());
    automata.push_back(new LineCommentAutomaton());

    automata.push_back(new UndefinedAutomaton());

    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    int iteration = 0;
    while (!input.empty()) {
        int maxRead = 0;

        iteration++;

        Automaton *maxAutomaton = automata.at(0);

        while (std::isspace(input.front())) {
            if (input.front() == '\n') {
                lineNumber++;
            }
            input.erase(0, 1);
        }
        if (input.empty()) {
            break;
        }

        for (Automaton *currAutomaton: automata) {
            int inputRead = currAutomaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = currAutomaton;
            }
        }

        if (maxRead > 0) {
            Token *newToken = maxAutomaton->CreateToken((input.substr(0, maxRead)), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        } else { //No token accepted, make undefined token
            maxRead = 1;
            Automaton* UndefAutomaton = new UndefinedAutomaton();
            Token* newToken = UndefAutomaton->CreateToken(input, lineNumber);
            tokens.push_back(newToken);
        }
        input.erase(input.begin(), input.begin() + maxRead);
    }
    Automaton* EOFAutomaton = new End_Of_FileAutomaton();
    Token* newToken = EOFAutomaton->CreateToken(input, lineNumber);
    tokens.push_back(newToken);
}

void Lexer::printTokens() {
    unsigned long numTokens = tokens.size();
    for (Token* currToken : tokens){
        std::cout << currToken->toString() << std::endl;
    }
    std::cout << "Total Tokens = " << numTokens;
}
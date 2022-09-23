#include <cctype>

#include "Lexer.h"
#include "AutomataHeaders/ColonAutomaton.h"
#include "AutomataHeaders/AddAutomaton.h"
#include "AutomataHeaders/CommaAutomaton.h"
#include "AutomataHeaders/Left_ParenAutomaton.h"
#include "AutomataHeaders/MultiplyAutomaton.h"
#include "AutomataHeaders/PeriodAutomaton.h"
#include "AutomataHeaders/Q_MarkAutomaton.h"
#include "AutomataHeaders/Right_ParenAutomaton.h"
#include "AutomataHeaders/ColonDashAutomaton.h"
#include "AutomataHeaders/End_Of_FileAutomaton.h"
#include "AutomataHeaders/UndefinedAutomaton.h"
#include "AutomataHeaders/SchemesAutomaton.h"
#include "AutomataHeaders/FactsAutomaton.h"
#include "AutomataHeaders/RulesAutomaton.h"
#include "AutomataHeaders/QueriesAutomaton.h"
#include "AutomataHeaders/IDAutomaton.h"
#include "AutomataHeaders/StringAutomaton.h"
#include "AutomataHeaders/LineCommentAutomaton.h"
#include "AutomataHeaders/BlockCommentAutomaton.h"

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
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    while (!input.empty()) {
        int maxRead = 0;
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
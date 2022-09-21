#ifndef END_OF_FILEAUTOMATON_H
#define END_OF_FILEAUTOMATON_H

#include "Automaton.h"

class End_Of_FileAutomaton : public Automaton
{
public:
    End_Of_FileAutomaton() : Automaton(TokenType::END_OF_FILE) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // END_OF_FILEAUTOMATON_H
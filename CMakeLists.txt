cmake_minimum_required(VERSION 3.16.3)
project(Project236)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project236
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h
        AddAutomaton.cpp
        AddAutomaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        Left_ParenAutomaton.cpp
        Left_ParenAutomaton.h
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        Q_MarkAutomaton.cpp
        Q_MarkAutomaton.h
        Right_ParenAutomaton.cpp
        Right_ParenAutomaton.h End_Of_FileAutomaton.h End_Of_FileAutomaton.cpp UndefinedAutomaton.h UndefinedAutomaton.cpp SchemesAutomaton.h SchemesAutomaton.cpp)

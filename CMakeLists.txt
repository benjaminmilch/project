cmake_minimum_required(VERSION 3.12)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp Command.h OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.cpp ConnectCommand.h ValidateNumbers.cpp ValidateNumbers.h Expression.h BinaryExpression.h BinaryExpression.cpp Plus.cpp Plus.h LoopCommand.cpp LoopCommand.h Parser.cpp Parser.h Div.cpp Div.h Minus.cpp Minus.h Mul.cpp Mul.h Number.cpp Number.h Client.cpp Client.h Server.h Server.cpp Lexer.h Lexer.cpp)
cmake_minimum_required(VERSION 3.21)
project(LestaTestMiniGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(LestaTestMiniGame main.cpp MiniGameModel.cpp MiniGameModel.h MiniGameView.cpp MiniGameView.h)

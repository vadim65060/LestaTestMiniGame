//
// Created by vadim on 23.10.2022.
//

#ifndef LESTATEST_MINIGAMEVIEW_H
#define LESTATEST_MINIGAMEVIEW_H

#include <iostream>
#include "MiniGameModel.h"

class MiniGameView {
public:
    MiniGameView() = default;

    void StartGame() {
        do {
            PrintArea();
            std::cout << "first point ";
            std::pair<int, int> input1 = ReadIJ(_gameModel.GetArea());
            PrintArea(&input1);
            std::cout << "second point ";
            std::pair<int, int> input2 = ReadIJ(_gameModel.GetArea());
            if (!_gameModel.SwapPoints(input1, input2)) {
                std::cout << "incorrect points\n";
            }
        } while (!_gameModel.GameWin());
        PrintArea();
        std::cout<<"You win!";
    }

private:
    MiniGameModel _gameModel;

    std::pair<int, int> ReadIJ(const std::vector<std::vector<char>> &area);

    bool InRange(const int &n, const int a, const int b) {
        return n >= a && n <= b;
    }

    void PrintArea(std::pair<int, int> *selectedPoint = nullptr);
};


#endif //LESTATEST_MINIGAMEVIEW_H

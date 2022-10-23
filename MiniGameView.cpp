//
// Created by vadim on 23.10.2022.
//

#include "MiniGameView.h"
#include <cassert>

std::pair<int, int> MiniGameView::ReadIJ(const std::vector<std::vector<char>> &area) {
    std::pair<int, int> input;
    std::cout << "i j:";
    assert(std::cin >> input.first >> input.second);
    if (InRange(input.first, 0, _gameModel.AreaSize() - 1) &&
        InRange(input.second, 0, _gameModel.AreaSize() - 1) && area[input.first][input.second] != '#') {
        return input;
    }
    std::cout << "incorrect input\n";
    return ReadIJ(area);
}

void MiniGameView::PrintArea(std::pair<int, int> *selectedPoint) {
    system("cls");
    std::cout << "i ";
    for (int i = 0; i < _gameModel.TypesCount(); ++i) {
        std::cout << _gameModel.TypeChar()[i] << "   ";
    }
    std::cout << "\n";

    for (int i = 0; i < _gameModel.AreaSize(); ++i) {
        std::cout << i << ' ';
        for (int j = 0; j < _gameModel.AreaSize(); ++j) {
            if (selectedPoint != nullptr && i == selectedPoint->first && j == selectedPoint->second &&
                _gameModel.SelectedTypeChar().find(_gameModel.GetArea()[i][j]) != _gameModel.SelectedTypeChar().end())
                std::cout << _gameModel.SelectedTypeChar().at(_gameModel.GetArea()[i][j]) << ' ';
            else
                std::cout << _gameModel.GetArea()[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "j>";
    for (int i = 0; i < _gameModel.AreaSize(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << "\n";
}

//
// Created by vadim on 23.10.2022.
//

#ifndef LESTATEST_MINIGAMEMODEL_H
#define LESTATEST_MINIGAMEMODEL_H

#include <vector>
#include <map>
#include <ctime>

class MiniGameModel {
public:
    MiniGameModel() {
        GenerateArea();
    }

    [[nodiscard]] bool GameWin() const { return _gameWin; }

    int AreaSize() { return _areaSize; }

    int TypesCount() { return _typesCount; };

    const char *TypeChar() { return _typeChar; }

    const std::map<char, char> &SelectedTypeChar() { return _selectedTypeChar; }

    const std::vector<std::vector<char>> &GetArea() { return area; }

    bool SwapPoints(std::pair<int, int> &point1, std::pair<int, int> &point2);

private:
    static const int _areaSize = 5;
    static const int _typesCount = 3;
    const char _typeChar[_typesCount] = {'r', 'g', 'b'};
    const std::map<char, char> _selectedTypeChar = {{_typeChar[0], 'R'},
                                                    {_typeChar[1], 'G'},
                                                    {_typeChar[2], 'B'}};
    bool _gameWin = false;
    std::vector<std::vector<char>> area;

    void GenerateArea();

    void CheckWin() {
        for (int i = 0; i < _areaSize; ++i) {
            for (int j = 0; j < _areaSize; j += 2) {
                if (area[i][j] != _typeChar[j / 2]) {
                    _gameWin = false;
                    return;
                }
            }
        }
        _gameWin = true;
    }

};


#endif //LESTATEST_MINIGAMEMODEL_H

//
// Created by vadim on 23.10.2022.
//

#include "MiniGameModel.h"

void MiniGameModel::GenerateArea() {
    area.resize(_areaSize);
    std::vector<int> countOfType(_typesCount);
    srand(time(nullptr));
    for (int i = 0; i < _areaSize; ++i) {
        for (int j = 0; j < _areaSize; ++j)
            area[i].push_back('.');
    }
    for (int i = 0; i < _areaSize; ++i) {
        for (int j = 0; j < _areaSize; j += 2) {
            int type = rand() % _typesCount;
            while (countOfType[type] >= _areaSize) {
                type = (type + 1) % _typesCount;
            }
            countOfType[type]++;
            area[i][j] = _typeChar[type];
        }
        if (!(i & 1))
            for (int j = 1; j < _areaSize; j += 2) {
                area[i][j] = '#';
            }
    }
}

bool MiniGameModel::SwapPoints(std::pair<int, int> &point1, std::pair<int, int> &point2) {
    if (abs(point1.first - point2.first) + abs(point1.second - point2.second) > 1 ||
        (area[point1.first][point1.second] != '.' && area[point2.first][point2.second] != '.'))
        return false;

    std::swap(area[point1.first][point1.second], area[point2.first][point2.second]);
    CheckWin();
    return true;
}

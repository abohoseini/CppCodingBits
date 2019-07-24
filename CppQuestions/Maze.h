// The Maze
// Given a 2d vector Maze, mouse position and cheese position, solve maze.
#pragma once

#include "Utils.h"
#include <vector>

class Maze
{

public:
    Maze(std::vector<std::vector<bool>>& board, coordinate mousePos, coordinate cheesePos);
    ~Maze();
    bool FindCheese(bool iter = true);
    void PrintBoardAndPath();

private:
    int m_cols;
    int m_rows;
    coordinate m_mousePosition;
    coordinate m_cheesePosition;
    std::vector<std::vector<bool>> m_board;
    std::vector<std::vector<bool>> m_visited;

    bool FindCheeseRec(std::vector<std::vector<bool>>& visited, coordinate mousePosition);
    bool FindCheeseIter();
};

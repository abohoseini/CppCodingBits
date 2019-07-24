#include <iostream>
#include <stack>
#include "Maze.h"

Maze::Maze(std::vector<std::vector<bool>>& board, coordinate mousePos, coordinate cheesePos)
{
    m_cols = board[0].size();
    m_rows = board.size();
    m_mousePosition = mousePos;
    m_cheesePosition = cheesePos;
    m_board = board;
}

bool Maze::FindCheese(bool iter )
{
    if (m_board[m_mousePosition.RowNumber][m_mousePosition.ColNumber] == true)
        return false;

    if (m_board[m_cheesePosition.RowNumber][m_cheesePosition.ColNumber] == true)
        return false;

    for (int i = 0; i < m_rows; i++)
    {
        m_visited.push_back(std::vector<bool>());
        for (int j = 0; j < m_cols; j++)
        {
            m_visited[i].push_back(false);
        }
    }

    return (iter) ? FindCheeseIter() : FindCheeseRec(m_visited, m_mousePosition);
}

Maze::~Maze()
{
}

bool Maze::FindCheeseRec(std::vector<std::vector<bool>>& visited, coordinate mousePosition)
{
    if (mousePosition == m_cheesePosition)
        return true;

    visited[mousePosition.RowNumber][mousePosition.ColNumber] = true;

    // Move UP
    if (mousePosition.RowNumber > 0 &&
        !m_board[mousePosition.RowNumber - 1][mousePosition.ColNumber] &&
        !visited[mousePosition.RowNumber - 1][mousePosition.ColNumber] &&
        FindCheeseRec(visited, coordinate{ mousePosition.RowNumber - 1, mousePosition.ColNumber }))
        return true;

    // Move Down
    if (mousePosition.RowNumber < m_rows - 1 &&
        !m_board[mousePosition.RowNumber + 1][mousePosition.ColNumber] &&
        !visited[mousePosition.RowNumber + 1][mousePosition.ColNumber] &&
        FindCheeseRec(visited, coordinate{ mousePosition.RowNumber + 1, mousePosition.ColNumber }))
        return true;

    // Move Left
    if (mousePosition.ColNumber > 0 &&
        !m_board[mousePosition.RowNumber][mousePosition.ColNumber - 1] &&
        !visited[mousePosition.RowNumber][mousePosition.ColNumber - 1] &&
        FindCheeseRec(visited, coordinate{ mousePosition.RowNumber, mousePosition.ColNumber - 1 }))
        return true;

    // Move Right
    if (mousePosition.ColNumber < m_cols - 1 &&
        !m_board[mousePosition.RowNumber][mousePosition.ColNumber + 1] &&
        !visited[mousePosition.RowNumber][mousePosition.ColNumber + 1] &&
        FindCheeseRec(visited, coordinate{ mousePosition.RowNumber, mousePosition.ColNumber + 1 }))
        return true;

    visited[mousePosition.RowNumber][mousePosition.ColNumber] = false;
    return false;
}

bool  Maze::FindCheeseIter()
{
    std::stack<coordinate> myStack;
    myStack.push(m_mousePosition);

    while (!myStack.empty())
    {
        // Pop a node from stack
        auto currentNode = myStack.top();
        myStack.pop();

        if (!m_visited[currentNode.RowNumber][currentNode.ColNumber])
        {
            if (currentNode == m_cheesePosition)
            {
                return true;
            }

            m_visited[currentNode.RowNumber][currentNode.ColNumber] = true;
        }

        // Move UP
        if (currentNode.RowNumber > 0 &&
            !m_board[currentNode.RowNumber - 1][currentNode.ColNumber] &&
            !m_visited[currentNode.RowNumber - 1][currentNode.ColNumber])
            myStack.push(coordinate{ currentNode.RowNumber - 1, currentNode.ColNumber });

        // Move Down
        if (currentNode.RowNumber < m_rows - 1 &&
            !m_board[currentNode.RowNumber + 1][currentNode.ColNumber] &&
            !m_visited[currentNode.RowNumber + 1][currentNode.ColNumber])
            myStack.push(coordinate{ currentNode.RowNumber + 1, currentNode.ColNumber });


        // Move Left
        if (currentNode.ColNumber > 0 &&
            !m_board[currentNode.RowNumber][currentNode.ColNumber - 1] &&
            !m_visited[currentNode.RowNumber][currentNode.ColNumber - 1])
            myStack.push(coordinate{ currentNode.RowNumber, currentNode.ColNumber - 1 });

        // Move Right
        if (currentNode.ColNumber < m_cols - 1 &&
            !m_board[currentNode.RowNumber][currentNode.ColNumber + 1] &&
            !m_visited[currentNode.RowNumber][currentNode.ColNumber + 1])
            myStack.push(coordinate{ currentNode.RowNumber, currentNode.ColNumber + 1 });
    }
    return false;
}

void Maze::PrintBoardAndPath()
{
    for (int i = 0; i < m_board.size(); i++)
    {
        for (int j = 0; j < m_board[0].size(); j++)
        {
            if (m_board[i][j])
            {
                std::cout << " # ";
            }
            else
            {
                if (m_mousePosition.RowNumber == i && m_mousePosition.ColNumber == j)
                    std::cout << " M ";
                else if (m_cheesePosition.RowNumber == i && m_cheesePosition.ColNumber == j)
                    std::cout << " C ";
                else if (m_visited[i][j])
                    std::cout << " * ";
                else
                    std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
}

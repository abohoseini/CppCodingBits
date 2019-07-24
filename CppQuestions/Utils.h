
#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

// Definition for singly-linked list.
template <typename T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode(T x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct coordinate
{
    int ColNumber;
    int RowNumber;

    coordinate(int  rowNum, int colNum) : ColNumber(colNum), RowNumber(rowNum) {}
    coordinate() = default;

    inline bool operator == (const coordinate &b) const
    {
        return ((b.ColNumber == ColNumber) &&
            (b.RowNumber == RowNumber));
    }
};

class Utils
{
public:
  template <typename T>
  static void PrintVector(std::vector<T> vect);

  template <typename T>
  static void PrintLinkedList(ListNode<T>* list);

  template <typename T>
  static void Swap(T &a, T &b);

  template <typename T>
  static std::string VectorToString(std::vector<T> vect);
};

#endif // UTILS_H
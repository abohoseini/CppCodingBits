#include "Utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>  
using namespace std;

template <typename T>
void Utils::PrintVector(vector<T> vect)
{
    cout << '[';

    for (unsigned int i = 0; i < vect.size() - 1; i++)
    {
        cout << vect[i] << ", ";
    }

    if (vect.size() > 0)
    {
        cout << vect[vect.size() - 1];
    }

    cout << ']' << endl;
}

template <typename T>
static void Utils::Swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
static void Utils::PrintLinkedList(ListNode<T>* list)
{ 
    if (!list)
        cout << "NULL";

    auto templist = list;
    while (templist)
    {
        cout << templist->val;
        if (templist->next)
        {
            cout << "->";
        }
        templist = templist->next;
    }
    cout << endl;
}

template <typename T>
static std::string Utils::VectorToString(std::vector<T> vect)
{
	std::stringstream ss;
	ss << "[";
	
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		ss << vect[i];

		if (i < vect.size() - 1)
			ss << ", ";
	}

	ss << "]";

	return ss.str();
}

// Explicit template instantiation
template void Utils::PrintLinkedList<int>(ListNode<int>*);
template void Utils::PrintVector<int>(vector<int>);
template void Utils::PrintVector<char>(vector<char>);
template void Utils::Swap<int>(int &, int &);
template void Utils::Swap<char>(char &, char &);
template std::string Utils::VectorToString<int>(vector<int>);
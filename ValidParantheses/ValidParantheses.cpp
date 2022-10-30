// ValidParantheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string str) {

    stack<char> paranthesis;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            paranthesis.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (paranthesis.empty()) {
                return false;
            }
            else if (str[i] == ')' && paranthesis.top() == '(')
                paranthesis.pop();
            else if (str[i] == '}' && paranthesis.top() == '{')
                paranthesis.pop();
            else if (str[i] == ']' && paranthesis.top() == '[')
                paranthesis.pop();
            else
                return false;
            //SAME SOLUTION REVERSED
            /*
            else if (str[i] == ')' && paranthesis.top() != '(')
                return false;
            else if (str[i] == '}' && paranthesis.top() != '{')
                return false;
            else if (str[i] == ']' && paranthesis.top() != '[')
                return false;
            else
                paranthesis.pop();
                */
        }
    }
    if (paranthesis.empty()) {
        return true;
    }
    else
        return false;
}

int main()
{
    string str = "{[]([])}";

    cout << isValid(str);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

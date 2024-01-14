// Valid Parantheses

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {

            st.push(c);
        }
        else
        {

            if (st.empty())
            {
                return false;
            }

            char topElement = st.top();
            st.pop();

            if ((c == ')' && topElement != '(') ||
                (c == ']' && topElement != '[') ||
                (c == '}' && topElement != '{'))
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    string input = "{[()]}";
    bool result = isValid(input);

    if (result)
    {
        cout << "The input string is valid." << endl;
    }
    else
    {
        cout << "The input string is not valid." << endl;
    }

    return 0;
}

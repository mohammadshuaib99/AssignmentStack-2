
// Question 3 } Final Prices a Special Discount in a Shop 

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> finalPrices(const vector<int> &prices)
{
    vector<int> result(prices.size(), 0);
    stack<int> st;

    for (int i = 0; i < prices.size(); ++i)
    {
        while (!st.empty() && prices[st.top()] >= prices[i])
        {

            result[st.top()] = prices[st.top()] - prices[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main()
{

    vector<int> prices = {8, 4, 6, 2, 3};

    vector<int> result = finalPrices(prices);

    cout << "[";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << std::endl;

    return 0;
}


// output is [4, 2, 4, 0, 0]
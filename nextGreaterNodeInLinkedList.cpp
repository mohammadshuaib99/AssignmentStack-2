// next greater Node in a linkedlist

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

class Node
{
public:
    int index;
    int value;
    Node(int idx, int val)
    {
        this->index = idx;
        this->value = val;
    }
};

vector<int> nextGreaterNodes(ListNode *head)
{
    vector<int> result;
    stack<Node> st;

    ListNode *current = head;
    int index = 0;

    while (current)
    {
        while (!st.empty() && st.top().value <= current->val)
        {
            st.pop();
        }

        if (st.empty())
        {
            result.insert(result.begin(), 0);
        }
        else
        {
            result.insert(result.begin(), st.top().value);
        }

        st.push(Node(index, current->val));

        current = current->next;
        ++index;
    }

    return result;
}

int main()
{
    // Example usage
    ListNode *head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    vector<int> result = nextGreaterNodes(head);

    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

// output is : -[ 7, 4, 7, 0, 0 ]
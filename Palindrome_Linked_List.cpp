#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
bool palindrome(vector<int> arr, int n)
{
    int flag = 0;

    for (int i = 0; i <= n / 2 && n != 0; i++)
    {

        if (arr[i] != arr[n - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        return false;
    return true;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    vector<int> nodes;
    LinkedListNode<int> *p = head;
    while (p)
    {
        nodes.push_back(p->data);
        p = p->next;
    }

    return palindrome(nodes, nodes.size());
}
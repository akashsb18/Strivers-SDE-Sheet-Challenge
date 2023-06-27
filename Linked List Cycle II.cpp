/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/
#include <bits/stdc++.h>

Node *firstNode(Node *head)
{
    unordered_map<Node *, int> mp;
    Node *p = head;
    while (p)
    {
        mp[p]++;
        if (mp[p] > 1)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
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
Node *findIntersection(Node *headA, Node *headB)
{
    unordered_map<Node *, int> mp;
    while (headA)
    {
        mp[headA]++;
        headA = headA->next;
    }
    while (headB)
    {
        mp[headB]++;
        if (mp[headB] > 1)
        {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    vector<int> nodes;
    Node *p = head;
    while (p)
    {
        nodes.push_back(p->data);
        p = p->next;
    }
    int n = nodes.size();
    if (n == 0)
    {
        return NULL;
    }
    int length = n - k % n;
    vector<int> finalNodes;

    for (int i = length; i < n; i++)
    {
        finalNodes.push_back(nodes[i]);
    }

    for (int i = 0; i < length; i++)
    {
        finalNodes.push_back(nodes[i]);
    }

    Node *dummy = new Node(-1);
    Node *current = dummy;

    for (auto it : finalNodes)
    {
        current->next = new Node(it);
        current = current->next;
    }

    return dummy->next;
}
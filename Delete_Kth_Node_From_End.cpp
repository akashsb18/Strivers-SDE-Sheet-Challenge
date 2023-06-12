/*
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
*/

Node *removeKthNode(Node *head, int n)
{
    Node *p = head, *q = head;
    while (n--)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        return head->next;
    }
    while (p->next)
    {
        p = p->next;
        q = q->next;
    }
    Node *Del = q->next;
    q->next = q->next->next;
    delete Del;

    return head;
}

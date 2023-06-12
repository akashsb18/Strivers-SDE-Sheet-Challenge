
Node *findMiddle(Node *head)
{
    int length = 0;
    Node *p = head;
    while (p)
    {
        length++;
        p = p->next;
    }
    int middle = length / 2;

    while (head and middle != 0)
    {
        head = head->next;
        middle--;
    }
    return head;
}

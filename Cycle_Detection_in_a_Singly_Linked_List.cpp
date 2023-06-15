
bool detectCycle(Node *head)
{
    Node *p = head, *q = head;
    while (q and q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
        {
            return true;
        }
    }
    return false;
}
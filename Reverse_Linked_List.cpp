
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *p = NULL, *q = NULL;
    while (head != 0)
    {
        p = q;
        q = head;
        head = head->next;
        q->next = p;
    }
    head = q;
    return head;
}


// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if(!head)
        return head;
    SinglyLinkedListNode* ex=nullptr;
    SinglyLinkedListNode* crnt=head;
    SinglyLinkedListNode* next;
    while(crnt->next)
    {
        next=crnt->next;
        crnt->next=ex;
        ex=crnt;
        crnt=next;
        if(!crnt->next)
        {
            crnt->next=ex;
            break;
        }
    }
    return crnt;
}




// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    int i=0;
    SinglyLinkedListNode* crnt=head;
    if(position==0)
        return head->next;
    while(i<position-1)
    {
        crnt=crnt->next;
        i++;
    }
    crnt->next=crnt->next->next;
    return head;
}




// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    int i=0;
    SinglyLinkedListNode* crnt=head;
    SinglyLinkedListNode* new_node=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    new_node->data=data;
    while(crnt->next && i<position-1)
    {
        crnt=crnt->next;
        i++;
    }
    new_node->next=crnt->next;
    crnt->next=new_node;
    return head;
}


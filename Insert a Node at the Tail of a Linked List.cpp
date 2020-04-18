

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* new_Node=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    new_Node->data=data;new_Node->next=nullptr;
    if(head==nullptr)
    {
        head=new_Node;
        return head;
    }
    SinglyLinkedListNode* rtr=head;
    while(rtr->next!=nullptr)
    {
        rtr=rtr->next;
    }
    rtr->next = new_Node;
    return head;
}


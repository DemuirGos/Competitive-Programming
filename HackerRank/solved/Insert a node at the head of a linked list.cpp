

// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* new_node=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    new_node->data=data;new_node->next=nullptr;
    if(llist==nullptr)
    {
        llist= new_node;
        return new_node;
    }
    new_node->next=llist;
    return new_node;
}


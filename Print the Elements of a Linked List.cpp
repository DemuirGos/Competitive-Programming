

// Complete the printLinkedList function below.

void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* curr= head;
    while(1)
    {
        cout << curr->data << endl;
        if(curr->next==nullptr) break;
        curr=curr->next;
    }
}

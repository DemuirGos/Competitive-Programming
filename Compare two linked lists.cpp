

// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1==NULL && head2==NULL) return 1;
    else if(head1==NULL || head2==NULL) return 0;
    else if(head1->data==head2->data) return compare_lists(head1->next,head2->next);
    else return 0;
}


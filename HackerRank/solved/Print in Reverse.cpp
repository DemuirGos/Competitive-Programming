

// Complete the reversePrint function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void reversePrint(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* crnt=head;
    vector<int> v;v.push_back(crnt->data);
    while(crnt->next) 
    { 
        crnt=crnt->next;
        v.push_back(crnt->data);
    }
    for(int i=0;i<v.size();i++)
     cout << v[v.size()-i-1] << endl;
}


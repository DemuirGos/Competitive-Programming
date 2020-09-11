void io(Node* root,vector<int>& v)
{
    if(root!=NULL)
        {io(root->left,v);
        v.push_back(root->data);
        io(root->right,v);}
}
bool checkBST(Node* root) {
    vector<int> v;
    io(root,v);
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]>v[i+1] || v[i]==v[i+1]) return 0;
    }
    return 1;
}
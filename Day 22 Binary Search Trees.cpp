
        int height=0;
		int Height(Node* root){
          if(root==NULL){
              return 0;
          }
          else{
              return 1+max(Height(root->right),Height(root->left));
          }
        }
        int getHeight(Node* root){
          return Height(root)-1;
        }


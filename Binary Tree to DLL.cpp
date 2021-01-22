//Binary Tree to DLL 

void inorder(Node *root,Node *&head,Node *&tail){
    if(root){
        inorder(root->left,head,tail);
        if(head==NULL){
            Node *temp=newNode(root->data);
            head=temp;
            tail=temp;
        }
        else{
            Node *temp=newNode(root->data);
            temp->left=tail;
            tail->right=temp;
            tail=tail->right;
        }
        inorder(root->right,head,tail);
    }
}
Node * bToDLL(Node *root)
{
    // your code here
    Node *head=NULL;
    Node *tail=NULL;
    inorder(root,head,tail);
    return head;
}


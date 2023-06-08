void findRange(Node* root, int low, int high , int &count){
        if(root==NULL) return;
        if(root->data >= low && root->data <= high) count+=root->count;
        if(root->data < low) findRange(root->right,low,high,count);
        else if(root->data > high) findRange(root->left,low,high,count);  
        else {
            findRange(root->right,low,high,count);
            findRange(root->left,low,high,count); 
        }
    }
int getCount(Node *root, int l, int h)
{
        int count=0;
        findRange(root,l,h,count);
        return count;  
}

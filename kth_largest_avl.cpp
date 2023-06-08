/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void inOrd(Node *root,int &k,int &elem){
        if(root==NULL) return;
        
        inOrd(root->right,k,elem);
        
        k=k-root->count;
        if(k==0) elem=root->data;
        
        inOrd(root->left,k,elem);
    }
    int kthLargest(Node *root, int k)
    {
        int elem;
        inOrd(root,k,elem);
        return elem;
    }
};
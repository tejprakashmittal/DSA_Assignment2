/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

// int hit(Node *nod){
//     if(nod==NULL) return 0;
//     return nod->height;
// }

// Node* RR(Node* root){
//     Node *temp=root->right;
//     root->right=temp->left;
//     temp->left=root;
    
//     root->height=max(hit(root->left),hit(root->right))+1;
//     temp->height=max(hit(temp->left),hit(temp->right))+1;
    
//     return temp;
// }

// Node* LL(Node* root){
//     Node *temp=root->left;
//     root->left=temp->right;
//     temp->right=root;
    
//     root->height=max(hit(root->left),hit(root->right))+1;
//     temp->height=max(hit(temp->left),hit(temp->right))+1;
    
//     return temp;
// }

// Node* predec(Node* root){
//         if(root->left==NULL) return NULL;
        
//         Node *temp=root->left,*temp1=temp;
        
//         while(temp->right!=NULL){
//             temp1=temp;
//             temp=temp->right;
//         }
//         if(temp->left!=NULL)
//             temp1->right=NULL;
//         else temp1->right=temp->left;
//         if(temp!=root->left) temp->left=root->left;
//         temp->right=root->right;
//         root->left=NULL;root->right=NULL;
        
//         temp->height=1 + max(hit(temp->left),hit(temp->right));
        
//         int bf=hit(temp->left)-hit(temp->right);
        
//         if(bf > 1){
//             int bf_left=hit(temp->left->left)-hit(temp->left->right);
//             if(bf_left >= 0) return LL(temp);
//             else {
//                 root->left=RR(temp->left);
//                 return LL(temp);
//             }
//         }
        
//         else if(bf < -1){
//             int bf_right=hit(temp->right->left)-hit(temp->right->right);
//             if(bf_right <= 0) return RR(temp);
//             else {
//                 root->right=LL(temp->right);
//                 return RR(temp);
//             }
//         }
        
//         return temp;
//     }
    
    Node* notBoth(Node* root){
        Node *temp=NULL;
        if(root->left==NULL) temp=root->right;
        else temp=root->left;
        
        return temp;
    }
    
    Node* success(Node* root){
        Node* temp = root;
            while (temp->left != NULL)
                temp = temp->left;
         
            return temp;
    }
void dataCopy(Node *root,Node *temp){
        root->val=temp->val;
        root->height=temp->height;
        root->count=trmp->count;
    }

Node* findAndDel(Node* root, int key){
        if(root==NULL) return root;
        if(root->val==key) {
            if(root->right==NULL || root->left==NULL) {
                if( (root->left == NULL) || (root->right == NULL) ) root=notBoth(root);
            }
            else
            {
                Node* temp=success(root->right);
                dataCopy(root,temp);
                root->right=findAndDel(root->right,temp->val);
            }
            if(root==NULL) return root;
        }
        if(root->val > key) root->left=findAndDel(root->left,key);
        else root->right = findAndDel(root->right,key);
        
        root->height=1 + max(hit(root->left),hit(root->right));
        
        int bf=hit(root->left)-hit(root->right);
        
        if(bf > 1){
            int bf_left=hit(root->left->left)-hit(root->left->right);
            if(bf_left >= 0) return LL(root);
            else {
                root->left=RR(root->left);
                return LL(root);
            }
        }
        
        else if(bf < -1){
            int bf_right=hit(root->right->left)-hit(root->right->right);
            if(bf_right <= 0) return RR(root);
            else {
                root->right=LL(root->right);
                return RR(root);
            }
        }
        
        return root;
}

Node* deleteNode(Node* root, int val)
{
    if(root==NULL) return NULL;
        return findAndDel(root,val);
}
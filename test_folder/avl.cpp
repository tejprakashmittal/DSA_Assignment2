#include<iostream>
#include <functional>
using namespace std;
template <class T> 
struct Node
    {
        T val;
        int count;
        struct Node<T>* left;
        struct Node<T>* right;
        int height;
    };
template <class T> 
class Avl{
    public:
    int hit(Node<T> *nod){
        if(nod==NULL) return 0;
        return nod->height;
    }

    bool isLess(int x,int y){
       return x<y;
    }
    bool isLess(float x,float y){
       return x<y;
    }
    bool isLess(double x,double y){
       return x<y;
    }
    bool isLess(string str1,string str2){
       int n1 = str1.length(), n2 = str2.length();
 
        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;
    
        for (int i = 0; i < n1; i++)
            if (str1[i] < str2[i])
                return true;
            else if (str1[i] > str2[i])
                return false;
    
        return false;
    }

    bool isGreater(int x,int y){
       return x>y;
    }
    bool isGreater(float x,float y){
       return x>y;
    }
    bool isGreater(double x,double y){
       return x>y;
    }
    bool isGreater(string str1,string str2){
       int n1 = str1.length(), n2 = str2.length();
 
        if (n1 > n2)
            return true;
        if (n2 > n1)
            return false;
    
        for (int i = 0; i < n1; i++)
            if (str1[i] > str2[i])
                return true;
            else if (str1[i] < str2[i])
                return false;
    
        return false;
    }

    bool isEqual(int x,int y){
       return x==y;
    }
    bool isEqual(float x,float y){
       return x==y;
    }
    bool isEqual(double x,double y){
       return x==y;
    }
    bool isEqual(string str1,string str2){
       int n1 = str1.length(), n2 = str2.length();
 
        if (n1 < n2 || n2 < n1)
            return false;
    
        for (int i = 0; i < n1; i++)
            if (str1[i] < str2[i])
                return false;
            else if (str1[i] > str2[i])
                return false;
    
        return true;
    }

    Node<T>* RR(Node<T>* root){
        Node<T> *temp=root->right;
        root->right=temp->left;
        temp->left=root;
        
        root->height=max(hit(root->left),hit(root->right))+1;
        temp->height=max(hit(temp->left),hit(temp->right))+1;
        
        return temp;
    }

    Node<T>* LL(Node<T>* root){
        Node<T> *temp=root->left;
        root->left=temp->right;
        temp->right=root;
        
        root->height=max(hit(root->left),hit(root->right))+1;
        temp->height=max(hit(temp->left),hit(temp->right))+1;
        
        return temp;
    }

/* Insert Function Sction*/

    Node<T>* rotation(Node<T>* root,Node<T> * nod){
        if(isLess(root->val,nod->val)){
            if(isLess(root->right->val,nod->val)) return RR(root);
            else{
                root->right=LL(root->right);
                return RR(root);
            }
        }
        else{
            if(isGreater(root->left->val,nod->val)) return LL(root);
            else{
                root->left=RR(root->left);
                return LL(root);
            }
        }
    }

    Node<T>* balance(Node<T>* root,Node<T> * nod){
        int BF=abs(hit(root->left) - hit(root->right));
        //cout<<"BF:"<<BF<<endl;
        if(BF>1) return rotation(root,nod);
        return root;
    }

    Node<T>* insertAVL(Node<T>* root,Node<T> * nod){
        if(root==NULL) return nod;
        else{
            if(isLess(root->val,nod->val)){
                    root->right = insertAVL(root->right,nod);
            }
            else if(isGreater(root->val,nod->val)){
                    root->left = insertAVL(root->left,nod);
            }
            else{
                root->count++;
                return root;
            }
            root->height=max(hit(root->left),hit(root->right))+1;
            return balance(root,nod);
        }
    }

    Node<T> * insert(Node<T> * root,T val)
    {
        Node<T>* nod=new Node<T>();
        nod->val=val;
        nod->height=1;
        nod->count=1;
        nod->left=NULL;nod->right=NULL;
        return insertAVL(root,nod);
    }

    Node<T>* insertAVL(Node<T>* root,Node<T> * nod, function<bool(T, T)> func){
        if(root==NULL) return nod;
        else{
            if(func(root->val,nod->val)){
                    root->right = insertAVL(root->right,nod,func);
            }
            else if(func(root->val,nod->val)){
                    root->left = insertAVL(root->left,nod,func);
            }
            else{
                root->count++;
                return root;
            }
            root->height=max(hit(root->left),hit(root->right))+1;
            return balance(root,nod);
        }
    }

    Node<T> * insert(Node<T> * root,T val,function<bool(T, T)> func)
    {
        Node<T>* nod=new Node<T>();
        nod->val=val;
        nod->height=1;
        nod->count=1;
        nod->left=NULL;nod->right=NULL;
        return insertAVL(root,nod,func);
    }
   /*End of Insert Function*/

/*start of delete------------*/
    Node<T>* notBoth(Node<T>* root){
        Node<T> *temp=NULL;
        if(root->left==NULL) temp=root->right;
        else temp=root->left;
        
        return temp;
    }
    
    Node<T>* success(Node<T>* root){
        Node<T>* temp = root;
            while (temp->left != NULL)
                temp = temp->left;
         
            return temp;
    }
    void dataCopy(Node<T> *root,Node<T> *temp){
            root->val=temp->val;
            root->height=temp->height;
            root->count=temp->count;
        }

    Node<T>* findAndDel(Node<T>* root, T key){
            if(root==NULL) return root;
            if(isEqual(root->val,key)) {
                if(root->right==NULL || root->left==NULL) {
                    if( (root->left == NULL) || (root->right == NULL) ) root=notBoth(root);
                }
                else
                {
                    Node<T>* temp=success(root->right);
                    dataCopy(root,temp);
                    root->right=findAndDel(root->right,temp->val);
                }
                if(root==NULL) return root;
            }
            if(isGreater(root->val,key)) root->left=findAndDel(root->left,key);
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

    Node<T>* deleteNode(Node<T>* root, T val)
    {
        if(root==NULL) return NULL;
            return findAndDel(root,val);
    }/*End of delete-----------------------------------------------------------------*/

/*K-th largest element---------------------------------------------------------------*/
    Node<T>* inOrd(Node<T> *root,T &k){
        if(root==NULL) return root;
        Node<T> *temp=NULL;
        temp=inOrd(root->right,k);

        if(temp!=NULL) return temp;

        k=k-root->count;
        if(k<=0) return root;
        
        temp=inOrd(root->left,k);
        
        return temp;
    }
    Node<T>* kthLargest(Node<T> *root, T k)
    {
        return inOrd(root,k);
    }

/*Count the number of elements in the tree whose values fall into a given range.*/
    void findRange(Node<T>* root, int low, int high , int &count){
        if(root==NULL) return;
        if(root->val >= low && root->val <= high) count+=root->count;
        if(root->val < low) findRange(root->right,low,high,count);
        else if(root->val > high) findRange(root->left,low,high,count);  
        else {
            findRange(root->right,low,high,count);
            findRange(root->left,low,high,count); 
        }
    }
    int getCount(Node<T> *root, int l, int h)
    {
            int count=0;
            findRange(root,l,h,count);
            return count;  
    }

/*Find Closest Element--------------------------------*/
    void findClosest(Node<T> *root, int k,T &_minDiff,T &minVal){
	    if(root==NULL) return;
	    int diff=abs(root->val-k);
	    
	    if(diff<_minDiff){
	        _minDiff=diff;
	        minVal=root->val;
	    }
	    findClosest(root->left,k,_minDiff,minVal);
	    findClosest(root->right,k,_minDiff,minVal);
	}
	
    T closest(Node<T> *root, T k)
    {
        T _minDiff=__INT_MAX__,minVal=root->val;
        findClosest(root,k,_minDiff,minVal);
        return minVal;
    } 

/*Search an element -------------------------------*/
    bool find(Node<T> *root,T k){
        if(root==NULL) return false;
        if(isEqual(root->val,k)) return true;
        if(isLess(root->val,k)) return find(root->right,k);
        return find(root->left,k);
    }

/*Count occurrences of element----------------------------------*/
    int countOccur(Node<T> *root,int k){
        if(root==NULL) return 0;
        if(isEqual(root->val,k)) return root->count;
        if(isLess(root->val,k)) return countOccur(root->right,k);
        return countOccur(root->left,k);
    }

/*Lower Bound---------------------------------------------------------*/
    T lower_bound(Node<T> *root,T k){
        T ans;
        if(typeid(T).name()=="string") ans="Not Found";
        else ans=-1;

        while(root!=NULL){
            if(isEqual(root->val,k)) return root->val;
            else if(isLess(k,root->val)){
                ans=root->val;
                root=root->left;
            }
            else root=root->right;
        }
        return ans;
    }

/*Upper Bound---------------------------------------------------------*/
    T upper_bound(Node<T> *root,T k){
        T ans;
        if(typeid(T).name()=="string") ans="Not Found";
        else ans=-1;

        while(root!=NULL){
            if(isLess(k,root->val)){
                ans=root->val;
                root=root->left;
            }
            else root=root->right;
        }
        return ans;
    }

/*Pre-Order------------------------------------------------------------*/
    void preOrder(struct Node<T>* root)
    {
        if (root != NULL) {
            cout << root->val << "("<<root->count << ")"<< " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    
    void in_Order(struct Node<T>* root)
    {
        if (root != NULL) {
            preOrder(root->left);
            cout << root->val << "("<<root->count << ")"<< " ";
            preOrder(root->right);
        }
    }
};
 
/* Driver program to test above function*/
int main()
{
    
    struct Node<string>* root = NULL;
    Avl<string> *obj=new Avl<string>();
    /* Constructing tree given in the above figure */
    root = obj->insert(root, "XYZ");
    root = obj->insert(root, "ABCD");
    // root = obj->insert(root, "abc");
    // root = obj->insert(root, "z");
    // root = obj->insert(root, "HF");
    // root = obj->insert(root, "HFSA");
    // root = obj->insert(root, "opq");
    // root = obj->insert(root, "ppq");
 
    cout <<"Pre order traversal of the constructed AVL tree is \n";
    obj->in_Order(root);
    cout<<endl;
    //root=obj->kthLargest(root,6);
    //cout<<root->val;
    //cout<<obj->getCount(root,5,17)<<endl;
    //cout<<obj->closest(root,10)<<endl;
    cout<<obj->lower_bound(root,"zzhi");
    //root=obj->deleteNode(root,"def");
    //root=obj->deleteNode(root,10);
 
    //cout <<"\nPre order traversal after deletion of 9 \n";
    //obj->preOrder(root);
    
}
     
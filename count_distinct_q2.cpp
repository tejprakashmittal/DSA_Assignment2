#define MAX_SIZE 100003

class MyHashMap {
public:
    
    struct Node{
        int key,val;
        struct Node* left;
        struct Node* right;
        
        // Node(int k,int v){
        //     key=k;
        //     val=v;
        //     left=NULL;
        //     right=NULL;
        // }
    };
    
    unsigned int hash(int key){
        // string str=to_string(key);
        // int len=str.size(),hash=0;
        // for(int i=len;i>0;i--){
        //     hash+=(str[i]*(int)(pow(7,i)))%MAX_SIZE;
        // }
        // return hash%MAX_SIZE;
    //      x = ((x >> 16) ^ x) * 0x45d9f3b;
    // x = ((x >> 16) ^ x) * 0x45d9f3b;
    // x = (x >> 16) ^ x;
    // return x%MAX_SIZE;
       return (key*7)%MAX_SIZE;
    }
    
    bool find(int key){
        if(arr[(key*7)%MAX_SIZE]!=NULL) return true;
        return false;
    }
    
    Node *arr[MAX_SIZE];
    
    Node* createNode(int key,int value){
        Node* node=new Node();
          node->key=key;
          node->val=value;
          node->left=NULL;
          node->right=NULL;
        
        return node;
    }
    
    void deleteNode(Node* node){
        Node *temp=node->left;
        temp->right=node->right;
        if(node->right!=NULL){
            node->right->left=temp;
        }
        node->left=NULL;
        node->right=NULL;
    }
    
    MyHashMap() {
       //arr=new Node[MAX_SIZE];
       memset(arr, NULL, MAX_SIZE);
    }
    
    void put(int key, int value) {
        int hashv=hash(key);
        
        if(arr[hashv] == NULL){
          Node* node=createNode(key,value);
          arr[hashv]=node;
        }
        else{
            Node* temp=arr[hashv];
            while(temp->right!=NULL){
                if(temp->key==key){
                    temp->val=value;
                    break;
                }
                temp=temp->right;
            }
            if(temp->right==NULL)
            {
                if(temp->key!=key){
                    Node* node=createNode(key,value);
                    temp->right=node;
                    node->left=temp;
                }
                else{
                    temp->val=value;
                }
            }
        }
    }
    
    int get(int key) {
        int hashv=hash(key);
        
        if(arr[hashv]==NULL) return -1;
        
        Node* temp=arr[hashv];
        
        while(temp!=NULL){
            if(temp->key==key){
                    return temp->val;
            }
            temp=temp->right;
        }
       return -1;
    }
    
    void remove(int key) {
        int hashv=hash(key);
        
             if(arr[hashv]!=NULL){            
               Node* temp=arr[hashv];

                if(temp->right==NULL){
                    arr[hashv]=NULL;
                    return;
                }
                 
                 if(temp->key==key){
                    arr[hashv]=temp->right;
                    temp->right->left=NULL;
                    temp->right=NULL;
                    return;
                }
                 
               while(temp!=NULL){
                    if(temp->key==key){
                            deleteNode(temp);
                            return;
                    }
                    temp=temp->right;
                }  
        } 
    }
};

class Solution:public MyHashMap{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        MyHashMap *umap = new MyHashMap();
        //unordered_map<int,int> umap;
        vector<int> vec;
        
        
        int dist_count = 0;

    for (int i = 0; i < k; i++) {
        if (umap->get(A[i]) == -1) {
            dist_count++;
	    umap->put(A[i],1);
        }
	else
	{
	   int temp=umap->get(A[i]);
           umap->put(A[i],++temp);
	}
    }
 
    vec.push_back(dist_count);
    //cout << dist_count << endl;
 
    // Traverse through the remaining array
    for (int i = k; i < n; i++) {
        // Remove first element of previous window
        // If there was only one occurrence, then reduce distinct count.
        if (umap->get(A[i - k]) == 1) {
            dist_count--;
        }
        // reduce count of the removed element
        int temp=umap->get(A[i-k]);
        umap->put(A[i-k],--temp);

        if(umap->get(A[i-k]) == 0) umap->remove(A[i-k]);
 
        // Add new element of current window
        // If this element appears first time,
        // increment distinct element count
 
       if (umap->get(A[i]) == -1) {
            dist_count++;
	    umap->put(A[i],1);
        }
	else
	{
	   int temp=umap->get(A[i]);
           umap->put(A[i],++temp);
	}
 
        // Print count of current window
        vec.push_back(dist_count);
        //cout << dist_count << endl;
    }
        
        // int count=0;
        // for(int i=0;i<k;i++) umap[A[i]]++;
        // vec.push_back(umap.size());
        
        // for(int i=1;i<n-k+1;i++){
        //     umap[A[i-1]]--;
        //     if(umap[A[i-1]]==0) umap.erase(A[i-1]);
        //     umap[A[i+k-1]]++;
        //     vec.push_back(umap.size());
        // }
        return vec;
    }
};

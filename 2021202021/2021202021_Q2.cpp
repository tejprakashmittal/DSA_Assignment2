#include<iostream>
#include<vector>
#include<string.h>
#include <sstream>
#define MAX_SIZE 1000003
using namespace std;

template<class T1,class T2>
class MyHashMap {
public:
    struct Node{
        T1 key;
        T2 val;
        struct Node* left;
        struct Node* right;
        
        // Node(int k,int v){
        //     key=k;
        //     val=v;
        //     left=NULL;
        //     right=NULL;
        // }
    };
    
    
    long long polynomialRollingHash(string const& str)
    {
        int p = 31;
        int m = MAX_SIZE;
        long long power_of_p = 1;
        long long hash_val = 0;
        
        for (int i = 0; i < str.length(); i++) {
            hash_val = (hash_val + (str[i] - 'a' + 1) * power_of_p) % m;
            power_of_p = (power_of_p * p) % m;
        }
        return (hash_val%m + m) % m;
    }
    
    int hash(T1 key){
        ostringstream os;
        os << key;
        return polynomialRollingHash(os.str());
    }
    
    Node *arr[MAX_SIZE];
    
    Node* createNode(T1 key,T2 value){
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
    
    void insert(T1 key, T2 value) {
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
    
    bool find(T1 key) {
        int hashv=hash(key);
        
        if(arr[hashv]==NULL) return false;
        
        Node* temp=arr[hashv];
        
        while(temp!=NULL){
            if(temp->key==key){
                    return true;
            }
            temp=temp->right;
        }
       return false;
    }

    T2 operator [](T1 key) {
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
    
    void erase(T1 key) {
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

class Solution:public MyHashMap<int,int>{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        MyHashMap<int,int> *umap=new MyHashMap<int,int>();
        vector<int> vec;

        int dist_count = 0;

    for (int i = 0; i < k; i++) {
        if((*umap)[A[i]] == -1) {
            dist_count++;
	        (*umap).insert(A[i],1);
        }
        else
        {
            int temp=(*umap)[A[i]];
            (*umap).insert(A[i],++temp);
        }
    }
 
    vec.push_back(dist_count);
    for (int i = k; i < n; i++) {
        if ((*umap)[A[i - k]] == 1) {
            dist_count--;
        }
        int temp=(*umap)[A[i-k]];
        (*umap).insert(A[i-k],--temp);

        if((*umap)[A[i-k]] == 0) (*umap).erase(A[i-k]);
 
        if ((*umap)[A[i]] == -1) {
            dist_count++;
	        (*umap).insert(A[i],1);
        }
        else
        {
            int temp=(*umap)[A[i]];
            (*umap).insert(A[i],++temp);
        }
        vec.push_back(dist_count);
    }
        return vec;
    }
};

vector <int> countDistinct (int A[], int n, int k)
    {
        MyHashMap<int,int> umap;
        vector<int> vec;

        int dist_count = 0;

    for (int i = 0; i < k; i++) {
        if(umap[A[i]] == -1) {
            dist_count++;
	        umap.insert(A[i],1);
        }
        else
        {
            int temp=umap[A[i]];
            umap.insert(A[i],++temp);
        }
    }
 
    vec.push_back(dist_count);
    for (int i = k; i < n; i++) {
        if (umap[A[i - k]] == 1) {
            dist_count--;
        }
        int temp=umap[A[i-k]];
        umap.insert(A[i-k],--temp);

        if(umap[A[i-k]] == 0) umap.erase(A[i-k]);
 
        if (umap[A[i]] == -1) {
            dist_count++;
	        umap.insert(A[i],1);
        }
        else
        {
            int temp=umap[A[i]];
            umap.insert(A[i],++temp);
        }
        vec.push_back(dist_count);
    }
        return vec;
    }

int main(){

    //unordered_Map<string,string>um;
    MyHashMap<string,string> *um=new MyHashMap<string,string>();
    //um.print();
    
    string a,b;
    string k;
    // int test;
    // cin>>test;
    while(true){
        int c;
    cin>>c;
    switch(c){
        case 1:
        cin>>a>>b;
        um->insert(a,b);
       // um.print();
        break;
        
        case 2:
        
        cin>>k;
        if(um->find(k)){
            cout<<"true";
        }else{
            cout<<"false";
        }
        cout<<endl;
        break;
        
        case 3:
        
        cin>>k;
        um->erase(k);
        break;
        
        // case 4:
        // cin>>k;
        // cout<<(*um)[k];
        // break;
        
        
        case 5:
        exit(0);
        
        
         }
    }

    // Solution obj;
    // int N = 7, K = 4;
    // int A[] = {1,2,1,3,4,2,3};
    // vector<int> vec;
    // vec=obj.countDistinct(A,N,K);
    // for(auto x:vec) cout<<x<<" ";
    // return 0;
}
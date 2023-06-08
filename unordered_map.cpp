#include<iostream>
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

// int main(){
//     MyHashMap<string,float> obj;// = new MyHashMap<string,float>();
//     obj.insert("hello",3.9);
//     obj.insert("hi",4.9);
//     // obj->insert(2.6,3.1);
//     // obj->insert(2.9,3.8);
//     // obj->insert(2.4,3.5);
//     //obj->erase("hello");
//     cout<<obj["hello"]<<endl;
//     //obj->remove(key); 
//     return 0;
// }

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
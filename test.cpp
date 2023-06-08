#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

/* Resize Array implementation---------------------------------
int size=2;
int *arr=new int[size];

void resize(){
    //int n=sizeof(arr)/sizeof(arr[0]);
    int* newArr = new int[size+1];
    //cout<<size+1<<endl;
    for(int i=0;i<size;i++){
        newArr[i]=arr[i];
    }
    size=size+1;
    delete[] arr;
    arr = newArr;
}

int main(){
    for(int i=0;i<200;i++){
        arr[i]=i;
        if(size<=i+1) resize();
    }
    cout<<size<<endl;
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
}
-----------------------------------------------------------------*/

/* Unused Section---------------
Node* LR(Node* root,Node * nod){
        Node *temp = root->left->right;
        root->left->right = temp->left;
        root->left = temp->right;
        temp->left=root->left;
        temp->right=root;
        
        root->ht=max(hit(root->left),hit(root->right))+1;
        if(root->left != NULL)
        root->left->ht=max(hit(root->left->left),hit(root->left->right))+1;
        
        return temp;
    }

    Node* RL(Node* root,Node * nod){
        Node *temp = root->right->left;
        
        root->right->left = temp->right;
        root->right = temp->left;
        
        temp->right=root->right;
        temp->left=root;
        
        root->ht=max(hit(root->left),hit(root->right))+1;
        if(root->right != NULL)
        root->right->ht=max(hit(root->right->left),hit(root->right->right))+1;
        
        return temp;
    }
    */
class A{
    public:
    int val;
    void put(int x){
        val=x;
        cout<<val;
    }
};
class B : public A{
    public:
    void aa(){
        A obj;
    obj.put(22);
    }
};
int main(){
    // deque<int> second (4,100);
    // cout<<second.size();
    set<string> st;
    st.insert("hello");
    st.insert("Ko");
    for(auto it:st){
        cout<<(it)<<endl;
    }
    // unordered_map<int,int> umap;
    // cout<<umap.size()<<endl;
    // cout<<umap[2]<<endl;
    // cout<<umap.size()<<endl;
    // string str="ab",str1="z";
    // if(str<str1) cout<<"Yes";
}
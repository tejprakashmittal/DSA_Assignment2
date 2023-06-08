// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	
	void findClosest(Node *root, int k,int &_minDiff,int &minVal){
	    if(root==NULL) return;
	    int diff=abs(root->data-k);
	    
	    if(diff<_minDiff){
	        _minDiff=diff;
	        minVal=root->data;
	    }
	    findClosest(root->left,k,_minDiff,minVal);
	    findClosest(root->right,k,_minDiff,minVal);
	}
	
    int minDiff(Node *root, int k)
    {
        int _minDiff=INT_MAX,minVal=root->data;
        findClosest(root,k,_minDiff,minVal);
        return minVal;
    }
};

#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
struct Node* getNode(int data) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

bool rec(struct Node* root, int* sum, int x)
{
    if(root==NULL)
     return false;
   
  
  bool r = rec(root->right,sum,x);
  bool l = rec(root->left,sum,x); 
   

   
    if(l||r)
    {
        *sum = *sum+(root->data);
    }
    
    if(root->data == x) 
       return true;
    else
        return false;
}



int main() 
{ 
  
  
    Node *root = getNode(4);           /*        4        */
    root->left = getNode(2);           /*       / \       */
    root->right = getNode(5);          /*      2   5      */
    root->left->left = getNode(7);     /*     / \ / \     */
    root->left->right = getNode(2);    /*    7  2 2  3    */
    root->right->left = getNode(2); 
    root->right->right = getNode(2); 
    int sum = 0;
    int x = 2;
    rec(root,&sum,x);
    cout<<sum<<endl;
    
} 




   

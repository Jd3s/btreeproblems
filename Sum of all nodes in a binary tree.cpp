#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

int rec(struct Node* root)
{
    if(root==NULL)
     return 0;
  
     return (root-> data + rec(root->left)+ rec(root->right));
}



int main() 
{ 
  
    struct Node *root = newNode(12); 
    root->left = newNode(5); 
    root->left->left = newNode(3); 
    root->left->right = newNode(9); 
    root->left->left->left = newNode(1); 
    root->left->right->left = newNode(2);
    root->left->right->right = newNode(2);
    cout<< (rec(root));
} 




   

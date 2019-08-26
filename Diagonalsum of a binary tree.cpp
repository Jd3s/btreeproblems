#include <bits/stdc++.h> 
using namespace std; 
int a[10000]; 
int maxlefts = 0;
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

void rec(struct Node* root, int lc)
{
    if(root==NULL)
     return ;
    else
    {
       rec(root->right,lc);
       rec(root->left,lc+1);
       
       a[lc] = a[lc]+root->data;
       maxlefts = max(lc,maxlefts);
    }

}

int main() 
{ 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(9); 
    root->left->right = newNode(6); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->left->right->left = newNode(11); 
    root->left->left->right = newNode(10); 
  
    rec(root,0); 
    for(int i=0;i<=maxlefts;i++)
     cout<<a[i]<<endl;
    
} 


   

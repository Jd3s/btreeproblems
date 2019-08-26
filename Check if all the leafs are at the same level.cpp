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

int rec(struct Node* root, int level, int *leaflevel)
{
    if(root==NULL)
     return 1;
    if (root->left == NULL && root-> right == NULL)
     {
         if(*leaflevel == -1)
          *leaflevel = level;
         else if(*leaflevel != level)
          return 0;
         else 
          return 1;
     }
     return rec(root->left,level+1,leaflevel)&&rec(root->right,level+1,leaflevel);
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
    int leaflevel = -1;
    cout<< (rec(root,0,&leaflevel) == 0 ? "False" : "True");
} 




   

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

void rec(struct Node* root, int* sum)
{
    if(root==NULL)
     return ;
   
    if(root->left && root->left->left==NULL && root->left->right == NULL)
    {
        *sum = *sum+(root->left->data);
    }
  
        rec(root->left,sum);
        rec(root->right,sum);
  

}



int main() 
{ 
  
  
    struct Node *root         = newNode(20); 
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12); 
    int sum = 0;
    rec(root,&sum);
    cout<<sum<<endl;
    
} 




   

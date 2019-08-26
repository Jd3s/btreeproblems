#include <bits/stdc++.h> 
using namespace std; 
int ans = 0,n = 0;
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
    
    int l = rec(root->left);
    int r = rec(root->right);
    
    return l+r+1;
}

int rec1(struct Node* root)
{
    if(root==NULL)
     return 0;
    
    int l = rec1(root->left);
    int r = rec1(root->right);
    
    if(l+r+1==(n/2))
    {
     ans = 1;
    }

    
    return l+r+1;

}

int main() 
{ 
    struct Node* root = newNode(5); 
    root->left = newNode(1); 
    root->right = newNode(6); 
    root->left->left = newNode(3); 
    root->right->left = newNode(7); 
    root->right->right = newNode(4); 
  
    n = rec(root);
    cout<<"count=  "<<n<<endl;
    if(n%2)
    {
     cout<<"0"<<endl;
    }
    else
    {
    rec1(root);
    cout<<ans<<endl;
    }
    
} 


   

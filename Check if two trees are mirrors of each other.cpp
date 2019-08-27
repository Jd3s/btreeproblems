#include <bits/stdc++.h> 
using namespace std; 


struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
 Node* newNode(int k) 
{ 
     Node *temp = new Node; 
    temp->data = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

bool rec(struct Node* root1, struct Node* root2)
{
  if(!root1&&!root2)
   return true;
  else if (root1&&root2)
  {
   if(root1->data == root2 ->data)
    return rec(root1->left,root2->right)&&rec(root1->right,root2->left);
  else 
    return false;
  }
  else
   return false;

}

int main() 
{ 
    Node *a = newNode(1); 
    Node *b = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
  
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 
  
    cout<<rec(a,b);
   
    
} 


   

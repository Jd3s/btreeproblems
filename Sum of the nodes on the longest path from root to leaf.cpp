#include <bits/stdc++.h> 
using namespace std; 
int maxlevel = 0, maxsum = 0;

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
 Node* getNode(int k) 
{ 
     Node *temp = new Node; 
    temp->data = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void rec(struct Node* root,int level,int sum)
{
  if(root==NULL)
   return;
  if(!root->left&&!root->right)
  {
      if(level > maxlevel)
      {
          maxsum = sum+(root->data);
          maxlevel = level;
      }
      else if(level == maxlevel)
      {
           maxsum = max(maxsum,sum+root->data);
      }
      
      return;
  }
  else
  {
      rec(root->left, level+1, sum+root->data);
      rec(root->right, level+1, sum+root->data);
  }
  
  
  
}

int main() 
{ 
    Node* root = getNode(4);                      /*        4        */
    root->left = getNode(2);                      /*       / \       */
    root->right = getNode(5);                     /*      2   5      */
    root->left->left = getNode(7);                /*     / \ / \     */
    root->left->left->left = getNode(-10);        /*    7  1 2  3    */
     root->left->left->left->left = getNode(-10); /*   /   /          */
    root->left->right = getNode(1);              /*  -10  6           */
    root->right->left = getNode(2);                  /    
    root->right->right = getNode(3);            /* -10                 */
    root->left->right->left = getNode(6); 
  
    rec(root,0,0);
   cout<<maxsum<<"  "<<maxlevel;
    
} 


   

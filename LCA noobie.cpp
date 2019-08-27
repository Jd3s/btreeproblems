#include <bits/stdc++.h> 
using namespace std; 
int key;
vector<int> path;
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

bool rec(struct Node* root)
{
    if(root==NULL)
     return 0;
    
    if(root->data == key)
    {
        path.push_back(key);
        return 1;
    }
      
      
    bool l = rec(root->left);
    bool r = rec(root->right);
    
    if(l||r)
    {
     path.push_back(root->data);
     return 1;
    }
    
    return 0;
    

}

int main() 
{ 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    key = 4;
    rec(root);
     vector<int> a ,b;
    for(int i=path.size()-1;i>=0;i--)
     a.push_back(path[i]);
   path.clear();
   key = 5;
   rec(root);
    for(int i=path.size()-1;i>=0;i--)
     b.push_back(path[i]);
     int ans =0;
     for(int i=0;i<min(a.size(),b.size());i++)
     {
         if(a[i]==b[i])
         {
             ans = a[i];
         }
         else
          break;
     }
   cout<<ans;
    
    
} 


   

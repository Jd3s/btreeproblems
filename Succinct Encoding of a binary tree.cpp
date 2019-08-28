#include <bits/stdc++.h> 
using namespace std; 
int maxlevel = 0, maxsum = 0;

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

void sencoding(struct Node* root, list<bool> &enc, list<int> &data)
{
  if(root==NULL)
  {
     enc.push_back(0); 
      return;
  }
  
 
  else
  {
      enc.push_back(1);
      data.push_back(root->data);
      
      sencoding(root->left, enc,data);
      sencoding(root->right, enc,data);
  }
  
  
  
}

 Node* sdecoding(list<bool> &enc, list<int> &data)
{
    if(enc.size()<=0)
     return NULL;
     
  if(enc.front()==0)
  {
     enc.pop_front();
      return NULL;
  }
  
      enc.pop_front();
      Node *root = newNode(data.front());
      data.pop_front();
      root->left = sdecoding(enc,data);
      root-> right = sdecoding(enc,data);
      return root;
}

int main() 
{ 
    Node *root         = newNode(10); 
    root->left         = newNode(20); 
    root->right        = newNode(30); 
    root->left->left   = newNode(40); 
    root->left->right  = newNode(50); 
    root->right->right = newNode(70); 
  
    list<bool> enc;
    list<int> data;
    sencoding(root,enc,data);
    
    for(auto it : enc)
    {
       
        cout<<it;
    }
    cout<<endl;
    
    for(auto it : data)
    {
       cout<<it;
    }
    
    cout<<sdecoding(enc,data);
    
    
} 


   

#include<iostream>
using namespace std;
struct node{
    int item;
    node *left;
    node *right;
};

class BST
{
private:    
    node *root;
protected:
    void preorderrec(node *);
    void inorderrec(node *);
    void postorderrec(node *);
    node* deleteNode(node *,int );
public:
    BST();
   bool isEmpty();
   void inserting(int ,node * );
   void preorder();
   void inorder();
   void postorder();
   void del(int );
    ~BST();
};
void BST::del(int data){
    root=deleteNode(root,data);
}
node* BST::deleteNode(node *ptr, int data){
    if(ptr==NULL)
        return NULL;
    if(data < ptr->item)
        ptr->left = deleteNode(ptr->left,data);
    else if(data > ptr->item)
        ptr->right = deleteNode(ptr->right, data);
    else{
        //No child
        if(ptr->left==NULL && ptr->right==NULL){
            delete ptr;
            return NULL;
        }
        //Single child
        if(ptr->left==NULL || ptr->right==NULL){
            node *child = ptr->left?ptr->left:ptr->right;
            delete ptr;
            return child;
        }
        //two child
        node* pred, *parpred;
        parpred = ptr;
        pred = ptr->left;
        while(pred->right!=NULL){
            parpred = pred;
            pred = pred->right;
        }
        ptr->item = pred->item;
        parpred->right = deleteNode(pred,pred->item);
    }
    return ptr;
}
void BST::postorderrec(node *ptr){
    if(ptr){
        postorderrec(ptr->left);
        postorderrec(ptr->right);
        cout<<" "<<ptr->item;
    }
}
void BST::postorder(){
    postorderrec(root);
}
void BST::inorderrec(node *ptr){
    if(ptr){
        inorderrec(ptr->left);
        cout<<" "<<ptr->item;
        inorderrec(ptr->right);
    }
}
void BST::inorder(){
    inorderrec(root);
}
void BST::preorderrec(node *ptr){
    if(ptr){
        cout<<" "<<ptr->item;
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}
void BST::preorder(){
    preorderrec(root);
}
void BST::inserting(int data, node *root){
    node *n=new node;
    n->item = data;
    n->left = NULL;
    n->right = NULL;
    node*ptr = root;
    //RECURSION APPROACH --------->
    // if(root){
    //     if(data > root->item){
    //         root->left = n;
    //         root->right= NULL;
    //         inserting(data , root->left);
    //     }
    //     if(data < root->item){
    //         root->right = n;
    //         inserting(data , root->right);
    //     }
    // }
    //Alternative Approcach----------->
    if(root==NULL){
        root=n;
    }
    else{
        while(n->item!=ptr->item){
            if(n->item < ptr->item){
              if(ptr->left!=NULL)
                    ptr=ptr->left;
            else{
                ptr->left=n;
                break;
            }
            }
            else{
                if(ptr->right!=NULL)
                    ptr=ptr->right;
                else{
                    ptr->right=n;
                    break;
                }
            }
        }
        if(ptr->item==root->item){
            delete n;
        }
    }
}
bool BST::isEmpty(){
    return root==NULL;
}
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
}

#include<iostream>
using namespace std;

struct node{
    node*left;
    int item;
    node*right;
};
class AVL{
    private:
        node * root;
    public:
        AVL();
        void balanceFactor(int );
        node* search(int );
};
node *AVL::search(int data)
{
    node *ptr = root;
    while (ptr)
    {
        if (ptr->item == data)
            return ptr;
        if (ptr->item > data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}
void AVL::balanceFactor(int data){
    node* ptr = search(data);
    node* L=ptr->left;
    node* R=ptr->right;
    int l=0,r=0;
    while(L->left && L->right!=NULL){
        if(L->left==NULL)
            L=L->right;
        else
            L=L->left;
        l=l+1;
    }
    while(R->left && R->right!=NULL){
        if(R->left==NULL)
            R=R->right;
        else
            R=R->left;
        r=r+1;
    }
    int diff=l-r;
    cout<<diff;
}
AVL::AVL(){
    root=NULL;
}

int main(){
    
    return 0;
}
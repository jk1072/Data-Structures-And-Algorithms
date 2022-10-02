#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
 
void inOrder(struct  node* root){

    
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
    
}
 
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
 
struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}
struct node * search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}
void insert(struct node *root, int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}
struct node *inOrderPredecessor_Or_Successor(struct node* root){
    if (root->left!=NULL){
        root= root->left;
        while (root->right!=NULL){  // inOrderPredecessor left tree ka sabse bada child hota hai 
        root = root->right;}
        return root;
        }
    if (root->right!=NULL){
        root =root->right;
        while (root->left!=NULL){   // inOrderSuccessor right tree ka sabse chota child hota hai
        root = root->left;}
        return root;
        }
    
}
struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        printf("Tree is Empty so value can`t be deleted sorry!");
        return NULL;
    }
    if (root->data==value&&root->left==NULL&&root->right==NULL){
        free(root);
        printf("value found and deleted");
        return NULL;
        
    }
    if (root->data!=value&&root->left==NULL&&root->right==NULL){
        printf("value not found sorry!");
        return root;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor_Or_Successor(root);
        root->data = iPre->data;
        if (root->left!= NULL && root->right== NULL ){
        root->left = deleteNode(root->left, iPre->data);
        }
        if (root->right!= NULL && root->left== NULL){
        root->right = deleteNode(root->right, iPre->data);
        }
        if (root->left!= NULL && root->right!= NULL ){
        root->left = deleteNode(root->left, iPre->data);
        }
    }
    return root;
}
 
int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(7);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(6);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \   \
    //  1   4   8
 
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left= p5;
    inOrder(p);
    printf("\n");
    struct node* q=deleteNode(p, 5);
    printf("\n");
    if (q!=NULL){
    inOrder(q);
    }else{
        printf("Tree is Empty");
    }
    // struct node* q =inOrderPredecessor(p2 );
    // printf("%d",q->data);
    return 0;
}
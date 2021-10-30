#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

struct node* newnode(int data){
    struct node* vertex = (struct node*)malloc(sizeof(struct node));
    vertex->data = data;
    vertex->left = NULL;
    vertex->right = NULL;
    return vertex;
}

int main(){
    int n;
    struct node* root = newnode(0);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        struct node* temp_node = newnode(temp);
        
    }
}
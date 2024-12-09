struct node
{
int data;
struct node*left,*right;
};
#include<stdio.h>
#include<stdlib.h>
void main()
{
struct node*root=(struct node*)0;
struct node*insert(struct node*,int);
struct node*delete(struct node*,int);
struct node*search(struct node*,int);
void display(struct node*);
int opt,data;
do
{
printf("\n1.insert\n2.search\n3.delete\n4.display\n5.exit\n");
printf("enter you choice:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("enter the data:");
       scanf("%d",&data);
       root=insert(root,data);
       break;
case 2:printf("enter the data:");
       scanf("%d",&data);
       if(search(root,data)==0)
       printf("not found");
       else
       printf("found");
       break;
case 3:printf("data:\n");
       scanf("%d",&data);
       root=delete(root,data);
       break;
case 4:display(root);
       break;
case 5:exit(0);
}
}
while(1);
}
void display(struct node*bst)
{
if(bst!=(struct node*)0)
{
display(bst->left);
printf("%d\t",bst->data);
display(bst->right);
}
}
struct node*insert(struct node*bst,int data)
{
struct node*t,*t1=bst,*t2;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
t->left=t->right=(struct node*)0;
if(bst==0)
bst=t;
else
{
while(t1!=0 &&t1->data!=data)
{
t2=t1;
if(data<t1->data)
t1=t1->left;
else
t1=t1->right;
}
if(t1==0)
if(data<t2->data)
t2->left=t;
else
t2->right=t;
else
printf("duplicate\n");
}
return bst;
}
struct node*search(struct node*bst,int data)
{
while(bst!=(struct node*)0 && bst->data!=data)
if(data<bst->data)
bst=bst->left;
else
bst=bst->right;
return bst;
}
struct node* delete(struct node* bst, int data) {
    struct node* t1 = bst;
    struct node* t2 = NULL;
    struct node* sp = NULL;

    while (t1 != NULL && t1->data != data) {
        t2 = t1;
        if (data < t1->data) {
            t1 = t1->left;
        } else {
            t1 = t1->right;
        }
    }

    if (t1 == NULL) {
        printf("Node not found\n");
        return bst;  // Data not found
    }

    // Case 1: Node has no children
    if (t1->left == NULL && t1->right == NULL) {
        if (t1 == bst) {
            free(bst);
            return NULL;  // Tree becomes empty
        }
        if (t2->left == t1) {
            t2->left = NULL;
        } else {
            t2->right = NULL;
        }
        free(t1);
    }
    // Case 2: Node has one child
    else if (t1->left == NULL || t1->right == NULL) {
        struct node* child = (t1->left != NULL) ? t1->left : t1->right;
        if (t1 == bst) {
            free(bst);
            return child;  // Return the child as new root
        }
        if (t2->left == t1) {
            t2->left = child;
        } else {
            t2->right = child;
        }
        free(t1);
    }
    // Case 3: Node has two children
    else {
        sp = t1;
        t2 = t1->right;
        while (t2->left != NULL) {
            sp = t2;
            t2 = t2->left;
        }
        t1->data = t2->data;  // Replace data
        if (sp->left == t2) {
            sp->left = t2->right;
        } else {
            sp->right = t2->right;
        }
        free(t2);
    }
    return bst;
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left,*right;
};
void main()
{
struct node*start=(struct node*)0;
struct node*insert(struct node*,int);
struct node*delete(struct node*,int);
struct node*search(struct node*,int);
void display(struct node*);
int opt,data;
do
{
printf("\n 1.insert\n");
printf("\n 2.delete\n");
printf("\n 3.search\n");
printf("\n 4.display\n");
printf("\n 5.exit\n");
printf("enter your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("enter the data:");
       scanf("%d",&data);
       start=insert(start,data);
       break;
case 2:printf("data to be deleted:");
       scanf("%d",&data);
       start=delete(start,data);
       break;
case 3:printf("item to search:");
       scanf("%d",&data);
       if(search(start,data)==(struct node*)0)
       printf("item not found");
       else
       printf("item found");
       break;
case 4:display(start);
       break;
case 5:exit(0);
}
}
while(1);
}
void display(struct node*s)
{
while(s!=(struct node*)0)
{
printf("%d\t",s->data);
s=s->right;
}
}
struct node*search(struct node*s,int data)
{
while(s!=(struct node*)0 && s->data!=data)
s=s->right;
return s;
}
struct node*insert(struct node*s,int data)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node*));
t->data=data;
t->left=(struct node*)0;
t->right=s;
if(s!=(struct node*)0)
{
s->left=t;
s=t;
}
return t;
}
struct node*delete(struct node*s,int data)
{
struct node*t;
t=search(s,data);
if(t!=(struct node*)0)
{
if((t->left==(struct node*)0)&&t->right==(struct node*)0)
{
s=(struct node*)0;
printf("item %d deleted.\n",data);
}
else if(t->left==0)
{
s=s->right;
s->left=0;
printf("item %d deleted.\n",data);
}
else if(t->right==0)
{
t->left->right=0;
printf("item %d deleted.\n",data);
}
else
{
t->left->right=t->right;
t->right->left=t->left;
printf("item %d deleted.\n",data);
}
free(t);
}
else
printf("not found");
return s;
}




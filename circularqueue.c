#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int queue[SIZE];
int front=0,rear=0;
void main()
{
void enqueue(int);
int deq();
int search(int);
int opt,data;
do
{
printf("\n1.insert\n2.delete\n3.search\n4.exit\n");
printf("enter you choice:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("enter the data to insert:");
       scanf("%d",&data);enqueue(data);
       break;
case 2:data=deq();
       if(data!=-1)
       printf("the deleted item is%d",data);
       break;
case 3:printf("enter item to serch:");
       scanf("%d",&data);
       if(search(data))
       printf("item found\n");
       else
       printf("item not found\n");
       break;
case 4:exit(0);
}
}
while(1);
}
void enqueue(int data)
{
int trear=rear;
trear=(trear+1)%SIZE;
if(trear==front)
printf("queue is full\n");
else
{
rear=trear;
queue[rear]=data;
}
}
int deq()
{
if(front==rear)
{
printf("queue is empty\n");
return -1;
}
else
{
front=(front+1)%SIZE;
}
return queue[front];
}
int search(int item)
{
if(front==rear)
return 0;
int tfront=(front+1)%SIZE;
while(tfront!=rear&& queue[tfront]!=item)
tfront=(tfront+1)%SIZE;
if(queue[tfront]==item)
return 1;
else 
return 0;
}

       

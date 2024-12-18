#include<stdio.h>
#include<stdlib.h>
# define SIZE 10
int queue[SIZE];
int front=-1,rear=-1;
void main()
{
void insertq(int);
int deleteq();
int searchq(int);
int opt,data,ans;
do
{
printf("\n 1.Insert\n 2.Delete\n 3.Search\n 4.Exit\n Enter your option:\n");
scanf("%d",&opt);
switch(opt)
{
case 1 :printf("Enter the Data:\n");
scanf("%d",&data);
enque(data);
break;
case 2 :data=deque();
printf("Deleted data:\n%d",data);
break;
case 3 :printf("Data to search:");
scanf("%d",&data);
ans=searchq(data);
if(ans==1)
printf("\n found");
else
printf("\n not found");
break;
case 4 :exit(0);
}
}
while(1);
}

void insertq(int data)
{
if(rear==SIZE-1)
printf("\n Queue is full");
else
queue[++rear]=data;
}

int deque()
{
if(front==rear)
{
printf("Queue is empty");
exit(1);
}
return queue[++front];
}

int searchq(int item)
{
int tfront==front+1;
while(tfront!=rear && queue[tfront]!=item)
++tfront;
if(queue[tfront]==item)
return 1;
else
return 0;
		
}	
				
				
				

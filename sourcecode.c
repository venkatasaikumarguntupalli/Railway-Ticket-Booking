#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define size 5
typedef struct node
{
	int regno;
	char name[20];
	char gender[7];
	char place[10];
	char destination[10];
	int age;
	struct node *ptr;
}node;
node* deq();
void create();
int reserve();
int cancel(int);
void enq(node*);
void display();
node *new1,*cur,*head,*front,*rear,*pre;
int count=0;
int num=0;
void create( )
{
	new1=(node*)malloc(sizeof(node));
	new1->regno=1;
	printf("Name:\n");
	scanf("%s",new1->name);
	printf("Age :\n");
	scanf("%d", &new1->age);
	printf("Enter gender\n");
	scanf("%s",new1->gender);
	printf("Enter your place and destination\n");
	scanf("%s",new1->place);
	scanf("%s",new1->destination);
	head=new1;
	new1->ptr=NULL;
	num++;
}

int reserve(head)
{
	if(head==NULL)
	{
	   create(head);
	   return 1;
	}
	else
	{
	   cur=head;
	   while(cur->ptr!=NULL)
	    {
	      cur=cur->ptr;
	    }
	   new1=(node*)malloc(sizeof(node));
	   printf("Name:\n");
	   scanf("%s", new1->name);
	   printf("Age :\n");
	   scanf("%d", &new1->age);
	   printf("Enter gender\n");
	   scanf("%s",new1->gender);
	   printf("Enter your place and destination\n");
	   scanf("%s",new1->place);
	   scanf("%s",new1->destination);
	   new1->ptr=NULL;
	   if(num<=size)
	     {
		num++;
		new1->regno=num;
		cur->ptr=new1;
		return 1;
	     }
	   else
	     {
		enq(new1);
		return 0;
	     }
	}
}

int cancel(int reg)
{
	cur=head;
	pre=NULL;
	if(head==NULL)
	return -1;
	if(cur->ptr==NULL && cur->regno==reg)
	  {
	     head=NULL;
	     num--;
	     free(cur);
	     return 1;
	   }
       else
       {
	  while(cur->regno!=reg && cur->ptr!=NULL)
		{
		   pre=cur;
		   cur=cur->ptr;
		}
		if(cur==NULL && cur->regno!=reg)
		    return -1;
		else
			pre->ptr=cur->ptr;
		free(cur);
		new1=deq();
		while(pre->ptr!=NULL)
			pre=pre->ptr;
		pre->ptr=new1;
		num--;
		return 1;
	}
}

void enq(node *new1)
{
	if(rear==NULL)
	{
		rear=new1;
		rear->ptr=NULL;
		front=rear;
	}
	else
	{
		cur=new1;
		rear->ptr=cur;
		cur->ptr=NULL;
		rear=cur;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->ptr!=NULL)
		{
			front=front->ptr;
			front1->ptr=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			return front1;
		}
	}


}


void display()
{
	cur=head;
	while(cur!=NULL)
	{
		printf("\nRegistration Number: %d\n",cur->regno);
		printf("Name : %s\n", cur->name);
		printf("Gender :%s\n",cur->gender);
		printf("Your journey from %s to %s\n",cur->place,cur->destination);
		cur=cur->ptr;
    }

}

int main()
{
	int choice, status=0,canc=0, reg=0;
	head=NULL;
	rear=NULL;
	front=NULL;
	printf("\t\t\t***RAILWAY RESERVATION***\t\t\t\t\n");
	while(1)
	{
	printf("\n\nDo you want to - \n 1. Reserve a ticket? \n 2. Cancel Booking \n 3. Display
             passenger details \n 4. exit\n\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1 : status=reserve(head);
		      if(status==0)
			printf("\nBooking Full!! \nYou are added to waiting list. Waiting list
                                        number %d", count);
		      else
			printf(" \nBooking Successful!!! Enjoy your journey! Your Reg No is
                                         %d\n\n", num);

		      break;

	    case 2:   printf(" \n Give the Registration number to be cancelled\n");
		      scanf(" %d", &reg);
		      if(reg>num)
		      printf("Invalid!!");
		      else
		      {
		      canc=cancel(reg);
		      if(canc==-1)
			printf("\nRegistration number invalid!!\n");
		      else
			printf("\nRegistration cancelled successfully\n");
			}
		      break;

	    case 3: display();
	    break;
	    case 4: exit(0);
	}
}
}

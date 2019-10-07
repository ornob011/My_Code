#include<bits/stdc++.h>
using namespace std;

#define size 5
int arr[size];

int front=-1, rear=-1;

void enqueue()
{
	int element;

	if((front==0 && rear==size-1) || (rear+1==front))
		printf("Queue is overflowed.\n");

	else
	{
		printf("Enter an element:\n");
		cin>>element;

		if(rear==-1)
			rear=front=0;

		else if(rear==size-1)
			rear=0;
		else
			rear++;

		arr[rear]=element;
	}
}


void dequeue()
{
	int element;

	if(front==-1)
		printf("Queue is underflowed.\n");

	else
	{
		element=arr[front];

		if(front==rear)
			front=rear=-1;

		else if(front==size-1)
			front=0;

		else
			front++;

		printf("Deleted element: %d\n", element);
	}
}

void traverse()
{
	int i;

	if(front==-1 && rear==-1)
		printf("Queue is underflowed.\n");

	else if(front>rear)
	{
		for(i=front; i<size; i++)
			printf("%d \n", arr[i]);

		for(i=0; i<=rear; i++)
			printf("%d \n", arr[i]);
	}
	else
	{
		for(i=front; i<=rear; i++)
			printf("%d \n", arr[i]);
	}
}

int main()
{
	int choice, item;
	cout<<"Circular Queue Operations:\n"<<endl;
	while(1)
	{
		cout<<"\n1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Traverse"<<endl;
		cout<<"4.Exit"<<endl;

		cout<<"\nEnter a choice:"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1: enqueue();
			break;

			case 2: dequeue();
			break;

			case 3: traverse();
			break;

			case 4: exit(0);

			default: cout<<"Invalid choice."<<endl;
		}
	}
	return 0;
}
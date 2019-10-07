#include<bits/stdc++.h>
using namespace std;

#define size 5
int arr[size];

int front=0, rear=0;

int isEmpty()
{
    return front==rear;
}

int isFull()
{
    return rear==size;
}

void enqueue()
{
    if(isFull())
    {
        cout<<"Overflowed"<<endl;
        return;
    }
    
    int item;
    
    cout<<"Enter an element:"<<endl;
    cin>>item;
    cout<<"Inserted:"<<item<<endl;
    arr[rear]=item;
    rear++;
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"Underflowed"<<endl;
        return;
    }
    cout<<"Deleted:"<<arr[front]<<endl;
    for(int i=0; i<rear-1; i++)
        arr[i]=arr[i+1];
    rear--;
}

void traverse()
{
    for(int i=front; i<rear; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int choice, item;

	cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.Traverse"<<endl;
	cout<<"4.Exit"<<endl;
	while(1)
	{
		cout<<"Enter a choice:"<<endl;
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
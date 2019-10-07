#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

struct node *root=NULL;

void push()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter data:\n";
	cin>>temp->data;

	temp->link=NULL;

	if(root==NULL)
		root=temp;
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}

void traverse()
{
	struct node *temp;
	temp=root;
	if(temp==NULL)
		cout<<"Empty"<<endl;
	else
	{
		cout<<"Traversed data:"<<endl;
		while(temp!=NULL)
		{
			cout<<temp->data<<"-->";
			temp=temp->link;
		}
		cout<<endl;
	}
}

void swap()
{
	struct node *p, *q, *r;
	p=q=r=(struct node*)malloc(sizeof(struct node));

	int i=1, loc;
	cout<<"Enter location:"<<endl;
	cin>>loc;

	p=root;

	while(i<loc-1)
	{
		p=p->link;
		i++;
	}
	q=p->link;
	r=q->link;

	q->link=r->link;
	r->link=q;
	p->link=r;
}

int main()
{
	int choice;
	cout<<"1.Push\n2.Traverse\n3.Swap\n4.Exit\n";
	cout<<endl;
	while(1)
	{
		cout<<"Enter choice:"<<endl;
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
			case 1: push();
				break;
			
			case 2: traverse();
				break;

			case 3: swap(); 
				break;

			case 4: exit(0);
			
			default: cout<<"Invalid choice."<<endl;
		}
		cout<<endl;
	}
	return 0;
}


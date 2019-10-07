#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *root=NULL;
int len;

int length()
{
	struct node *temp;
	int count=0;
	temp=root;

	if(temp==NULL)
		printf("List is empty\n");
	
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp=temp->right;
		}
	}
	return count;
}

void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));

	printf("Enter node data:\n");

	scanf("%d", &temp->data);
	temp->left=NULL;
	temp->right=NULL;

	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}

void addatbegin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data to insert at beginning:\n");
	scanf("%d", &temp->data);

	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		temp->right=root;
		root->left=temp;
		root=temp;
	}
}

void addatafter()
{
	struct node *temp, *p;
	int location, i, len;
	len=length();
	printf("Enter the location to add into:\n");
	scanf("%d", &location);

	if(location>len)
	{
		printf("Invalid location.\n");
		printf("Linked list currently has %d nodes.\n", len);
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
		
		printf("Enter data to insert after the location:\n");
		scanf("%d", &temp->data);
		
		temp->left=NULL;
		temp->right=NULL;
		
		i=1;
		p=root;

		while(i<location)
		{
			p=p->right;
			i++;
		}
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
	}
}

void display()
{
	struct node *temp;
	temp=root;

	if(temp==NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->", temp->data);
			temp=temp->right;
		}
	}
	printf("\n");
}

int main()
{

	int choice;
	printf("\nDouble Linked List Operations:\n\n");
	

	while(1)
	{
		printf("\n1. Append\n");
		printf("2. Addatbegin\n");
		printf("3. Addatafter\n");
		printf("4. Length\n");
		printf("5. Display\n");
		//printf("6. Delete\n");
		printf("7. Quit\n\n");
		
		printf("\nEnter a choice:\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: append();
					break;

			case 2: addatbegin();
					break;

			case 3: addatafter();
					break;

			case 4: len=length();
					printf("Length=%d\n", len);
					break;

			case 5: display();
					break;

			//case 6: deleted();
			//		break;

			case 7: return 0;

			default: printf("Invalid choice\n");
		}
	}
	return 0;
}
#include<stdio.h>
#define capacity 5
int stack[capacity];
int top=-1;

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(capacity-1==top)
		return 1;
	else
		return 0;	
}

void push(int n)
{
	if(isFull()==1)
		printf("Stack is full.\n");
	else
	{
		top++;
		stack[top]=n;
	}
	printf("%d pushed.\n", stack[top]);	
}
int pop()
{
	int n;
	if(isEmpty()==1)
		return 0;
	else
	{
		n=stack[top];
		top--;
	}
	return n;
}

void peek()
{
	if(isEmpty()==1)
		printf("Stack is empty.\n");
	else
		printf("Peek element:%d\n", stack[top]);
}

void traverse()
{
	int i;
	if(isEmpty()==1)
		printf("Stack is empty.\n");
	else
	{
		printf("Traversed element:\n");
		for(i=0; i<=top; i++)
			printf("%d ", stack[i]);
		printf("\n");
	}
}

int main()
{
	int choice, item;

	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Peek\n");
	printf("4.Traverse\n");
	printf("5.Exit\n\n");

	while(1)
	{
		printf("Enter a choice:\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: printf("Enter a element:\n");
					scanf("%d", &item);
					push(item);
					break;

			case 2: item=pop();
					if(item==0)
						printf("Stack is empty.\n");
					else
						printf("Popped item=%d\n", item);
					break;

			case 3: peek();
					break;

			case 4: traverse();
					break;
					
			case 5: return 0;

			default: printf("Invalid choice.\n");
		}
	}
	
	return 0;
}

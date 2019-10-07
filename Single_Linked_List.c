#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *root = NULL;
int len;

int length()
{
	struct node *temp;
	int count = 0;
	temp = root;

	while (temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
}

void append()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	printf("Enter node data:\n");

	scanf("%d", &temp->data);
	temp->link = NULL;

	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *p;
		p = root;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
}

void addatbegin()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter node data to insert at beginning:\n");
	scanf("%d", &temp->data);

	temp->link = NULL;
	temp->link = root;
	root = temp;
}

void addatafter()
{
	struct node *temp, *p;
	int location, i, len;
	len = length();
	printf("Enter the location to add into:\n");
	scanf("%d", &location);

	if (location > len)
	{
		printf("Invalid location.\n");
		printf("Linked list currently has %d nodes.\n", len);
	}
	else
	{
		i = 1;
		p = root;

		while (i < location)
		{
			p = p->link;
			i++;
		}
		temp = (struct node *)malloc(sizeof(struct node));

		printf("Enter data to insert after the location:\n");
		scanf("%d", &temp->data);
		temp->link = NULL;

		temp->link = p->link;
		p->link = temp;
	}
}

void deleted()
{
	struct node *temp;
	int location;
	printf("Enter a location to delete:\n");
	scanf("%d", &location);

	if (location > length())
		printf("Invalid location.\n");

	else if (location == 1)
	{
		temp = root;
		root = temp->link;
		temp->link = NULL;

		free(temp);
	}
	else
	{
		struct node *p, *q;
		p = root;
		int i = 1;
		while (i < location - 1)
		{
			p = p->link;
			i++;
		}
		q = p->link;
		p->link = q->link;
		q->link = NULL;

		free(q);
	}
}

void display()
{
	struct node *temp;
	temp = root;

	if (temp == NULL)
	{
		printf("Linked list is empty.\n");
	}
	else
	{
		while (temp != NULL)
		{
			printf("%d-->", temp->data);
			temp = temp->link;
		}
	}
	printf("\n");
}

void reverse()
{
	int i, j, k, temp;
	struct node *p, *q;

	i = 0;
	j = len - 1;
	p = q = root;

	while (i < j)
	{
		k = 0;
		while (k < j)
		{
			q = q->link;
			k++;
		}
		temp = p->data;
		p->data = q->data;
		q->data = temp;

		i++;
		j--;

		p = p->link;
		q = root;
	}
}

void maximum()
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = root;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	int max = temp->data;

	while (temp != NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->link;
	}

	printf("Maximum: %d\n", max);
}

void minimum()
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = root;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	int min = temp->data;

	while (temp != NULL)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->link;
	}

	printf("Minimum: %d\n", min);
}

void search()
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = root;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	int item, flag = 0;

	printf("Enter search element: ");
	scanf("%d", &item);

	while (temp != NULL)
	{
		if (temp->data == item)
		{
			flag = 1;
			break;
		}
		temp = temp->link;
	}

	flag == 1 ? printf("%d present\n", item) : printf("Not present\n");
}

int main()
{
	/*
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/

	int choice;
	printf("Single Linked List Operations:\n\n");

	while (1)
	{
		printf("\n1. Append\n");
		printf("2. Addatbegin\n");
		printf("3. Addatafter\n");
		printf("4. Length\n");
		printf("5. Display\n");
		printf("6. Delete\n");
		printf("7: Reverse\n");
		printf("8: Maximum\n");
		printf("9: Minimum\n");
		printf("10: Search\n");
		printf("11. Quit\n");

		printf("\nEnter a choice:\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			append();
			break;

		case 2:
			addatbegin();
			break;

		case 3:
			addatafter();
			break;

		case 4:
			len = length();
			printf("Length=%d\n", len);
			break;

		case 5:
			display();
			break;

		case 6:
			deleted();
			break;

		case 7:
			reverse();
			break;

		case 8:
			maximum();
			break;

		case 9:
			minimum();
			break;

		case 10:
			search();
			break;

		case 11:
			return 0;

		default:
			printf("Invalid choice\n");
		}
	}
	return 0;
}

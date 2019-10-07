#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

void push()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    cout << "Enter data:" << endl;
    cin >> temp->data;

    temp->link = top;
    top = temp;
}

void pop()
{
    struct node *temp;

    if (top == NULL)
        cout << "Stack empty." << endl;

    else
    {
        temp = top;
        cout << "Popped Element: " << temp->data << endl;

        top = top->link;
        temp->link = NULL;

        free(temp);
    }
}

void traverse()
{
    struct node *temp;
    if (top == NULL)
        cout << "Stack is empty." << endl;

    else
    {
        temp = top;
        cout << "Traversed data:" << endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
}

int main()
{
    int choice;

    while (1)
    {
        cout << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Traverse" << endl
             << "4. Quit" << endl
             << endl;

        cout << "Enter the choice:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            traverse();
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice." << endl
                 << "Enter choice again:" << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}
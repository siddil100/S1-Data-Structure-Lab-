#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node{
int val;
struct node*next;
};
struct node*head;
void main(){
    int choice;
while (choice!=2)
{
    printf("\n**************Linked Stack***************");
    printf("\n choose one of the options");
    printf("\n 1.push \n 2.pop \n 3.display \n 4.Exit");
    printf("\n Enter your choice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
        push();
        break;
        }
    case 2:
        {
            pop();
            break;
        }
    case 3:
        {
            display();
            break;
        }
    case 4:
        {
            printf("quitting");
            break;
        }
    default:
        {
            printf("invalid choice");
        }

    };
}
}
void push()
{
    int val;
    struct node*ptr=(struct node*)malloc(sizeof(struct node));

        printf("enter the value: ");
        scanf("%d",&val);
        if (head==NULL)
        {
            ptr->val=val;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            ptr->val=val;
            ptr->next=head;
            head=ptr;
        }
        printf("item pushed");
}

void display()
{

    struct node *temp;
    temp=head;
    if(temp == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->val);
            temp = temp->next;
        }
    }
}
void pop()
{
    int item;
    struct node *temp;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = head->val;
        temp = head;
        head = head->next;
        free(temp);
        printf("%d popped",item);

    }
}




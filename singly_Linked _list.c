#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert ();
void lastinsert ();
void randominsert();
void display();
void begin_delete();
void end_delete();
void random_delete();
void main ()
{
    int choice =0;
    while(choice != 8)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.insert end\n3.specific pos\n4.display\n5.beg_delete\n6.end_delete\n7.random_delete\n8.exit");
        printf("\nEnter your choice?\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
            case 1:
            beginsert();
            break;
            case 2:
            lastinsert();
            break;
            case 3:
            randominsert();
            break;
            case 4:
            display();
            break;
            case 5:begin_delete();
            break;
            case 6:end_delete();
            break;
            case 7:random_delete();
            break;
            case 8:
            exit(0);
            default:
            printf("enter a valid choice");
        }
    }
}

void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node *));

        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
           ptr->next=NULL;
           head=ptr;
        }
        else
        {
            ptr->next=head;
            head=ptr;
        }

        printf("\nNode inserted");
    }


void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));

        printf("\nEnter value?\n");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
            head = ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted at end");

        }
    }

void randominsert()
{
    int i,loc,item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));

        printf("\nEnter element value");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert ");
        scanf("\n%d",&loc);
        temp=head;
        for(i=1;i<loc;i++)
        {
            temp = temp->next;
        }
            if(temp == NULL)
            {
                printf("\ncan't insert list empty\n");
                return;
            }
            else
            {
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\nNode inserted");
            }

    }

void display()
{
    struct node *temp;
    temp = head;
    if(temp == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp = temp -> next;
        }
    }
}

void begin_delete()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        printf("\nNode deleted from the begining ...\n");
    }
}

void end_delete()
{
    struct node *temp,*temp1;
    if(head == NULL)
    {
        printf("\nlist is empty");
    }
    else if(head->next==NULL)
    {
         head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp1 = temp;
            temp = temp ->next;
        }
        temp1->next = NULL;
        free(temp);
        printf("\nDeleted Node from the last ...\n");
    }
}

void random_delete()
{
    struct node *temp,*temp1;
    int loc,i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<loc;i++)
    {
        temp1 = temp;
        temp = temp->next;

        if(temp == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    temp1 ->next = temp ->next;
    free(temp);
    printf("\nDeleted node %d ",loc+1);
}

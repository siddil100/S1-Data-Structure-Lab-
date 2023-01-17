#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        printf("\n\n*********Main Menu Doubly*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert at begining\n2.insert at end\n3.Insert-specific pos\n4.Display\n5.begin_delete\n6.end_delete\n7.Specific_delete\n8.EXIT");
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
            case 5:
            begin_delete();
            break;
            case 6:
            end_delete();
            break;
            case 7:
            random_delete();
            break;
            case 8:
            exit(0);
            default:
            printf("Enter a valid choice");
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
            ptr->prev=NULL;
            head=ptr;
            ptr->next=NULL;
        }
        else
        {
            ptr->prev=NULL;
            ptr->next=head;
            head=ptr;
            printf("node inserted & was not empty");
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
void lastinsert()
{
    struct node *ptr,*temp,*temp1;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node *));

        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->prev=NULL;
            head=ptr;
            ptr->next=NULL;
            printf("List was empty,still inserted");
        }
        else
        {
            temp=head;
            while (temp -> next != NULL)
            {
                temp1=temp;
                temp = temp -> next;
            }
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=NULL;
            printf("node inserted at back");
        }
}


void randominsert()
{
    int i,loc,item;
    struct node *ptr,*temp;
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
        if(head==NULL)
        {
            printf("\n cant insert list is empty");
        }
        else
        {
            ptr->next = temp->next;
            ptr -> prev = temp;
            temp->next = ptr;

            printf("\n node inserted at %d",loc);
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
       temp=head;
       head=temp->next;
       free(temp);
       printf("\n Node Deleted");
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
    struct node *temp,*temp1,*prevupd;
    int loc,i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<loc;i++)
    {
        temp1 = temp;
        temp = temp->next;
    }

        if(temp == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    else
    {
    temp1->next=temp->next;
    prevupd=temp->next;
    prevupd->prev=temp1;
    free(temp);
    printf("\nDeleted node %d ",loc);
    }
}




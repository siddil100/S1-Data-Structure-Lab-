#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *f = NULL;
struct node *r = NULL;
void enqueue();
void dequeue();
void display();
void main()
{
int choice=0;
while(choice != 8)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.enqueue\n2.display\n3.dequeue");
        printf("\nEnter your choice?\n");
        scanf("\n%d",&choice);
switch(choice){
			case 1:
                enqueue();
				break;
			case 2:
				display();
				break;
			case 3:
				 dequeue();
				break;

			case 0:
				break;
			default:
				printf("\nInvalid Choice");

		}

}
}
void enqueue()
{


	struct node* n;
	n = (struct node*)malloc(sizeof(struct node));
	printf("Enter the Element");
	scanf("%d",&n->data);

	if((r==NULL)&&(f==NULL))
	{
		f = r = n;
		r->next = f;
	}
	else
	{
		r->next = n;
		r = n;
		n->next = f;
	}
}

void dequeue()
{
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else if(f == r){
		f = r = NULL;
		free(t);
	}
	else{
		f = f->next;
		r->next = f;
		free(t);
	}


}


void display(){
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("--%d",t->data);
			t = t->next;
		}while(t != f);
	}
}



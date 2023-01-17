#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main ()
{
    int choice =0;
    while(choice !=5)
    {
        printf("\nChoose one option\n");
        printf("\n1.Union\n2.Intersection\n3.Difference\n4.exit");
        printf("\nEnter your choice\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
         case 1:Union();
                break;
         case 2:intersection();
                break;
         case 3:difference();
                break;
         case 4:exit(0);
                break;
         default: printf("Please enter a valid choice");

       }
    }
}
void Union()
{

    int n1,n2,n,s1[20],s2[20],s[40],i;
    printf("Enter the number of elements:");
    scanf("%d", &n1);
    printf("Enter the elements:\n");
    for(i=0;i<n1;i++)
        scanf("%d", &s1[i]);
    printf("Enter the number of elements:");
    scanf("%d", &n2);
    printf("Enter the elements:\n");
    for(i=0;i<n2;i++)
        scanf("%d", &s2[i]);
    if(n1!=n2)
        printf("Two sets are not compatible for union.");
    else
    {
        for(i=0;i<n1;i++)
        {
        s[i]=s1[i] || s2[i];
        }
         printf("union is:");
         for(i=0;i<n1;i++)
            printf("%d",s[i]);
    }

}

void intersection()
{
    int n1,n2,n,s1[20],s2[20],s[40],i;
    printf("Enter the number of elements:");
    scanf("%d", &n1);
    printf("Enter the elements:\n");
    for(i=0;i<n1;i++)
        scanf("%d", &s1[i]);
    printf("Enter the number of elements:\n");
    scanf("%d", &n2);
    printf("Enter the elements:\n");
    for(i=0;i<n2;i++)
        scanf("%d", &s2[i]);

    if(n1!=n2)
        printf("Two sets are not compatible for intersection.");
    else
    {
        for(i=0;i<n1;i++)
        {
            s[i]=s1[i] && s2[i];
        }
        printf("the intersection is");
        for(i=0;i<n1;i++)
               printf("%d",s[i]);
    }
}

void difference()
{
    int n1,n2,n,s1[20],s2[20],s[40],i;
    printf("Enter the number of elements:");
    scanf("%d", &n1);
    printf("Enter the elements:\n");
    for(i=0;i<n1;i++)
        scanf("%d", &s1[i]);
    printf("Enter the number of elements:\n");
    scanf("%d", &n2);
    printf("Enter the elements:");
    for(i=0;i<n2;i++)
        scanf("%d", &s2[i]);
    n=n1+n2;
    if(n1!=n2)
        printf("Two sets are not compatible for differnciation.");
    else
    {
        for(i=0;i<n1;i++)
        {
            s2[i]=!s2[i];

        }
        for(i=0;i<n1;i++)
        {
            s[i]=s1[i] && s2[i];
        }
    }
    printf("the difference is");
    for(i=0;i<n1;i++)
        printf("%d",s[i]);
}


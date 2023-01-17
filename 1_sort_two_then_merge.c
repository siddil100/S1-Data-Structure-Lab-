#include<stdio.h>
void main(){
    int a[50],b[50],c[50],m,n,s,i,temp=0,j;
    printf("enter the size of first array ");
    scanf("%d",&m);
    printf("enter the elements of first\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the size of second array ");
    scanf("%d",&n);
    printf("enter the elements of second array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<m-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("sorted first array is\n");
for(i=0;i<m;i++)
{
    printf("%d\n",a[i]);
}
for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(b[j]>b[j+1])
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    printf("sorted second array is\n");
for(i=0;i<n;i++)
{
    printf("%d\n",b[i]);
}
s=m+n;
    for(i=0;i<s;i++)
    {
        a[m+i]=b[i];
    }
    for(i=0;i<s-1;i++)
    {
        for(j=0;j<s-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<s;i++)
    {
        c[i]=a[i];
    }
    printf("sorted final array is\n");
for(i=0;i<s;i++)
{
    printf("%d\n",c[i]);
}
}

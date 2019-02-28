#include<stdio.h>
int a[8]={12,14,27,33,26,17,12,7};
int binarysearch1()
{
    int ub=0;
    int lb=7;
    int mid = (ub+lb)/2;

    while(1)
    {
        if(a[mid]<a[mid+1] && a[mid]>a[mid-1])
        ub=mid+1;
        else if(a[mid]>a[mid+1] && a[mid]<a[mid-1])
        lb=mid-1;
        else if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
        {
         
            break;
        }
    }
    return mid;    
    
    
}
int binarysearch2(int ub , int lb, int item)
{
    int mid=(lb+ub)/2;
    while(ub>lb)
    {
        if(a[mid]>item )
        {
            lb=mid+1;
        }
        else if(a[mid]<item)
        {
            ub=mid-1;
        }
        if(a[mid] == item)
        {
            return mid;
        }
    }
    return -1;

}
int binarysearch3(int ub , int lb, int item)
{
    int mid=(lb+ub)/2;
    while(ub<lb)
    {
        if(a[mid]<item )
        {
            lb=mid+1;
        }
        else if(a[mid]>item)
        {
            ub=mid-1;
        }
        if(a[mid] == item)
        {
            return mid;
        }
    }
    return -1;

}

void main()
{
    int item;
    printf("enter value to search\n");
    scanf("%d",&item);
    int peak = binarysearch1();

    int result1= binarysearch2(0,peak,item);

    printf("result 1 : %d\n",result1);

    int result2 = binarysearch3(peak+1,7,item);
    printf("result 2 : %d",result2);
    
}
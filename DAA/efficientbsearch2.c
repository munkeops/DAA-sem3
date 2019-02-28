#include<stdio.h>
int a[]={53,63,73,83,13,23,33,43};
int binarysearch1()
{
    int lb=0;
    int ub=7;
    int mid = (ub+lb)/2;

    while(1)
    {
         if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
        {
         
            break;
        }
        if( a[mid]>a[0])
        lb=mid+1;
        else if(a[mid]<a[0])
        ub=mid-1;
        
    }
    return mid;    
    
    
}
void main()
{


    int peak=  binarysearch1();
    printf("peak : %d \n",peak);

}
#include<stdio.h>

void main()
{
    int i,j;
     int adjmatrix[7][7]={
        { 0,1,2,3,4,5,6},
        {1,0,5,100,9,100,2},
        {2,5,0,2,100,100,100},
        {3,100,2,0,3,100,100},
        {4,9,100,3,0,2,100},
        {5,100,100,100,2,0,3},
        {6,2,100,100,100,3,0}};

        for(i=0;i<7;i++)
        {
            for(j=0;j<7;j++)
            {
                printf("%d\t",adjmatrix[i][j]);
            }
            printf("\n");
        }

        int sp[7]={100,0,100,100,100,100,100};
        int e[7]={1,1,0,0,0,0,0};

        int count=0;
        int head=1;
        int min=2;
        int k=1;
        while(count<7)
        {
            e[head]=1;
            while(e[k]==1)
            {
                k++;
            }
            min=k;
            for(int i=1;i<7;i++)
            {
                if((sp[i]>(adjmatrix[head][i]+sp[head]))&&(e[i]==0))
                {
                    sp[i]=adjmatrix[head][i]+sp[head];
                }
                if((sp[min]>sp[i]) && e[i]==0 && head!=i)
                {
                    min=i;
                }
                /* printf("\n\n");
                for(j=0;j<7;j++)
                {
                    printf("%d\t",sp[j]);
                } 
                printf("\n%d\n",min);*/
        
            }
            head=min;
            count++;
            //printf("%d %d \n",head,count);
        }
        //printf("hi");
        printf("\n\n");
        for(i=0;i<7;i++)
        {
            printf("%d\t",sp[i]);
        } 
        printf("\n");
        
}
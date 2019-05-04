#include<stdio.h>

void main()
{
    int min,minnode,i,j,inf;
    int adjmatrix[5][5]={
        { 0,1,2,3,4},
        {1,0,8,2,1000},
        {2,1000,0,1000,15},
        {3,6,5,0,7},
        {4,11,7,8,0}};

    int cost=0;

    int table[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d\t",adjmatrix[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            table[i][j]=adjmatrix[i][j];
        }
    }
    

    
    int path[5]={1,0,0,0,0};
    int counter =0;
    int head=1;
    //int neighbour[4]={1000,1000,1000,1000};
    while (counter<5)
    {
        if(head==1)
        {   min=table[head][2];
            minnode=2;
        }
        else
        {
            min=table[head][1];
            minnode=1;
        }
        for(i=1;i<5;i++)
        {
            if(i!=head)        
            {
                if(min>table[head][i])
                {
                    min=table[head][i];
                    minnode=i;
                    cost=cost+table[head][i];
                    
                }
            }
            /*if(head==2)
                    {
                        printf(" min for 2 : %d\n",min);
                    }*/
        }
        if(head==1)
        {
            inf=100;
        }
        else
        {
            inf=1000;
        }
        for(i=1;i<5;i++)
        {
            table[i][head]=inf;
        }
        counter++;
        path[counter]=minnode;
        head=minnode;
       /* for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                printf("%d\t",table[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for(i=0;i<5;i++)
        {
            printf("%d\t",path[i]);
        } 
        printf("\n\n");*/
           
    }
    printf("\n\npath:\t");
     for(i=0;i<5;i++)
        {
            printf("%d\t",path[i]);
        } 
       printf("\n\ncost = %d",cost);
}
#include<stdio.h>


int table[5][5];
int subtable[5][5];

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int cycle_detect()
{
    
	int i,j,k,m;
	//int table[4][4];
    int a[4];
	
	for(i=0;i<4;i++)
	{
		a[i]=-1;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(subtable[i][j]>=1)
			{
				if((a[i]==a[j] && a[i]!=-1)||(a[i]<-1 && a[j]==i)||(a[j]<-1 && a[i]==j))
				{
					//print();
					//printf("cycle detected\n");
                    return 1;
				}
				else
				{
					if(a[i]==-1 && a[j]==-1)
					{
						a[j]=i;
						a[i]=-1;
                       // printf("1\n");
					}
					else if(a[j]==-1 && a[i]>=0)
					{
						a[j]=a[i];
						a[a[i]]-=1;
                        //printf("2\n");

					}
					else if(a[i]==-1 && a[j]>=0)
					{
						a[i]=a[j];
						a[a[j]]-=1;
                        //printf("3\n");

					}
					else if(a[i]>0 && a[j]>0)
					{
                       // printf("4\n");

						if(a[a[i]]<a[a[j]])
						{
							a[a[j]]=a[i];
							for(k=0;k<4;k++)
							{
								if(a[k]==a[j])
								{
									a[k]=a[i];
								}
							}
						}

						if(a[a[i]]>a[a[j]])
						{
							a[a[i]]=a[j];
							for(k=0;k<4;k++)
							{
								if(a[k]==a[i])
								{
									a[k]==a[j];
								}
							}
						}
						

					}
                    else if(a[i]<-1 && a[j]>-1)
                    {
                       // printf("5\n");

                        if(a[i]>a[a[j]])
                        {
                            a[i]=a[a[j]];
                            for(k=0;k<4;k++)
							{
								if(a[k]==i)
								{
									a[k]==a[j];
								}
							}

                        }
                        else
                        {
                            
                            a[a[j]]=a[i];
                            for(k=0;k<4;k++)
							{
								if(a[k]==a[j])
								{
									a[k]==i;
								}
							}                                                
                            
                        }
                        
                    }
                    else if(a[j]<-1 && a[i]>=0)
                    {
                       // printf("6\n");

                        if(a[j]>a[a[i]])
                        {
                            a[j]=a[a[i]];
                            for(k=0;k<4;k++)
							{
								if(a[k]==j)
								{
									a[k]==a[i];
								}
							}

                        }
                        else
                        {
                            a[a[i]]=a[j];
                            for(k=0;k<4;k++)
							{
								if(a[k]==a[i])
								{
									a[k]==j;
								}
							}                                                
                            
                        }
                        
                    }
                    else if(a[j]<-1 && a[i]==-1)
                    {
                       // printf("7\n");

                        a[i]=j;
                    }
                    else if(a[i]<-1 && a[j]==-1)
                    {
                       // printf("8\n");

                        a[j]=i;
                    }                    
				//print();
				}

			}
		}
    }

    return 0;
}

void main()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            table[i][j]=0;
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            subtable[i][j]=0;
        }
    }

    table[0][1]=5;
    table[1][3]=1;
    table[0][3]=2;
    table[0][2]=3;
    table[2][3]=4;
    table[2][1]=4;


    int a[25];
    for(int i=0;i<25;i++)
    {
        a[i]=100;
    }
    //now for krushkals algorithm we must find all the edges and sort them into increasing order.

    int k=0;
    for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(table[i][j]>0)
            {
                a[k]=table[i][j];
                k++;
            }
		}
	}
   
    mergeSort(a,0,24);

    k=0;
    while(a[k]<100)
    {    
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(table[i][j]==a[k])
                {
                    subtable[i][j]=a[k];
                    if(cycle_detect()!=0)
                    {
                        subtable[i][j]=0;                       
                    }
                }
            }
        }
        k++;
    }

    for(i=0;i<4;i++)
    {
        printf("\t%d",i);
    }
    printf("\n");
    for(i=0;i<4;i++)
	{
        printf("%d\t",i);
		for(j=0;j<4;j++)
		{
			printf("%d\t",table[i][j]);
        }
        printf("\n");

	}
    printf("\n");
    

    for(i=0;i<4;i++)
    {
        printf("\t%d",i);
    }
    printf("\n");
    for(i=0;i<4;i++)
	{
        printf("%d\t",i);
		for(j=0;j<4;j++)
		{
			printf("%d\t",subtable[i][j]);
        }
        printf("\n");

	}
    



}
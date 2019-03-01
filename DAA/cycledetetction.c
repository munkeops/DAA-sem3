#include<stdio.h>

int a[10];
void print()
{
int m;
	for(m=0;m<5;m++)
	{
		printf("%d=%d ",m,a[m] );
	}
printf("\n");
}
void main()
{

	int i,j,k,m;
	int table[4][4];
	
	for(i=0;i<5;i++)
	{
		a[i]=-1;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			table[i][j]=0;
		}
	}
	/*for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\n",table[i][j]);
		}
	}*/
	
	table[0][1]=1;
	table[1][2]=1;
	table[3][2]=1;
	table[1][3]=1;
	/*table[1][0]=1;
        table[2][1]=1;
        table[3][2]=1;
        table[1][3]=1;*/

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(table[i][j]==1)
			{
				if(a[i]==a[j] && a[i]!=-1)
				{
					print();
					printf("cycle detected\n");
				}
				else
				{
					if(a[i]<0 && a[j]<0)
					{
						a[j]=i;
						a[i]=-1;
					}
					else if(a[j]<0 && a[i]>=0)
					{
						a[j]=a[i];
						a[a[i]]-=1;
					}
					else if(a[i]<0 && a[j]>=0)
					{
						a[i]=a[j];
						a[a[j]]-=1;
					}
					else if(a[i]>0 && a[j]>0)
					{
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
				print();
				}

			}
		}


}
}

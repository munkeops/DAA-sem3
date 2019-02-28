#include<stdio.h>
#include<stdlib.h>


struct node * head[10];
struct node * trav;


struct node
{
    int data;
    struct link * next;
};

void insert(int val , struct node * head)
{
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp->data=val;
    trav =head;
    struct node * before = trav;

    while (1)
    {
        if(head->next=NULL)
        {
            head = temp;
            temp->next = NULL;
            break;
        }
         if(trav->next == NULL)
        {
            trav->next = temp;
            temp->next= NULL;
            break;
        }
        if(trav->data > val)
        {
            temp->next = trav;
            before->next = temp;
            break;
        }
        before=trav;       
        trav= trav->next;

    }

    
}
void print()
{
    for(int i=0;i<10;i++)
    {
        trav=head[i];
        while(trav->next != NULL)
        {
            printf("%d\n",trav->data);
            trav=trav->next;
        }

    }
}

int hash(int data)
{
    int hash_val=data/10;
    return hash_val;
}


void main ()
{    
    int hash_val[10];
    struct node * head[10];
    int raw_data[10];
    printf("enter 10 values for hashtable\n");
    for (int i=0;i<10;i++)
    {
        //printf("hi");
        scanf("%d",&raw_data[i]);
    }
   /* for (int i =0;i<10;i++)
    {
        printf("%d",raw_data[i]);
    }*/

    for (int i =0;i<10;i++)
    {
        hash_val[i]= hash(raw_data[i]);
        printf("%d",hash_val[i]);

    }

    for (int i =0;i<10;i++)
    {
        insert(raw_data[i],head[hash_val[i]]);
    }

    print();
      

}
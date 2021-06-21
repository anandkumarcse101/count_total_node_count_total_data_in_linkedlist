#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*head=NULL;
void create(int A[],int size)
{    int i;
      struct Node *temp,*last;
      head=(struct Node*)malloc(sizeof(struct Node));
      head->data=A[0];
      head->next=NULL;
      last=head;
      for(i=1;i<size;i++)
      {
          temp=(struct Node*)malloc(sizeof(struct Node));
          temp->data=A[i];
          temp->next=NULL;
          last->next=temp;
          last=temp;


      }

}
int count(struct Node  *p){
    int l=0;
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}
int Rcount(struct Node *p)
{
    if(p!=NULL)
       return Rcount(p->next)+1;
    else
       return 0;
}
int sum(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int Rsum(struct Node *p)
{
    int sum=0;
    if (p!=NULL)
       return Rsum(p->next)+p->data;
    else 
       return 0;
}
int main()
{
int A[]={1,2,3,4,5,6,7,8,9,0};
int size=sizeof(A)/sizeof(A[0]);
create(A,size);
printf("Calculating length without recursive and the total length of the node is=%d\n",count(head));
printf("Calculating length with recursive and the total length of the node is=%d\n",Rcount(head));
printf("Sum of all node data without using recursive is=%d\n",sum(head));
printf("Sum of all node data with using recursive is=%d\n",Rsum(head));

}
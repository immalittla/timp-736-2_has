#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
	}node;
	typedef node *list;
node *head=NULL;	
node *tail=NULL;
	int Empty()
	{
	if((head==NULL)&(tail==NULL))
	return 1;
	else 
	return 0;
	}
void init (int value)
{
 node *tmp=malloc(sizeof(node));
 tmp->value=value;
 tmp->next=NULL;
 tmp->prev=NULL;
 head=tmp;
 tail = tmp;

}
void add(int a)
{
	if (Empty()==1)
	init(a);
	else
	{
		node *tmp=malloc(sizeof(node));
		tmp->value=a;
		tmp->prev=tail;
		tmp->next=NULL;
		tail=tmp;
		tmp->prev=tmp;
		tmp->next=tmp;
	}

}
node *findnum(int b)
{
	node *tmp=head;
	for (int i =1;i<b;i++)
	{
		tmp=tmp->next;
		if(tmp==NULL)
		break;
	}
	return tmp;
}
node *findval(int c){
	node *tmp=head;
	while(tmp!=NULL)
	{
		if(tmp->value!=c)
		tmp=tmp->next;
	}
	return tmp;
}
void addend(int d,int e)
{
	node *tmp=findnum(d);
	if(tmp==tail||tmp==NULL)
	{
		node *tmp1=malloc(sizeof(node));
		tmp1->value=e;
		tmp1->next=NULL;
		tmp1->prev=tail;
		tail=tmp1;
	}
	else
	{
		node *temp = malloc(sizeof(node));
		temp->value=e;
		temp->next=tmp->next;
		temp->prev=tmp;
		tmp->next->prev=temp;
		tmp->next=temp;	
	}

}
void prepend(int d,int e)
{
	node *tmp=findnum(d);
	if(tmp==head||tmp==NULL)
	{
		node *tmp1=malloc(sizeof(node));
		tmp1->value=e;
		tmp1->prev=NULL;
		tmp1->next=head;
		head=tmp1;
		tmp1->next->prev=tmp1;
	}
	else
	{
		node *temp = malloc(sizeof(node));
		temp->value=e;
		temp->prev=tmp->prev;
		temp->next=tmp;
		tmp->prev=temp;
		temp->prev->next=temp;	
	}

}
void print()
{
	node *tmp=head;
	printf("%i",tmp->value);
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
		printf("   ");
		printf("%i",tmp->value);
	}
	printf("\n");

}
void destroy()
{
	if(Empty()==0)
	{
		node *tmp=head;
		node *tmp1=NULL;
		while(tmp!=NULL)
		{
		tmp1=tmp->next;
		free(tmp);
		tmp=tmp1;
		}
		head=NULL;
		tail=NULL;
	}
	
}
void delnom(int d)
{
	 node *tmp=findnum(d);
	 if(tmp==head&&tmp!=NULL)
	 {
	 head=tmp->next;
	 tmp->next->prev=NULL;
	 free(tmp);
	 }
	 if(tmp==tail&&tmp!=NULL)
	 {
	 	tail=tmp->prev;
	 	tmp->prev->next=NULL;
	 	free(tmp);
	 }
	 if (tmp==head&&tmp==tail&&tmp!=NULL)
	 {
	 	tmp->next->prev=tmp->prev;
	 	tmp->prev->next=tmp->next;
	 	free(tmp);
	 }

}
void delval(int c)
{
	node *tmp=findval(c);
	if(tmp==head&&tmp!=NULL)
	 {
	 head=tmp->next;
	 tmp->next->prev=NULL;
	 free(tmp);
	 }
	 if(tmp==tail&&tmp!=NULL)
	 {
	 	tail=tmp->prev;
	 	tmp->prev->next=NULL;
	 	free(tmp);
	 }
	 if (tmp==head&&tmp==tail&&tmp!=NULL)
	 {
	 	tmp->next->prev=tmp->prev;
	 	tmp->prev->next=tmp->next;
	 	free(tmp);
	 }

	
}
int main() 
{
	int n=0;
	int a=0;
	int d=0;
	int c=0;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
	{
		scanf ("%i", &a); 
		add(a); 
	}
	if(Empty()==0)
	print();
	
	scanf("%i",&d);
	delnom(d);
	if(Empty()==0)
	print();
	
	scanf("%i",&c);
	delval(c);
	if(Empty()==0)
	print();
	
	scanf ("%i",&d);
	scanf ("%i", &a);
	addend(d,a);
	if(Empty()==0)
	print();
	
	scanf ("%i",&d);
	scanf ("%i", &a);
	prepend(d,a);
	if(Empty()==0)
	print();
	
	destroy();
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
 
typedef struct list
{
    int el;
    struct list *next;
}list;
 
typedef struct queue
{
   struct list *beg, *end;
}queue;
 
void putToQueue(queue *q, int iEl)   
{
    list *tmp;
    tmp = malloc(sizeof(list));
    tmp->next = NULL;
    tmp->el = iEl;
    if(q->end != NULL)
        q->end->next = tmp;
    else
        q->beg = tmp;
    q->end = tmp;
}
 
int takeFromQueue(queue *q, int *iEl) 
{
    if(q->beg == NULL) return 0;
    list *tmp;
    tmp = q->beg;
    *iEl = tmp->el;
    q->beg = tmp->next;
    free(tmp);
    if(q->beg == NULL) q->end = NULL;
    return 1;
}
 
queue *CreateQueue()            
{
    queue *q;
    q = malloc(sizeof(queue));
    q->beg = NULL;
    q->end = NULL;
    return q;
}
 
int isQueueEmpty(queue *q)      
{
    if(q->beg == NULL) return 1;
    return 0;
}
 
int ClearQueue(queue *q)        
{
    if(q->beg == NULL) return 0;
    list *tmp, *t;
    tmp = q->beg;
    while(tmp->next != NULL)
    {
        t = tmp;
        tmp = t->next;
        free(t);
    }
    q->beg = NULL;
    q->end = NULL;
    return 1;
}
 
void PrintQueue(queue *q)       
{
    printf("\n");
    queue *tmp = CreateQueue(); 
    int iEl;
    while(!isQueueEmpty(q))
    {
        takeFromQueue(q, &iEl);
        printf("%d ", iEl);
        putToQueue(tmp, iEl);
    }
    while(!isQueueEmpty(tmp))
    {
        takeFromQueue(tmp, &iEl);
        putToQueue(q, iEl);
    }
}
void main()
{
    int i;
    int n=0;
    
    queue *q = CreateQueue();
    scanf("%i",&n);
    printf(".......Put Elems..............");
    for(i=0; i<n; i++)
    {
    	
        putToQueue(q, i);
        PrintQueue(q);
    }
    printf("\n......Take Elems...............");
    while(!isQueueEmpty(q))
    {
        takeFromQueue(q, &i);
        PrintQueue(q);
    }
    for(i=0; i<n; i++)
    {
    	
        putToQueue(q, i);
        PrintQueue(q);
    }
printf("\n......clear.....");
    ClearQueue(q);
    PrintQueue(q);
 
    
}

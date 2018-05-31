#include <stdio.h>
#include <stdlib.h>
typedef struct node{
        int value;
        int key;
        struct node *left;
        struct node *right;
        struct node *parent;
} node;

node* freenode(int key, int value){
    node *tmp = malloc(sizeof(node));

    tmp -> value = value;
    tmp -> key = key;

    tmp -> parent = NULL;
    tmp -> left = NULL;
    tmp -> right = NULL;

    return tmp;
}
void insert(node* head, int key, int value)
{
      while (1)
    {
        if(head->key==key)
        {
            head->value=value;
            break;
        }
        if (key>head->key)
                {
                        if (head->right==NULL)
                        {
                                node *tmp = malloc(sizeof(node));
                                head->right = tmp;
                                tmp->key=key;
			                	tmp->value=value;
                                tmp->parent=head;
                                break;
                        }
                        else
                        {
                                head=head->right;
                                continue;
                        }
                }
                if (key<head->key)
                {
                        if (head->left==NULL)
                        {
                                node *tmp = malloc(sizeof(node));
                                head->left = tmp;
                                tmp->key=key;
                                tmp->value=value;
                                tmp->parent=head;
                                break;
                        }
                        else
                        {
                                head=head->left;
                                continue;
                        }
                }
    }
}
int level=0;
 int search(node* head, int key)
 {
     level=level+1;
     if(head ==NULL)
         return -1;
     if(head->key==key)
        return head->value;
     if(key<head->key)
        return search(head->left, key);
     else return search(head->right, key);
 }
int main()
{
    int n,key,value;
    scanf ("%d", &n);
    scanf("%d", &key);
    scanf("%d", &value);
    node *head = freenode(key, value);
   for (int i=1; i<n; i++)
        {
           scanf("%d", &key);
           scanf("%d", &value);
           insert (head, key, value);
        }
        for (int i=0; i<3; i++)
        {
        int tmp=0;
                level=-1;
                scanf("%d", &key);
                tmp=search(head,key);
                if (tmp!=-1)
                printf("%d ", level);
                printf("%d", tmp);
                printf ("\n");
        }
    
}
   



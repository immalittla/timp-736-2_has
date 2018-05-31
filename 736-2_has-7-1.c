#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i, *pmass,a;
  scanf("%d", &n);
  pmass = malloc( sizeof(int[n]));
  for(i=0;i<n;i++)
  {
      scanf("%d", &a);
      pmass[i]=a;
  }
  for(i=0;i<n;i++)
  {
  printf("%d""  ", pmass[i]);
  }
  
 int m,p,f;
 int s=n;
 int c=n;
 while(n>1)
 {
     s=s/1.247f;
     if (s<1)
     {
     s=1;
     }
     f=0;
     for (int i=0; i+s<n;i++)
     {
         if(pmass[i]>pmass[i+s])
         {
             m=pmass[i];
             pmass[i]=pmass[i+s];
             pmass[i+s]=m;
             f=i;
         }
         ++p;
     }
     if (s==1)
     {	
			n=f+1;
     }

 }
 
 printf("\n");
     for(i=0;i<c;i++)
  {
  printf("%d""  ", pmass[i]);
  }

free(pmass);
    return 0;
}

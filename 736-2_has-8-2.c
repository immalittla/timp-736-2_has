#include <stdlib.h>
#include <stdio.h>
void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
    {
        int n, i, *pmass,a,sh=0,b,m;
        scanf("%d", &n);
        pmass = malloc( sizeof(int[n]));
 for(i=0;i<n;i++)
    {
        scanf("%d", &a);
        pmass[i]=a;
    }

while (1)
  {
    b = 0;
    for (i = 0; i < n; ++i)
    {  
      if (i*2 + 2 + sh < n)
      {
        if (pmass[i+sh] > pmass[i*2 + 1 + sh] ||pmass[i + sh] > pmass[i*2 + 2 + sh])
    {
      if (pmass[i*2+1+sh] < pmass[i*2+2+sh])
      {
         
         swap (&pmass[i+sh], &pmass[i*2+1+sh]);
        b = 1;
      }
      else if (pmass[i*2+2+sh] < pmass[i*2+1+sh])
      {
        swap (&pmass[i+sh],&pmass[i*2+2+sh]);
        b = 1;
      }
    }
      }
      else if (i * 2 + 1 + sh < n)
      {
        if (pmass[i+sh] > pmass[i*2+1+sh])
    {
      swap (&pmass[i+sh], &pmass[i*2+1+sh]);
      b=1;
    }
      }
    }
    if (!b) sh++;
    if (sh+2==n)
      break;
}

for(i=0;i<n;i++)
{
printf("%d"" ", pmass[i]);
}
printf("\n");
free(pmass);
return 0;
}


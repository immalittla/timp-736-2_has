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
  int c=n;
 int j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = pmass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < pmass[j - step])
                    pmass[j] = pmass[j - step];
                else
                    break;
            }
            pmass[j] = tmp;
        }
 
 printf("\n");
     for(i=0;i<c;i++)
  {
  printf("%d""  ", pmass[i]);
  }

free(pmass);
    return 0;
}

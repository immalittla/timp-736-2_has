


#include <stdlib.h>
#include <stdio.h>
void xoar(int *pmass, int first,int last)
{
int f =first, l=last,m;
m=pmass[first];
double x=pmass[(first+last)/2];
do
    {
        while(pmass[f]<x) f++;
        while(pmass[l]>x) l--;
        if(f<l)
        {
            if(pmass[f]>pmass[l])
            
            m=pmass[f];
            pmass[f]=pmass[l];
            pmass[l]=m;
        }
        f++;
        l--;
    }while(f<l);
    if (f<last)
    xoar(pmass, f, last);
    if(first<l)
    xoar(pmass, first, l);
}
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

xoar(pmass,0,n-1);
for(i=0;i<n;i++)
{
printf("%d"" ", pmass[i]);
}
printf("\n");
free(pmass);
return 0;
}

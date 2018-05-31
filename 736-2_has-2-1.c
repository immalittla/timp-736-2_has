#include <stdio.h>
 int main()
 {
   int n,i,x,a;
   a=0;
   printf ("Vvedite kolvo chisel n\n");
   scanf ( "%d", &n);
   printf("vvedite x\n");
    for (i=0;i<n;i++)
    {
      scanf("%d",&x);
       if(x>0)
        { 
          a=a+1;
        }       
    }
   printf("kolvo polozhitelnix chisel=");
   printf("%d\n", a);
   return 0;
  }

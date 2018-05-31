#include <stdio.h>
 int main()
 {
   int n,i,x,a;
   a=0;
   printf ("Vvedite kolvo chisel n\n");
   scanf ( "%d", &n);
   printf("vvedite x\n");
    for (i=1;i<=n;i++)
    {
      scanf("%d",&x); 
       a=a+(x-i);
     }
   printf("summa posledovarelnosti chisel=");
   printf("%d\n", a);
   return 0;
  }


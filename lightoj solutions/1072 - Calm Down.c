
/* sin example */
#include <stdio.h>      /* printf */
#include <math.h>       /* sin */
#define PI 3.14159265359
int main ()
{
  double R[1000],r;          // if paramiter =p,
  int n,x[100],i,j=1;             // result = sin (p*PI/180);
  scanf("%d",&n);
  for(i=0;i<n;i++,j++)
  {
      scanf("%lf%d",&R[i],&x[i]);
      r=(sin(PI/x[i])*R[i])/(1+sin(PI/x[i]));
      printf("Case %d: %.15lf\n",j,r);
  }
  return 0;
}

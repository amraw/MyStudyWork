#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int *c,*m,*n,*result,i,t,a,b;
    scanf("%d",&t);
    n=(int*)calloc(t,sizeof(int));
    c=(int *)calloc(t,sizeof(int));
    m=(int *)calloc(t,sizeof(int));
    result=(int *)calloc(t,sizeof(int));
    
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d",(n+i),(c+i),(m+i));
        if(*(n+i) > *(c+i))
        {
            *(result+i)=(*(n+i))/(*(c+i));
        }
        if(*(result+i)>=*(m+i))
        {
            a=*(result+i);
            while(a>=*(m+i))
            {
                b=a%(*(m+i));
                a=a/(*(m+i));
                *(result+i)+=a;
                a+=b;
            }
        }
    }
    for(i=0;i<t;i++)
        printf("%d\n",*(result+i));
    return 0;
}

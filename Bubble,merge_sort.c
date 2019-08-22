#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
int main()
{
    srand(time(NULL));
    FILE *f1,*f2,*f3;
    int i,j=MAX-1;
    f1=fopen("ascending.txt","w+");
    f2=fopen("descending.txt","w+");
    f3=fopen("random.txt","w+");
    for(i=0;i<MAX;i++)
    {
        putw(i,f1);
        putw(j,f2);j--;
        putw(rand()%MAX,f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    i=0;int a;
    int ar[MAX],a1[MAX],b[MAX];
    f1=fopen("ascending.txt","r+");
    while((a=getw(f1))!=EOF)
    {
        ar[i]=a;
        i++;
    }
    fclose(f1);i=0;
    f2=fopen("descending.txt","r+");
    while((a=getw(f2))!=EOF)
    {
        a1[i]=a;
        i++;
    }
    fclose(f2);i=0;
    f3=fopen("random.txt","r+");
    while((a=getw(f3))!=EOF)
    {
        b[i]=a;
        i++;
    }
    fclose(f3);i=0;
        bubsort1(ar,MAX);
         bubsort1(a1,MAX);
         bubsort1(b,MAX);

        bubsort2(ar,MAX);

    bubsort2(a1,MAX);

    bubsort2(b,MAX);


    return 0;
}
int bubsort1(int a[],int n)
{
    time_t start,stop;
    start=clock();
    int i,j,tem;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {

                tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }
        }
    }


            stop=clock();
            /*printf("\n The sorted array is ");
            for(i=0;i<n;i++)
                printf("%d ",a[i]);*/
            printf("\n The time is %lf s",(double)(stop-start)/CLOCKS_PER_SEC);



}
int bubsort2(int a[],int n)
{
    time_t start,stop;
    int t=1,bound=n-1,i,tem;
    start=clock();
    do
    {
        t=0;
        for(i=0;i<bound-1;i++)
        {
            if(a[i]>a[i+1])
            {
                tem=a[i];
                a[i]=a[i+1];
                a[i+1]=tem;
                t=i;
            }
        }bound =t;
    }

while(t>0);
stop=clock();
/*printf("\n The 2nd sorted array is ");
for(i=0;i<n;i++)
    printf("%d ",a[i]);*/
printf("\n The time is %lf s",(double)(stop-start)/CLOCKS_PER_SEC);
return 0;
}

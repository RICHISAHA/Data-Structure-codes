#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int bin(int a[],int value,int n)
{
    int mid,low=0,high=n-1,comp=0;
    if(high<low)
        return -1;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        comp++;
        if(a[mid]>value)
            high=mid-1;
        else if(a[mid]<value)
            low=mid+1;
        else
        {
            printf("\n bin Comparisons %d",comp);
            return mid+1;

        }
    }
    printf("\n bin Comparisons %d",comp);
    return -1;
}
int lin(int a[],int val,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==val)
            return i+1;
    }
    return -1;
}
int inter(int a[],int key,int n)
{
  int low=0,high=n-1,comp=0,mid=0;
  while(a[low]<key && a[high]>=key)
  {
      mid=low+((key-a[low])*(high-low)/(a[high]-a[low]));
      comp++;
      if(a[mid]<key)
      low=mid+1;
      else if(a[mid]>key)
        high=mid-1;
        else
        {
            printf("\n inter Number of comparisons %d",comp);
            return mid+1;
        }

  }
  printf("\n inter comparisons %d",comp);
  if(a[low]==key)
    return low+1;
  else
    return -1;
}
int check(int a[],int n)
{
     int aflag=0,dflag=0,flag,i;
    for(i=0;i<n;i++)
    {
        if(a[i]<a[i+1])
           aflag++;
           else
            dflag++;

    }
    printf(" %d",aflag);
    printf(" %d",dflag);
    if(aflag==n)
        flag=1;
    else if(dflag==n)
        flag=2;
    else
        flag=0;
        printf(" %d",flag);
    return flag;
}
int main()
{
    FILE *f1,*f2,*f3;
    int i,j=MAX-1,p,q,r;
    f1=fopen("asce.txt","w+");
    f2=fopen("desce.txt","w+");
    f3=fopen("ra.txt","w+");
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
    f1=fopen("asce.txt","r+");
    while((a=getw(f1))!=EOF)
    {
        ar[i]=a;
        i++;
    }
    fclose(f1);i=0;
    f2=fopen("desce.txt","r+");
    while((a=getw(f2))!=EOF)
    {
        a1[i]=a;
        i++;
    }
    fclose(f2);i=0;
    f3=fopen("ra.txt","r+");
    while((a=getw(f3))!=EOF)
    {
        b[i]=a;
        i++;
    }
    fclose(f3);i=0;
    int x,m,n,o;
    printf("\n Enter the value to be searched.");
    scanf("%d",&x);
    p=check(ar,MAX);

    if(p==1 || p==2)
    {
        m=inter(ar,x,MAX);
        if(m==-1)
            printf("\n Inter Value not found.");
        else
            printf("\nInter  Value found at %d",(m-1));
        n=bin(ar,x,MAX);
        if(n==-1)
            printf("\n Bin Value not found.");
        else
            printf("\n BIn Value found at %d",(n-1));
    }
    else
    {
        o=lin(ar,x,MAX);
        if(o==-1)
            printf("\n Lin Value not found.");
        else
            printf("\n Lin Value found at %d",o);

    }
    q=check(a1,MAX);

    if(q==1 || q==2 )
    {
        m=inter(a1,x,MAX);
        if(m==-1)
            printf("\n Inter Value not found.");
        else
            printf("\nInter  Value found at %d",(m-1));
        n=bin(a1,x,MAX);
        if(n==-1)
            printf("\n Bin Value not found.");
        else
            printf("\n BIn Value found at %d",(n-1));
    }
    else
    {
        o=lin(a1,x,MAX);
        if(o==-1)
            printf("\n Lin Value not found.");
        else
            printf("\n Lin Value found at %d",o);

    }
    r=check(b,MAX);
    if(r==1 || r==2)
    {
        m=inter(b,x,MAX);
        if(m==-1)
            printf("\n Inter Value not found.");
        else
            printf("\nInter  Value found at %d",(m-1));
        n=bin(b,x,MAX);
        if(n==-1)
            printf("\n Bin Value not found.");
        else
            printf("\n BIn Value found at %d",(n-1));
    }
    else
    {
        o=lin(b,x,MAX);
        if(o==-1)
            printf("\n Lin Value not found.");
        else
            printf("\n Lin Value found at %d",o);

    }
}

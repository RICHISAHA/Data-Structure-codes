#include <stdio.h>
#include <stdlib.h>
#define max 10
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;

    *b=c;

}
int heapify(int heap[],int n)
{
    int i,c,root,temp;
    for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (heap[c] > heap[root])   /* to create MAX heap array */
            {
                swap(&heap[c],&heap[root]);
            }
            c = root;
        } while (c != 0);
    }

    return *heap;
}
int sortedarray(int heap[],int n)
{
    int j,temp,c,root;
  for (j = n- 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];   /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    }
    return *heap;
}
int main()
{
    int i,heap[max],n;
    printf("\n Enter the number of numbers.");
    scanf("%d",&n);
    printf("\n Enter the elements.");
    for(i=0;i<n;i++)
    {
        scanf("%d",&heap[i]);
    }
    heapify(heap,n);
    printf("\n Max heap is ");
    for(i=0;i<n;i++)
    {
        printf(" %d",heap[i]);

    }
    sortedarray(heap,n);
    printf("\n Sorted array is ");
    for(i=0;i<n;i++)
    {
        printf(" %d",heap[i]);

    }


}

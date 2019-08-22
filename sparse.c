#include<stdio.h>
int main()
{
        int A[10][10],B[10][3],C[10][3],D[10][10],i,j,r,c,k=1,m=0,x,y,z,a,b,d;
        printf("Enter the row-size and column-size of the matrix A:\t");
        scanf("%d%d",&r,&c);
        printf("\nEnter the elements for the matrix :\n");
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        scanf("%d",&A[i][j]);   //reading the matrix elements
                }
        }
        printf("\nThe entered Matrix :\n");
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        printf("%d\t",A[i][j]); //displaying the matrix elements
                }
                printf("\n");
        }
        /* Sparse Matrix Triplet Finding Logic*/
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        if(A[i][j]!=0)  //getting the non-zero value
                        {
                                B[k][0]=i;              //row number
                                B[k][1]=j;              //column number
                                B[k][2]=A[i][j];//Non-zero value
                                k++;
                                m++;
                        }
                }
        }
        /*Sparse Matrix Triplets*/
        B[0][0]=r;              //row size
        B[0][1]=c;              //column size
        B[0][2]=m;              //total number of non-zero value
        /*Displaying the Sparse Matrix in Triplet Form */
        printf("\nThe Sparse Matrix triplet Representation is:\n");
        for(i=0;i<k;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("%d\t",B[i][j]);
                }
                printf("\n");
        }
        /*Transpose of the Sparse Matrix Logic*/
        x=B[0][0];      //getting row value
        y=B[0][1];      //getting column value
        z=B[0][2];      //getting non-zero elements

        C[0][0]=y;      //row will be column    //Transposed matrix
        C[0][1]=x;      //column will be row
        C[0][2]=z;      // non-zero elements
        k=1;
        if(z>0)
        {
                for(j=0;j<y;j++)
                {
                        for(i=1;i<=z;i++)
                        {
                                if(B[i][1]==j)
                                {
                                        C[k][0]=B[i][1];
                                        C[k][1]=B[i][0];
                                        C[k][2]=B[i][2];
                                        k++;
                                }
                        }
                }
        }
        /*Displaying the Transposed Sparse Matrix in Triplet Form */
        printf("\nThe Transposed Sparse Matrix in triplet Representation is:\n");
        for(i=0;i<k;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("%d\t",C[i][j]); //Displaying the matrix elements
                }
                printf("\n");
        }
        printf("\n The transpose of the matrix is \n");
       int l=1;

            for(i=0;i<y;i++)
            {
                if(l<=m)
                {

            a=C[l][0];
            b=C[l][1];
            d=C[l][2];
                }
                else
                {
                    a=C[l-1][0];
            b=C[l-1][1];
            d=C[l-1][2];
                }
                for(j=0;j<x;j++)
                {
                    if(i==a&& j==b)
                    D[i][j]=d;
                     else
                        D[i][j]=0;

                }

                l++;
            }


        for(i=0;i<x;i++)
        {

            for(j=0;j<y;j++)
            {

                printf("%d",D[i][j]);
                printf("\t");
            }
            printf("\n");
        }

return 0;
}

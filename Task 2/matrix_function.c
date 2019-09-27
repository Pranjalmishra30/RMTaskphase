#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int N=10; //max value of order

void cofactor(int arr[N][N], int temp[N][N], int p, int q, int n)
{
	int r,c,i=0,j=0;
	for (int r =0;r<n;r++)
	{
	    for (int c=0;c<n;c++)
		{
			if (r!= p && c!= q) //copying those values into temp which are not in the same row and col of arr
			{
				temp[i][j++] = arr[r][c];
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}


int determinant(int arr[N][N], int n)
{
	int i,s=1,det = 0;

	if (n == 1)
		return arr[0][0];

	int temp[N][N]; // To store cofactors
	for (i=0;i<n;i++)
	{
		cofactor(arr, temp, 0, i, n);
		det += s * arr[0][i] * determinant(temp, n - 1);
		s=-s;
	}

	return det;
}

void adjoint(int A[N][N],int adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int s=1,temp[N][N]; //temp stores cofactors

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cofactor(A, temp, i, j, N);

            if( ((i+j)%2)==0 )
                s=1;
            else
                s=-1;

            adj[j][i] = (sign)*(determinant(temp, N-1));//interchanging values of i and j to get its transpose
        }
    }
}
void display(int arr[N][N], int r, int c)
{
    int i,j;
	for (int i = 0; i <r ; i++)
	{
		for (int j = 0; j <c ; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
}

int main()
{
  int A[10][10], B[10][10], C[10][10];
  int n,m,p,q,i,j,k,temp=0;
  float norm=0;
  printf("enter rows and colums of 1st matrix\n");
  scanf("%d %d",&n,&m);
  printf("enter rows and colums of 2nd matrix\n");
  scanf("%d %d",&p,&q);
  if(m!=p)
  {
    printf("matrix can't be multiplied");
    exit(0);
  }
  printf("enter 1st array\n");
  for(i=0;i<n;i++)
   for(j=0;j<m;j++)
     scanf("%d",&A[i][j]);

  printf("enter 2nd array\n");
   for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&B[i][j]);

  //TASK 1
 //Product of matrices.
  for(i=0;i<n;i++)
  {
    for(j=0;j<q;j++)
    {
      C[i][j]=0;
      for(k=0;k<m;k++)
      {
        C[i][j]+=A[i][k]*B[k][j];
      }
    }
  }

  printf("product of matrices is \n");
  display(C,n,q);

  //Norm of matrix
  for(i=0;i<n;i++)
    for(j=0;j<q;j++)
      norm+=C[i][j]*C[i][j];

 printf("\nNorm of the product matrix is %0.3f\n",sqrt(norm));

 //Transpose of matrix
 printf("\nTranspose of the product matrix is \n");
  for(i=0;i<n;i++)
  {
    printf("\n");
    for(j=0;j<q;j++)
      printf("%d\t",C[j][i]);
  }

  //TASK 2
  //Determinant of matrix
  int D=determinant(C,n);
  printf("\nDeterminant of the matrix is : %d\n",D);

  //finding inverse
  if(D==0)
    printf("inverse can't be found\n");
  else
    int adj[N][N],inverse[i][j];
    adjoint(C, adj);
  for (int i=0; i<n; i++)
      for (int j=0; j<q; j++)
            inverse[i][j] = adj[i][j]/float(D);

   display(inverse,n,q);

}

#include<stdio.h>
#include<stdlib.h>
int** two_dimensional(int *arr,int n,int *total_rows,int *sizes_of_each_row)/*To access an element or to define array size, you can’t use array indexing/defining with []
operator. In other words, your code mustn’t contain any third bracket []
operator. */
{
  int **a=(int**)malloc(n*sizeof(int*));
  int i;
  for(i=0;i<n;i++)
  {
    a[i]=(int*)malloc(sizes_of_each_row[i]*sizeof(int));
  }
  *total_rows=n;
  for(i=0;i<n;i++)
  {
    arr[i]=sizes_of_each_row[i];
  }
  return a;
}
void printing2D(int **a,int *sizes_of_each_row,int rows)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<sizes_of_each_row[i];j++)
        {
        printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}
void sorting2D(int **a,int *sizes_of_each_row,int rows)
{
    int i,j,k;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<sizes_of_each_row[i];j++)
        {
            for(k=0;k<sizes_of_each_row[i]-j-1;k++)
            {
                if(a[i][k]>a[i][k+1])
                {
                    int temp=a[i][k];
                    a[i][k]=a[i][k+1];
                    a[i][k+1]=temp;
                }
            }
        }
    }
}
int main()
{
    /*
sample input:
20
5 10 15 20 -1 20 11 2 -1 5 17 11 22 50 12 -1 2
9 7 11
sample output:
Generated 2D array:
5 10 15 20
20 11 2
5 17 11 22 50 12
2 9 7 11
After Sorting:
5 10 15 20
2 11 20
5 11 12 17 22 50
2 7 9 11
code in such way so that it matches the sample output
    */
    int n;
    scanf("%d",&n);
    int *sizes_of_each_row=(int*)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&sizes_of_each_row[i]);
    }
    int *arr=(int*)malloc(n*sizeof(int));
    int **a=two_dimensional(arr,n,&n,sizes_of_each_row);
    for(i=0;i<n;i++)
    {
        for(int j=0;j<sizes_of_each_row[i];j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Generated 2D array:\n");
    printing2D(a,sizes_of_each_row,n);
    sorting2D(a,sizes_of_each_row,n);
    printf("After Sorting:\n");
    printing2D(a,sizes_of_each_row,n);
    return 0;
    /*int n;
    scanf("%d",&n);
    int *sizes_of_each_row=(int*)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&sizes_of_each_row[i]);
    }
    int *arr=(int*)malloc(n*sizeof(int));
    int **a=two_dimensional(arr,n,&n,sizes_of_each_row);
    for(i=0;i<n;i++)
    {
        for(int j=0;j<sizes_of_each_row[i];j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Generated 2D array:\n");
    printing2D(a,sizes_of_each_row,n);
    sorting2D(a,sizes_of_each_row,n);
    printf("After Sorting:\n");
    printing2D(a,sizes_of_each_row,n);
    return 0;
*/
}
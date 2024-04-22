#include <stdio.h>
int main() {
  int x,y,a[10][10],b[10][10],sum[10][10],i,j;
  printf("Enter the number of rows : ");
  scanf("%d", &x);
  printf("Enter the number of columns : ");
  scanf("%d", &y);
  printf("\nEnter elements of 1st matrix:\n");
  for (i = 0; i < x; ++i)
    for (j = 0; j < y; ++j) {
      printf("Enter element a[%d][%d]: ", i, j);
      scanf("%d", &a[i][j]);
    }
   printf("\n1st matrix is_ _\n");
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }

  printf("\nEnter elements of 2nd matrix:\n");
  for (i = 0; i < x; ++i)
    for (j = 0; j < y; ++j) {
      printf("Enter element b[%d][%d]: ", i, j);
      scanf("%d", &b[i][j]);
    }
   printf("\n2nd matrix is_ _\n");
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                printf("%d\t",b[i][j]);
            }
            printf("\n");
        }
  for (i = 0; i < x; ++i)
    for (j = 0; j < y; ++j) {
      sum[i][j] = a[i][j] + b[i][j];
    }
  printf("\nSum of two matrices: \n");
  for (i = 0; i < x; ++i){
    for (j = 0; j < y; ++j) {
      printf("%d\t", sum[i][j]);
    //   if (j == y-1) {
    //     printf("\n\n");
    //   }
    }
    printf("\n");
  }


    return 0;

}
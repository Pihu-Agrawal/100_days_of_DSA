/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/
#include<stdio.h>
int main(){
    int r,c;
    printf("enter number of rows and column:");
    scanf("%d %d",&r,&c);
    printf("enter matrix elemnets:\n");
    int matrix[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("enter matrix[%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);

        }
    }
    //adding diagonal elements
    int sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==j){
                sum=sum+matrix[i][j];
            }
    }
}
    printf("sum=%d",sum);
    return 0;
}

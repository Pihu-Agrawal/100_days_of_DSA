/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
#include<stdio.h>
int power(int x,int y);
int main(){
    int n,p;
    //input number and its power.
    scanf("%d %d",&n,&p);
    //printing power of the number
    printf("%d",power(n,p));
    return 0;

}
//recursion for finding power of the number
int power(int x,int y){
    if(y==0){
        return 1;
    }
    else{
        return x*power(x,y-1);
    }
}





/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include<stdio.h>
#include<string.h>
int main(){
    char string[50];
    //input the string
    scanf("%s",string);

    int start=0;
    int end=strlen(string)-1;

    char new_string[50];
    strcpy(new_string,string);
    char temp;
    
    while(start<end){
        temp=new_string[start];
        new_string[start]=new_string[end];
        new_string[end]=temp;
        start++;
        end--;

    }
    if(strcmp(new_string,string)==0){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
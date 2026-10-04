#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char text[100];
    char pattern[50];

    printf("Enter the text:");
    gets(text);
    printf("Enter the Pattern:");
    gets(pattern);

    int appearonce = 0;

    for(int i=0;i<=strlen(text)-strlen(pattern);i++){
        int found = 0;
        for(int j=0; j<strlen(pattern);j++){
            if(text[i+j] == pattern[j]){
                if(j == strlen(pattern)-1){
                    found=1;
                    appearonce= 1;
                }
            }else{
                break;
            }
        }
        if(found == 1){
            printf("Pattern Found at %d index\n",i);
        }
    }

    if(appearonce == 0){
        printf("Pattern Not Found");
    }
}
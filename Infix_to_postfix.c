#include <stdio.h>
#include <string.h>
#define MAX 100 
void post_evaluation(char *str ){
    for (int i =0; i<strlen(str) ; i++ ){
        printf("%c", str[i]);

    }
}
int main(){
    char st[3]="123";
    printf("%d", (int)(*st));
    char exp [MAX];
    printf("Enter the exp:-");
    gets(exp);
    puts(exp);
    post_evaluation(exp);
    return 0;
}
    
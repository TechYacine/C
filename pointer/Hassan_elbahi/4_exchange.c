#include<stdio.h>
#include<stdlib.h>
void exchange(int *p, int *p2) {
    if ((*p) * (*p2) > 0) {
        int k = *p;
        *p = *p2;
        *p2 = k;
    } else {
        int k = *p + *p2;
        int j = (*p) * (*p2);
        *p = k;
        *p2 = j;
    }
}
int main(){
    int a,b;
    int *p = &a;
    int *p2 = &b;
    printf("Enter the value of 'a' \n");
    scanf("%d", p);
    printf("Enter the value of 'b' \n ");
    scanf("%d", p2);
    exchange(p, p2);
    printf("Enter the value of 'a' %d \n ", *p);
    printf("Enter the value of 'b' %d \n", *p2);

    return 0;
}
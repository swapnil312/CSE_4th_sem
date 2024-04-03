# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int sum(int count){
    if(count == 0) return 0;
    srand(time(0));
    return rand()+sum(--count);
}

int main(){
    int count = 10;
    printf("Sum of 10 random numbers using recursion = %d",sum(count));
    return 0;
}
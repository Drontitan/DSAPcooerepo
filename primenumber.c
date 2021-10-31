#include <stdio.h>
void primenumbers(int start,int end){
    for (int i = start; i <= end; i++)
    {
        if (i == 1 || i == 0)
            continue;
       int  count = 1;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                count = 0;
                break;
            }
        }
        if (count == 1){
          printf("%d ", i);
        }
    }
}
int main(){
    int start,end;
    printf("Enter the the start and end of the prime number\n");
    scanf("%d",&start);
    scanf("%d",&end);
   primenumbers(start,end);
    return 0;
}
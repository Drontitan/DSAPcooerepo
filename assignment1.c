#include <stdio.h>
void enterelement(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
int  addition(int arr[] ,int n){
    int sum=0;
  for (int i = 0; i < n; i++)
  {
      sum+=arr[i];
  }
  return sum;
}
int multiplication(int arr[], int n)
{
    int mul=1;
    for (int  i = 0; i <n; i++)
    {
        mul=mul*arr[i];
    }
    return mul;
}
int division (int arr[])
{
    int divi;
    divi=arr[0]/arr[1];
    return divi;
}
int subtraction(int arr[])
{
    int subs;
    subs = arr[0] - arr[1];
    return subs;
}
int main(){
    int n;
    printf("Enter the number of input you want\n");
    scanf("%d",&n);
    int arr[n];
    int choice;
    printf("Enter the value for the operations\n");
    enterelement(arr, n);
    printf("Enter the choice you want for addition-1  multiplication-2 division-3 substraction-4  \n");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("The addition of the numbers are %d \n", addition(arr, n));
            break;
        case 2:
            printf("The multiplication of the numbers are %d \n", multiplication(arr, n));
            break;
        case 3:
            printf("The division of the numbers are %d \n", division(arr));
            break;
        case 4:
            printf("The substraction of the numbers are %d \n",  subtraction(arr));
            break;
    }

    return 0;
}
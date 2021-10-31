#include <stdio.h>
struct price{
    int productcode;
    int price;
    char name[100];
};
void print(struct price p ){
    printf("The product code of the item is : %d\n",p.productcode );
    printf("The name  of the item is : %s \n",p.name );
    printf("The  price of the item is  : %d \n",p.price );

}
int main(){
    struct price p;
    printf("Enter the product code of the item\n");
    scanf("%d",&p.productcode);
    printf("Enter the Name  of the item\n");
    scanf("%s",p.name);
    printf("Enter the price of the item\n");
    scanf("%d",&p.price);
   print(p);
    return 0;
}
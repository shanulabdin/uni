#include <stdio.h>

int calDel(int);

int main(){
  int order = 0, delivery = 0, total = 0;

  printf("Enter total Bill: ");
  scanf("%d", &order);

  delivery = calDel(order);
  total = delivery + order;

  printf("\nDelivery charges: %d\n", delivery);
  printf("Total: %d", total);

  return 0;
}

int calDel(int order){
  int delivery = order >= 1000 ? 0 : 150;
  
  return delivery;
}
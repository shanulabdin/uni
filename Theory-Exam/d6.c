#include <stdio.h>

float price(float cost);

int main(){
  float cost = 3000.0;
  float newCost;

  for(int i = 0; i<4; i++){
    newCost = price(cost);
    printf("Cost of month %d: %.2f\n", i+1, newCost);
    cost = newCost;
  }

  return 0;
}

float price(float cost){
  float newPrice = (cost * 0.08) + cost;

  return newPrice;
}
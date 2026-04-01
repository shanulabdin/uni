#include <stdio.h>

int main()
{
  float phy, chem, eng, PF, total;
  float per;

  printf("enter the marks in Physics: ");
  scanf("%f", &phy);
  printf("enter the marks in Chemistry: ");
  scanf("%f", &chem);
  printf("enter the marks in English: ");
  scanf("%f", &eng);
  printf("enter the marks in PF: ");
  scanf("%f", &PF);

  total = phy + chem + eng + PF;
  per = (total / 400) * 100;

  switch (per)
  {
    case 90 ... 100:
      printf("Your Grade is A.");
      break;
    
    case 80 ... 89:
      printf("Your Grade is B.");
      break;
    
    case 70 ... 79:
      printf("Your Grade is C.");
      break;
    
    case 60 ... 69:
      printf("Your Grade is D.");
      break;
    
    break;
      printf("You have Failed.");
    
  }

  printf("enter the marks in Physics: ");
  scanf("%f", &Total);


  return 0;
}
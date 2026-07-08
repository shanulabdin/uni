#include <stdio.h>

float AOR(float *w, float *l, float *area, float *per);

int main()
{
  float w, l;
  float area, per;
  printf("Enter the width and length: ");
  scanf("%f %f", &w, &l);

  AOR(&w, &l, &area, &per);

  printf("Area: %.2f\n", area);
  printf("Perimeter: %.2f", per);
  return 0;
}

float AOR(float *w, float *l, float *area, float *per)
{
  *area = (*w) * (*l);
  *per = 2 * (*w) + 2 * (*l);
}

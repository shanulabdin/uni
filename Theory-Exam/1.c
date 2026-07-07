#include <stdio.h>
#include <string.h>
int main()
{
  char str1[20] = "ABCDEFGHIJK";
  char str2[40] = "Yes, this is happening";
  int s, i;
  s = strlen(str1);
  for (i = 0; i <= s; i++)
  {
    printf("%c", str2[i]);
  }
  return 0;
}

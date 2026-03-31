#include <stdio.h>
#include <ctype.h>

int main() 
{
  char letter;
  char lower_letter;

  printf("Enter a Letter: ");
  scanf("%c", &letter);

  lower_letter = tolower(letter);

  switch(lower_letter){
    case 'a': printf("%c is a Vowel.", letter); break;
    case 'e': printf("%c is a Vowel.", letter); break;
    case 'i': printf("%c is a Vowel.", letter); break;
    case 'o': printf("%c is a Vowel.", letter); break;
    case 'u': printf("%c is a Vowel.", letter); break;
    
    default: printf("%c is a Consonant.", letter);
  }
  return 0;
}
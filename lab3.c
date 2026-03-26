// task 1
#include <stdio.h>

int main()
{
  int num1, num2, num3;

  printf("Enter Number 1: \t");
  scanf("%d", &num1);
  printf("Enter Number 2: \t");
  scanf("%d", &num2);
  printf("Enter Number 3: \t");
  scanf("%d", &num3);

  if (num1 > num2)
  {
    if (num1 > num3)
    {
      printf("%d is largest", num1);
    }
    else
    {
      printf("%d is largest", num3);
    }
  }
  else
  {
    if (num2 > num3)
    {
      printf("%d is largest", num2);
    }
    else
    {
      printf("%d is largest", num3);
    }
  }

  return 0;
}
int main() {
    float marks;
    printf("Enter your marks: \t");
    scanf("%f", &marks);
    
    if (marks >= 90)
    {
        printf("Grade A");
    } else if (marks >= 80)
    {
        printf("Grade B");
    } else if (marks >= 70)
    {
        printf("Grade C");
    } else if (marks >= 60)
    {
        printf("Grade D");
    } else if (marks < 60)
    {
        printf("Grade F");
    }

    return 0;
}

int main() {
    int age;
    printf("Enter your Age: \t");
    scanf("%d", &age);
    
    if (age >= 18)
    {
        printf("You can Vote.");
    } else 
    {
        printf("You can NOT Vote.");
    }

    return 0;
}

int main() {
    char letter;
    printf("Write a letter: ");
    scanf("%c", &letter);
    
    switch(letter){
        case 'a':
            printf("%c is a Vowel.", letter);
            break;
        case 'e':
            printf("%c is a Vowel.", letter);
            break;
        case 'i':
            printf("%c is a Vowel.", letter);
            break;
        case 'o':
            printf("%c is a Vowel.", letter);
            break;
        case 'u':
            printf("%c is a Vowel.", letter);
            break;
        default:
            printf("%c is a Consonant.", letter);
    }
    return 0;
}
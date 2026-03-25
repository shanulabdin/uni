#include <stdio.h>
int main()
{
	int number;
	printf("Enter the number ");
	scanf("%d",&number);
	if (number%2 == 0)
	{
		printf("%d is an even number",number);
	}
	else
	{
		printf("%d is an odd number",number);
		
	}
	return 0;
}

#include <stdio.h>
#include <ctype.h>

int main() {
    char guess;
    printf("Guess the first letter: ");
    scanf("%c", &guess);
    
    if(toupper(guess) == 'N')
    {
        printf("Right guess.");   
    } 
    else 
    {
        printf("Wrong guess.");  
    }

    return 0;
}
#include <stdio.h>

int main()
{
    char ch;
    char *p = &ch;

    int characters = 0;
    int words = 1;

    printf("Enter a sentence ending with '.': ");

    while (1)
    {
        scanf("%c", p);

        if (*p == '.')
            break;

        if (*p != ' ')
            characters++;
        else
            words++;
    }

    printf("Characters = %d\n", characters);
    printf("Words = %d\n", words);

    return 0;
}
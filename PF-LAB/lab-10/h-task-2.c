#include <stdio.h>

void reverseString(char str[], int left, int right)
{
    if (left >= right)
        return;

    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    reverseString(str, left + 1, right - 1);
}

int main()
{
    char str[100];
    int len = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[len] != '\0')
    {
        len++;
    }

    reverseString(str, 0, len - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}
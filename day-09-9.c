// A secret system stores code names in forward order. To display them in mirror format, 
//you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
void reverse(char str[], int index)
{
    if (index < 0)
        return;

    printf("%c", str[index]);
    reverse(str, index - 1);
}
int main()
{
    char code[100];
    int length = 0;

    printf("Enter the code name: ");
    scanf("%s", code);

    while (code[length] != '\0')
        length++;

    printf("Mirror format: ");
    reverse(code, length - 1);

    return 0;
}

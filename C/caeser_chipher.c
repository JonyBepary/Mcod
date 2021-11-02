#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_this_a_letter(char *character)
{
    if (*character >= 'A' && *character <= 'Z' || *character >= 'a' && *character <= 'z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void caeser_encrypt(char text[], int shift)
{
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (is_this_a_letter(&text[i]))
        {
            text[i] = text[i] + shift;
        }
    }
}

void caeser_decrypt(char text[], int shift)
{
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (is_this_a_letter(&text[i]))
        {
            text[i] = text[i] - shift;
        }
    }
}

int main(int argc, char const *argv[])
{
    char text[] = "Hello.";
    caeser_encrypt(text, 3);
    printf("%s\n", text);
    caeser_decrypt(text, 3);
    printf("%s\n", text);
    printf("\n");
}

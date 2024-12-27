#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char paragraph[1000];
    int sentences = 0;
    int letter = 0;
    int words = 1;
    float index = 0.0;

    printf("Text: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    for (int i = 0, len = strlen(paragraph); i < len; i++)
    {

        if (isalpha(paragraph[i]))
        {
            letter++;
        }
        else if (paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!')
        {
            sentences++;
        }
        else if (paragraph[i] == ' ')
        {
            words++;
        }
    }

    index = 0.0588 * (((float) letter * 100) / words) -
            0.296 * (((float) sentences * 100) / words) - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}
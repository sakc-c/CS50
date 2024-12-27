#include <cs50.h>
#include <stdio.h>

void pyramid(int h);

int main(void)
{
    int height;
    do
    {
        height = get_int("Please enter height between 1 and 8: ");
    }
    while (height < 1 || height > 8);

    pyramid(height);
}

void pyramid(int h)
{
    for (int rows = 0; rows < h; rows++)
    {
        for (int j = 0; j < (h - rows - 1); j++)
        {
            printf(" ");
        }
        for (int i = 0; i <= rows; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = 0; z <= rows; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int cash = 0;

    do
    {
        cash = get_int("change required (in cents): ");
    }
    while (cash < 0);

    do
    {
        if (cash >= 25)
        {
            cash = cash - 25;
            quarters++;
        }

        else if (cash >= 10)
        {
            cash = cash - 10;
            dimes++;
        }

        else if (cash >= 5)
        {
            cash = cash - 5;
            nickels++;
        }

        else if (cash >= 1)
        {
            cash = cash - 1;
            pennies++;
        }
    }
    while (cash > 0);

    printf("minimum coins needed: %i\n", quarters + dimes + nickels + pennies);
}
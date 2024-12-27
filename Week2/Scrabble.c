#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(char word[]);

int main(void)
{
    // Prompt the user for two words

    char word1[50];
    char word2[50];

    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);

    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("player 1 wins\n");
    }
    else if (score2 > score1)
    {
        printf("player 2 wins\n");
    }
    else
    {
        printf("Tie");
    }
}

int compute_score(char word[])
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }

        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }
    return score;
}
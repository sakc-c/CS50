#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Only one argument allowed\n");
        return 1;
    }

    char *image = argv[1];

    FILE *card = fopen(image, "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", image);
        return 1;
    }

    uint8_t buffer[512];
    int i = 0;
    FILE *img = NULL;
    char filename[8];

    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img); // Close the previously opened file
            }

            sprintf(filename, "%03i.jpg", i++);
            img = fopen(filename, "w");
            if (img == NULL) // Check if the file opened successfully
            {
                printf("Could not create %s.\n", filename);
                return 1;
            }
            fwrite(buffer, 1, 512, img);
        }

        else if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(img);
    fclose(card);

    return 0;
}

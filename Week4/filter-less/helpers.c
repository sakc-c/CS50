#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j].rgbtBlue + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen;
            image[i][j].rgbtRed = image[i][j].rgbtGreen;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // get values according to the given equation. //
            int sepiaRed   = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue  = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // cap the component values to 255. //
            if (sepiaRed   > 255)
                sepiaRed   = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue  > 255)
                sepiaBlue  = 255;

            // update the pixel values //
            image[i][j].rgbtRed   = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue  = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j] = image[i][j];
        }
     }
     for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int blue  = 0;
            int red   = 0;
            int green = 0;
            double counter = 0;
            for (int s = i - 1; s < i + 2; s++) {
                // check for top and bottom edge //
                if (s < 0 || s >= height)
                    continue;
                for (int m = j - 1; m < j + 2; m++) {
                    // check for left and right edge //
                    if (m < 0 || m >= width)
                        continue;
                    red   += copy[s][m].rgbtRed;
                    green += copy[s][m].rgbtGreen;
                    blue  += copy[s][m].rgbtBlue;
                    counter += 1;
                }
            }
            image[i][j].rgbtRed   = round(red   / counter);
            image[i][j].rgbtGreen = round(green / counter);
            image[i][j].rgbtBlue  = round(blue  / counter);
        }
    }
}

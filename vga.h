/* The VGA framebuffer starts at 0xB8000. */
unsigned char *video_memory = (unsigned char*)0xB8000;

/* The VGA text mode has 80 columns and 25 rows. */
const int width = 80;
const int height = 25;

/* Clear the screen by writing spaces to every cell in the framebuffer. */
void clear_screen()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            /* Calculate the index in the framebuffer. */
            int index = (y * width * 2) + (x * 2);  /* 2 bytes per character (char + color). */

            /* Write a space character with white foreground and black background. */
            video_memory[index] = ' ';
            video_memory[index + 1] = 0x0F;  /* White foreground, black background. */
        }
    }
}


/* Put a character on the screen at a given position. */
void put_char(char c, int x, int y, int color)
{
    /* Calculate the index in the framebuffer. */
    int index = (y * width * 2) + (x * 2);  /* 2 bytes per character (char + color). */

    /* Write the character with the specified color attributes. */
    video_memory[index] = c;
    video_memory[index + 1] = color;
}


/* Put a string on the screen at a given position. */
void put_string(char *str, int x, int y, int color)
{
    /* Iterate through the string and put each character on the screen. */
    for (int i = 0; str[i] != '\0'; i++)
    {
        put_char(str[i], x + i, y, color);
    }
}
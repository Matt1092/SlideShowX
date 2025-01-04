// Include necessary libraries
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "dirent.h"


// Define SPIF_UPDATEINFILE for use 
#ifndef SPIF_UPDATEINFILE
#define SPIF_UPDATEINFILE 0x01
#endif
// Define constants for Array sizing
#define MAX_STRINGS 256
#define MAX_LENGTH 256


// Main function
int main(void)
{
    // Declare folder name as Array of characters
    char foldername[MAX_PATH];
    // Include DIR functionalities
    DIR *dir;
    struct dirent* ent;
    // Create array of characters
    char strings[MAX_STRINGS][MAX_LENGTH];
    // Initialize update time and count
    float updateTime;
    int count = 0;
    // Initialize file and original file
    char file[MAX_LENGTH * 4];
    char file_orig[MAX_PATH];
    int loop = 1;


    printf("C code application to spice up your desktop wallpapers\n");
    // Prompt user for update refresh time for wallpaper display
    printf("Update time (in minutes): ");
    scanf_s("%f", &updateTime);


    // Prompt user for file path
    printf("File path: ");
    scanf_s("%s", foldername, sizeof(foldername));


    // Instructions for runtime
    printf("Press q to exit program");


    // Use open directory for folder name
    if ((dir = opendir(foldername)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
            // Check for file extension, if not an image file skip (png/jpeg/jpg/bmp/etc)
            if (!strstr(ent->d_name, "png") && !strstr(ent->d_name, "jpeg") && !strstr(ent->d_name, "jpg") && !strstr(ent->d_name, "btm"))
            {
                continue;
            }
            else
            {
                strcpy_s(strings[count], sizeof(strings[count]), ent->d_name);
                count++;
            }
        }
        closedir(dir);
    }
    else {
        /* could not open directory */
        perror("");
        return EXIT_FAILURE;
    }
    // Revert back to original desktop file
    SystemParametersInfoA(SPI_GETDESKWALLPAPER, MAX_PATH, (void*)file_orig, 0);


    // While loop to go through the wallpapers until user presses escape key
    while (1 == loop)
    {
        // Loop through Array of string filenames and update wallpaper based on user input for update time
        for (int i = 0; i < count; i++)
        {
            strcpy_s(file, sizeof(file), foldername);
            strcat_s(file, sizeof(file), "\\");
            strcat_s(file, sizeof(file), strings[i]);
            // Windows API function used to set system parameters. Sets desktop wallpaper that doesn't require a wide string
            // Integer value storing return value of SystemParametersInfoA function call
            // Non-zero - success, zero - failure)
            int returnValue = SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void*)file, SPIF_UPDATEINFILE);
            // Call sleep function to update wallpaper after elapsed time
            Sleep(updateTime * 60000);
            // Check if return value is non-zero (true)
            if (returnValue)
            {
                printf("Wallpaper set successfully. \n");
            }
            // Check if return value is zero (false)
            else
            {
                printf("Failed to set wallpaper. Error code: %d\n", GetLastError());
                continue;
            }
            if (_kbhit())
            {
                // If keyboard detects q key, break the for loop and exit the while loop
                if (_getch() == 'q')
                {
                    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void*)file_orig, SPIF_UPDATEINFILE);
                    loop = 0;
                    break;
                }
            }
        }
    }
    // Revert back to original desktop file
    SystemParametersInfoA(SPI_GETDESKWALLPAPER, MAX_PATH, (void*)file_orig, 0);
    return 0;
}

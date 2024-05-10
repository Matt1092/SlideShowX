// Include necessary libraries
#include <windows.h>
#include <stdio.h>


// Define SPIF_UPDATEINFILE for use 
#ifndef SPIF_UPDATEINFILE
#define SPIF_UPDATEINFILE 0x01
#endif


// Main function
int main(void)
{
    // Declare a character array with maximum size of up to 256 characters
    char foldername[256];

    printf("C code application to spice up your desktop wallpapers\n");
    printf("Folder name: ");

    // Prompt user for folder name
    scanf_s("%s", foldername, sizeof(foldername));
    
    // Pointer to a wide character string
//    const wchar_t *file = L"C:\\Users\\mattm\\OneDrive\\Desktop\\whitecolour.png"; // Change this to the path of your image file
    const wchar_t* file = L"C:\\Users\\mattm\\OneDrive\\Desktop\\forest.png"; // Change this to the path of your image file

    // Windows API function used to set system parameters. Sets desktop wallpaper
    // Integer value storing return value of SystemParametersInfoW function call
    int returnValue = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)file, SPIF_UPDATEINFILE);
    // Non-zero - success, zero - failure)

    // Check if return value is non-zero (true)
    if (returnValue) {
        printf("Wallpaper set successfully.\n");
    // Check if return value is zero (false)
    } else {
        printf("Failed to set wallpaper. Error code: %d\n", GetLastError());
    }
    return 0;
}

# Wallpaper Slideshow for Windows

This C program updates the user's desktop wallpaper in the form of a slideshow, using images from a specified directory. Users can set the refresh interval for updating the wallpaper.

## Features

- Automatically updates the desktop wallpaper with images from a specified directory.
- Supports common image formats such as PNG, JPEG, JPG, and BMP.
- Allows users to set the refresh interval in minutes.
- Reverts to the original wallpaper upon exit.

## Requirements

- Windows OS
- C compiler (e.g., GCC)
- Windows API
- `dirent.h` library for directory operations

## Usage

1. **Clone the Repository**
    ```sh
    git clone https://github.com/yourusername/wallpaper-slideshow.git
    cd wallpaper-slideshow
    ```

2. **Compile the Program**
    Use a C compiler to compile the program. For example, with GCC:
    ```sh
    gcc -o wallpaper_slideshow wallpaper_slideshow.c -luser32
    ```

3. **Run the Program**
    ```sh
    ./wallpaper_slideshow
    ```

4. **Provide Input**
    - **Update Time**: Enter the desired update interval in minutes.
    - **File Path**: Enter the path to the directory containing the images.

5. **Exit the Program**
    - Press `q` to exit the program and revert to the original wallpaper.

## Example

```sh
C:\> wallpaper_slideshow.exe
C code application to spice up your desktop wallpapers
Update time (in minutes): 5
File path: C:\Users\YourUsername\Pictures\Wallpapers
Press q to exit program
```

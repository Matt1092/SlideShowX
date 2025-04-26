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
    git clone https://github.com/Matt1092/WallpaperSlideshow.git
    cd WallpaperSlideshow
    ```

2. **Compile the Program**
    Use a C compiler to compile the program. For example, with GCC:
    ```sh
    gcc -o wallpaper_slideshow slideshow_wallpaper.c -luser32
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

## Code Explanation

### Libraries and Constants

- **Libraries**: Includes necessary libraries such as `windows.h`, `stdio.h`, `conio.h`, and `dirent.h`.
- **Constants**: Defines constants for array sizing.

### Main Function

- **Initialization**: Declares and initializes variables for folder name, directory operations, image list, update time, etc.
- **User Input**: Prompts the user for the update time and file path.
- **Directory Reading**: Reads the specified directory and filters image files (PNG, JPEG, JPG, BMP).
- **Original Wallpaper**: Stores the original wallpaper to revert upon exit.
- **Slideshow Loop**: Updates the wallpaper at specified intervals and checks for user input to exit.

### Functions Used

- **SystemParametersInfoA**: Windows API function to get and set system parameters, including the desktop wallpaper.
- **_kbhit** and **_getch**: Functions to detect keyboard input for exiting the program.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue to discuss potential changes.


## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Inspired by the need to dynamically update desktop wallpapers.


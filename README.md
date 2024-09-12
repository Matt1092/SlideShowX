# Wallpaper Application
This is a program I made in C that updates the desktop display of a user given a file folder and desired refresh time. I automated this visual task with the use of
a Windows API to modify the desktop displays. POSIX-compliant directory handling functions are used to repeatedly loop through image files in a folder the user must specify. 
This program prompts the user for the path of a file folder, loops through the files forever and applies a new wallpaper to the desktop, until user presses escape key 'q'.
(Program only accepts.png, .jpg, .jpeg and .btm files).

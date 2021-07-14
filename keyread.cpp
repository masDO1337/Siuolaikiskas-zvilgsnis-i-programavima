#include <linux/input.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd = 0;
    char device[PATH_MAX];

    /*
    *
    *This code finds the first keyboard device in /dev/input/by-path/
    *
    */

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("/dev/input/by-path/")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
             if(strstr(ent->d_name, "kbd") != NULL)
             {
                sprintf(device, "/dev/input/by-path/%s", ent->d_name);
             }
        }
        closedir (dir);
    }

    /*
    *
    *This code reads the keyboard buffer and prints the key code
    *
    */

    while(true)
    {
        // Read the key from the keyboard buffer
        int fd1 = 0;
        if((fd1 = open(device, O_RDONLY)) > 0 )
        {
            struct input_event event;
            unsigned int key = 0;
            read(fd1, &event, sizeof(struct input_event));
            key = event.value; //seems contrary to documentation, but it works(mostly)

            printf("Key Code: %d\n", key);
        }

    }
}

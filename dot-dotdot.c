/**
 * @author Timo Grautstueck
 * 
 * This program searches for the same
 * inode in/as the specified DIRECTORY.
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

#define DIRECTORY "/home/"

int
main(void)
{
    DIR *d;
    struct dirent *dir;
    unsigned long tmp_ino;
    char *tmp_d_name;

    if((d = opendir(DIRECTORY)) == NULL)
        perror("Could not open the directory");
    
    if((dir = readdir(d)) == NULL) {
        perror("Could not readdir: ");
        return EXIT_FAILURE;
    }

    tmp_ino = dir->d_ino;
    tmp_d_name = dir->d_name;

    while((dir = readdir(d)) != NULL) {
        perror("readdir(): ");
        if(tmp_ino == dir->d_ino)
            printf("Found same INODE: %d for {%s} and {%s} !!!\n",
            tmp_ino, tmp_d_name, dir->d_name);
        
        printf("After readdir: %s, %d\n", dir->d_name, dir->d_ino);
    }   

    if(closedir(d) == 0)
        printf("Closed: %s!\n", DIRECTORY);

    return EXIT_SUCCESS;
}
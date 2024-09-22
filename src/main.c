#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int usage(int argc, char *argv[]) {
    printf("Usage: %s [-c] [-i] [filename]\n-i | installs a .op package\n-c | start the package creation wizard\n", argv[0]);
    return 1;
}

void remove_last_4_chars(char *str) {
    size_t len = strlen(str); // Get the length of the string
    if (len > 4) {
        str[len - 4] = '\0'; // Set the 5th to last character as null terminator
    } else {
        str[0] = '\0'; // If the string has 4 or fewer characters, make it empty
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return usage(argc, argv);
    }
    
    if (argc == 2 && strcmp(argv[1], "-c") == 0) {
        char pkg_name[25];
        char pkg_command[320];
        printf("Package creation wizard\n");
        printf("Input package name:\n");
        scanf("%s", pkg_name);
        sprintf(pkg_command, "mkdir %s && cd %s && wget https://raw.githubusercontent.com/bit-sync/ops/refs/heads/main/pkgs/INSTALL.sh && wget https://raw.githubusercontent.com/bit-sync/ops/refs/heads/main/pkgs/example.txt && wget https://raw.githubusercontent.com/bit-sync/ops/refs/heads/main/pkgs/Makefile", pkg_name, pkg_name);
        system(pkg_command);
        printf("Package %s created successfully.\n", pkg_name);
    }
    
    if (argc == 3 && strcmp(argv[1], "-i") == 0) {
        char pkg_install_cmd[100];
        char removed_path[150];
        
        // Check to ensure argv[2] exists
        if (argc < 3) {
            return usage(argc, argv);
        }

        strcpy(removed_path, argv[2]); // Use argv[2], not argv[3]
        remove_last_4_chars(removed_path); // Pass the full string, not a character
        
        sprintf(pkg_install_cmd, "tar -xf %s && bash INSTALL.sh && rm -rf %s", argv[2], removed_path);
        system(pkg_install_cmd);
    } 
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int usage(int argc, char *argv[]) {
    printf("Usage: %s\n", argv[0]);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
                return usage(argc, argv);
    }
    if (argc == 2 && strcmp(argv[1], "-c") == 0) {
        char pkg_name[25];
        char pkg_command[25];
        printf("Package creation wizard\n");
        printf("Input package name:\n");
        scanf("%s", pkg_name);
        sprintf(pkg_command, "mkdir %s && c", pkg_name);
        system(pkg_command);
        printf("Package %s created successfully.\n", pkg_name);
    }
}
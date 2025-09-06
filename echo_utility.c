#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int echo_main(int argc, char *argv[]) {
    // Start from i=1 to skip the program name (argv[0])
    for (int i = 1; i < argc; i++) {
        // Print the argument
        if (printf("%s", argv[i]) < 0) {
            perror("printf");
            return EXIT_FAILURE;
        }
        
        // Add space between arguments (except after the last one)
        if (i < argc - 1) {
            if (putchar(' ') < 0) {
                perror("putchar");
                return EXIT_FAILURE;
            }
        }
    }
    
    // Add newline at the end
    if (putchar('\n') < 0) {
        perror("putchar");
        return EXIT_FAILURE;
    }
    
    // Flush stdout to ensure output is written
    if (fflush(stdout) == EOF) {
        perror("fflush");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
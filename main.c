#include <stdio.h>

int main(void) {
    int operation;

    char* reset = "\033[0m";  
    char* red = "\033[31m";     
    char* green = "\033[32m";   
    char* yellow = "\033[33m";  

    printf("WELCOME TO THE CALCULATOR! \n");
    
    printf("\n%sCHOOSE AN OPERATION:%s\n", yellow, reset);
    printf("%s1. ADDITION\n", green);
    printf("%s2. SUBTRACTION\n", green);
    printf("%s3. MULTIPLICATION\n", green);
    printf("%s4. DIVISION\n", green);
    printf("%sENTER YOUR CHOICE: %s", yellow, reset);
    
    if (scanf("%d", &operation) != 1) {
        printf("%sINVALID INPUT, PLEASE ENTER A NUMBER.\n%s", red, reset);
        return 1;
    }

    if (operation < 1 || operation > 4) {
        printf("%sINVALID OPERATION, PLEASE CHOOSE BETWEEN 1 AND 4.\n%s", red, reset);
        return 1;
    }

    return 0;
}

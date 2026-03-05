#include <stdio.h>

int main(void) {
    char* reset = "\033[0m";  
    char* green = "\033[32m";   
    char* yellow = "\033[33m";  

    printf("WELCOME TO THE CALCULATOR! \n");
    
    printf("\n%sCHOOSE AN OPERATION:%s\n", yellow, reset);
    printf("%s1. ADDITION\n", green);
    printf("%s2. SUBTRACTION\n", green);
    printf("%s3. MULTIPLICATION\n", green);
    printf("%s4. DIVISION\n", green);
    printf("%sENTER YOUR CHOICE: %s", yellow, reset);

    return 0;
}

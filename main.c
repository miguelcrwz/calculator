#include <stdio.h>

int main(void) {
    double num1, num2, result;
    int operation;

    char* reset = "\033[0m";  
    char* red = "\033[31m";     
    char* green = "\033[32m";   
    char* yellow = "\033[33m";  
    char* magenta = "\033[35m"; 

    printf("WELCOME TO THE CALCULATOR! ⚒︎\n");
    
    printf("\n%s CHOOSE AN OPERATION:%s\n", yellow, reset);
    printf("%s1. ADDITION\n", green);
    printf("%s2. SUBTRACTION\n", green);
    printf("%s3. MULTIPLICATION\n", green);
    printf("%s4. DIVISION\n", green);
    printf("%s Enter your CHOICE: %s", yellow, reset);
    
    if (scanf("%d", &operation) != 1) {
        printf("%s✘ INVALID INPUT, PLEASE ENTER A NUMBER.\n%s", red, reset);
        return 1;
    }

    if (operation < 1 || operation > 4) {
        printf("%s✘ INVALID OPERATION, PLEASE CHOOSE BETWEEN 1 AND 4.\n%s", red, reset);
        return 1;
    }

    printf("%s\nEnter THE FIRST NUMBER: %s", magenta, reset);
    if (scanf("%lf", &num1) != 1) {
        printf("%s✘ INVALID INPUT, PLEASE ENTER A NUMBER.\n%s", red, reset);
        return 1;
    }

    printf("%sEnter THE SECOND NUMBER: %s", magenta, reset);
    if (scanf("%lf", &num2) != 1) {
        printf("%s✘ INVALID INPUT, PLEASE ENTER A NUMBER.\n%s", red, reset);
        return 1;
    }

    switch (operation) {
        case 1:
            result = num1 + num2;
            printf(" %sRESULT: %.2lf\n%s", green, result, reset);
            break;
        case 2:
            result = num1 - num2;
            printf(" %sRESULT: %.2lf\n%s", green, result, reset);
            break;
        case 3:
            result = num1 * num2;
            printf(" %sRESULT: %.2lf\n%s", green, result, reset);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf(" %sRESULT: %.2lf\n%s", green, result, reset);
            } else {
                printf("%s✘ ERROR! DIVISION BY ZERO IS NOT ALLOWED.\n%s", red, reset);
            }
            break;
    }

    return 0;
}

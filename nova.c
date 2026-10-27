#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 100

int main(void) {
    int choice;
    int running = 1;
    double num1, num2, result;
    double history[MAX_HISTORY];
    int historyCount = 0;

    while (running) {
        printf("=========================================\n");
        printf("        PROJECT NOVA v1.0\n");
        printf("=========================================\n");
        printf("System Status: ONLINE\n\n");
        printf("1. C Programming Notes\n");
        printf("2. Calculator\n");
        printf("3. About NOVA\n");
        printf("4. View Calculation History\n");
        printf("5. Open Google Chrome\n");
        printf("6. Shutdown\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please restart NOVA and enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("\n==========================================\n");
                printf("        C PROGRAMMING NOTES\n");
                printf("==========================================\n\n");
                printf("1. printf(): used to print output.\n");
                printf("2. scanf(): used to take input.\n");
                printf("3. Variables: used to store data.\n");
                printf("4. Data types: int, float, char, etc.\n");
                printf("5. Operators: +, -, *, /, etc.\n");
                printf("6. Control structures: if, else, switch, loops.\n");
                printf("7. Functions: used to perform specific tasks.\n");
                break;

            case 2:
                while (1) {
                    printf("\n==========================================\n");
                    printf("           SMART CALCULATOR\n");
                    printf("==========================================\n");
                    printf("1. Addition (+)\n");
                    printf("2. Subtraction (-)\n");
                    printf("3. Multiplication (*)\n");
                    printf("4. Division (/)\n");
                    printf("5. Remainder (%%)\n");
                    printf("6. Reset Calculator and History\n");
                    printf("7. Exit Calculator\n");
                    printf("\nEnter your choice: ");

                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input. Please restart NOVA and enter a number.\n");
                        return 1;
                    }

                    if (choice == 7) {
                        printf("\nNOVA: Calculator closed.\n");
                        break;
                    }

                    if (choice == 6) {
                        historyCount = 0;
                        printf("\nNOVA: Calculator history cleared.\n");
                        continue;
                    }

                    if (choice < 1 || choice > 7) {
                        printf("NOVA: Invalid choice. Try again.\n");
                        continue;
                    }

                    printf("Enter first number: ");
                    if (scanf("%lf", &num1) != 1) {
                        printf("Invalid number. Please restart NOVA.\n");
                        return 1;
                    }

                    printf("Enter second number: ");
                    if (scanf("%lf", &num2) != 1) {
                        printf("Invalid number. Please restart NOVA.\n");
                        return 1;
                    }

                    int validResult = 1;

                    switch (choice) {
                        case 1:
                            result = num1 + num2;
                            printf("\nNOVA: Result = %.2f\n", result);
                            break;
                        case 2:
                            result = num1 - num2;
                            printf("\nNOVA: Result = %.2f\n", result);
                            break;
                        case 3:
                            result = num1 * num2;
                            printf("\nNOVA: Result = %.2f\n", result);
                            break;
                        case 4:
                            if (num2 == 0) {
                                printf("\nNOVA: Cannot divide by zero.\n");
                                validResult = 0;
                            } else {
                                result = num1 / num2;
                                printf("\nNOVA: Result = %.2f\n", result);
                            }
                            break;
                        case 5:
                            if (num2 == 0 ||
                                num1 != (int)num1 ||
                                num2 != (int)num2) {
                                printf("\nNOVA: Remainder requires whole numbers and a nonzero second number.\n");
                                validResult = 0;
                            } else {
                                result = (int)num1 % (int)num2;
                                printf("\nNOVA: Remainder = %.2f\n", result);
                            }
                            break;
                    }

                    if (validResult) {
                        if (historyCount < MAX_HISTORY) {
                            history[historyCount] = result;
                            historyCount++;
                        } else {
                            printf("NOVA: History is full; this result was not saved.\n");
                        }
                    }
                }
                break;

            case 3:
                printf("\nNOVA: I am your personal study assistant.\n");
                break;

            case 4:
                printf("\n--- Calculation History ---\n");
                if (historyCount == 0) {
                    printf("No calculations recorded yet.\n");
                } else {
                    for (int i = 0; i < historyCount; i++) {
                        printf("%d. Result = %.2f\n", i + 1, history[i]);
                    }
                }
                break;

            case 5:
                printf("\nNOVA: Opening Google Chrome...\n");
                if (system("open -a \"Google Chrome\"") != 0) {
                    printf("NOVA: Could not open Google Chrome. Check that it is installed.\n");
                }
                break;

            case 6:
                printf("\nNOVA: Shutting down. Goodbye!\n");
                running = 0;
                break;

            default:
                printf("\nNOVA: Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <ctype.h>

int calculate(const char *expression) {
    int result = 0, curnum = 0;
    char curope = '+'; 

    while (*expression != '=') {
        if (isdigit(*expression)) {
            curnum = curnum * 10 + (*expression - '0');
        } else if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
            if (curope == '+') {
                result += curnum;
            } else if (curope == '-') {
                result -= curnum;
            } else if (curope == '*') {
                result *= curnum;
            } else if (curope == '/') {
                if (curnum == 0) {
                    printf("ERROR\n");
                    return -1;
                }
                result /= curnum;
            }

            curope = *expression;
            curnum = 0;
        } else {
            printf("ERROR\n");
            return -1;
        }

        expression++;
    }

    if (curope == '+') {
        result += curnum;
    } else if (curope == '-') {
        result -= curnum;
    } else if (curope== '*') {
        result *= curnum;
    } else if (curope == '/') {
        if (curnum == 0) {
            printf("ERROR\n");
            return -1;
        }
        result /= curnum;
    }

    return result;
}

int main() {
    char expression[100];
    scanf("%s", expression);

    int result = calculate(expression);
    if (result != -1) {
        printf("%d\n", result);
    }

    return 0;
}

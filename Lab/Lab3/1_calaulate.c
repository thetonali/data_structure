#include <stdio.h>
#include <ctype.h>

int calculate(const char *expression) {
    int result = 0, curnum = 0;
    char curope = '+'; 

    while (*expression != '=') {
        if (isdigit(*expression)) {
            curnum = curnum * 10 + (*expression - '0');
        } else if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
            // 遇到运算符时，先根据上一个操作符计算
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

            // 更新当前操作符
            curope = *expression;
            curnum = 0;
        } else {
            // 非法字符
            printf("ERROR\n");
            return -1;
        }

        expression++;  // 继续处理下一个字符
    }

    // 最后一个数字和操作符的处理
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

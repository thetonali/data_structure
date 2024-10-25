#include <stdio.h>

long long GCD(long long a, long long b) {
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a > b)
        a %= b;
    else
        b %= a;

    return GCD(a, b);  // 返回递归调用的结果
}

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    long long gcd = GCD(a, b);

    // 先将一个数除以GCD，避免 a * b 的溢出
    long long lcm = (a / gcd) * b;

    printf("%lld\n", lcm);  // 输出最小公倍数
    return 0;
}

/*
* 1. 递归方法（慢）
  直接递归计算斐波那契数列并取模的复杂度是指数级的，
  这对大n不适用。这种方法时间复杂度是 𝑂(2^𝑛),适合较小的n。
* 2. 迭代方法（线性时间）
  使用迭代的方法计算斐波那契数列并对每一步结果取模m，
  时间复杂度为 𝑂(𝑛)。
  这种方法对于n较大的情况，如 n=10^6，仍然会花费一些时间。
* 3. 快速矩阵幂方法（对大 n 高效）
  快速矩阵幂是最快的方式，可以在 𝑂(log𝑛)的时间复杂度内
  计算第n个斐波那契数，并且可以直接对结果进行取模m。
*/

#include <stdio.h>
//2.迭代方法（线性时间）
long long fibonacci(long long n, long long m) {
    if (n == 0)
        return 0;
    long long a = 0, b = 1;
    for (long long i = 2; i <= n; i++) {
        long long next = (a + b) % m;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", fibonacci(n, m));
    return 0;
}


//3. 快速矩阵幂方法（对大 n 高效）
void multiply(long long F[2][2], long long M[2][2], long long m) {
    long long x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % m;
    long long y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % m;
    long long z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % m;
    long long w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % m;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(long long F[2][2], long long n, long long m) {
    if (n == 0 || n == 1)
        return;

    long long M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2, m);
    multiply(F, F, m);  // F = F^2 (square the matrix)

    if (n % 2 != 0)
        multiply(F, M, m);  // If n is odd, multiply by M one more time
}

long long fibonacci(long long n, long long m) {
    if (n == 0)
        return 0;

    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1, m);
    return F[0][0];  // F[0][0] will be F(n) mod m
}

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", fibonacci(n, m));
    return 0;
}

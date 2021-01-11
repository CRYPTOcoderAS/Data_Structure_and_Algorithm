/*
Author: Kumar Shanu
Program: nth fibnacci number
*/

#include <stdio.h>
#include <string.h>

/**
 * @brief recursive function for nth fibnacci number
 * Time Complexity: O(2^n)
 * @param n(int) integer number
 * @return nth term in fibnacci series
 */
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int memo[50];
/**
 * @brief fibnacci recursive function with memorization
 * @param n(int) integer number
 * @return nth term in fibnacci series
 */
int fib(int n)
{
    if (n <= 1)
        return n;

    int first, second;

    if (memo[n - 1] != -1)
        first = memo[n - 1];
    else
        first = fib(n - 1);

    if (memo[n - 2] != -1)
        second = memo[n - 2];
    else
        second = fib(n - 2);

    return memo[n] = first + second;
}

/**
 * @brief iterative function using dynamic programming
 * Time Complexity: O(n)
 * Space: O(n)
 * @param n(int) integer number
 * @return int
 */
int fib(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    memset(memo, -1, sizeof(memo));

    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("\nnth fibnacci number %d\n", fib(n));

    return 0;
}

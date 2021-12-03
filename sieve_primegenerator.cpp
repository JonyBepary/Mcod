// Author Jony Bepary
// 2021
// @jbeary
// http://jony-blog.github.io/
#include <iostream>
#include <math.h>

int prime[300000], nPrime;
int mark[100000002];
void sieve(int n)
{
    int i, j, limit = sqrt(n * 1.0) + 2;

    for (int i = 4; i < n + 1; i += 2)
        mark[i] = 1;
    prime[nPrime++] = 2;
    for (i = 3; i < n + 1; i++)
    {
        if (!mark[i])
        {
            prime[nPrime++] = i;
            if (i <= limit)
            {
                for (int j = i; j < n + 1; j += i * 2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    sieve(50);
    std::cout << nPrime << "\n";
    for (int i = 0; i < nPrime; i++)
    {

        std::cout << prime[i] << "\n";
    }

    return 0;
}

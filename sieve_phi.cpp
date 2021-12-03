#include <iostream>
#include <math.h>

int phi[1000006], mark[1000006];
using namespace std;
void sieve_phi(int n)
{
    int i, j;
    for (int i = 1; i < n + 1; i++)
    {
        phi[i] = i;
    }
    phi[i] = 1;
    mark[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        if (!mark[i])
        {
            for (int j = i; j < n + 1; j = j + i)
            {
                mark[j] = 1;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int n = 100;
    sieve_phi(n);

    for (int i = 1; i < n + 1; i++)
    {
        printf("%d: %d\n", i, phi[i]);
    }

    return 0;
}

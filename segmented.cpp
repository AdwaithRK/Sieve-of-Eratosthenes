#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<int> *sevie(int n)
{
    bool sieve[n + 1];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    vector<int> *result = new vector<int>();

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                sieve[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == true)
        {
            result->push_back(i);
        }
    }

    return result;
}

vector<int> *segmentedSieve(int low, int high, vector<int> possiblePrimeFactors)
{
    bool result[high - low + 1];
    memset(result, true, sizeof(result));

    for (auto i : possiblePrimeFactors)
    {

        int base = floor(low / i) * i;

        if (base < low)
            base += i;

        for (int k = base; k <= high; k += i)
        {
            if (k % i == 0)
                result[k - low] = false;
        }
    }

    vector<int> *primeInRange = new vector<int>();

    for (int i = 0; i < high - low + 1; i++)
    {
        if (result[i])
            primeInRange->push_back(i + low);
    }

    return primeInRange;
}

int main()
{
    vector<int> *results = sevie(sqrt(50));
    vector<int> *primeInRange = segmentedSieve(10, 50, *results);

    


    return 0;
}
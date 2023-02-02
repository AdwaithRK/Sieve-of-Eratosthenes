#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
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

    if(low == 1) result[0] = false;
    if(low == 0){
        result[low] = false;
        result[low+1] = false;
    }

    for (auto i : possiblePrimeFactors)
    {

        int base = floor(low / i) * i;

        if (base < low)
            base += i;


        for (int k = base; k <= high; k += i)
        {
            result[k - low] = false;
        }

        if (base == i)
            result[base - low] = true;
    }

    vector<int> *primeInRange = new vector<int>();

    for (int k = low; k <= high; k++)
    {
        if (result[k - low])
            primeInRange->push_back(k);
    }

    return primeInRange;
}

int main()
{
    vector<int> *results = sevie(sqrt(1000000));
    vector<int> *primeInRange = segmentedSieve(1, 1000000, *results);
    vector<int> answer = {-1, -1};

    if (primeInRange->size() == 0)
        return 0;

    int distance_btw_primes = INT_MAX;

    for (int i = 0; i < primeInRange->size() - 1; i++)
    {
        if (primeInRange[0][i + 1] - primeInRange[0][i] < distance_btw_primes)
        {
            distance_btw_primes = primeInRange[0][i + 1] - primeInRange[0][i];
            answer[0] = primeInRange[0][i];
            answer[1] = primeInRange[0][i + 1];
        }
    }

    return 0;
}
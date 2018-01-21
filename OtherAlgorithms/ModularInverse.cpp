#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;


//The modular multiplicative inverse is an integer ‘x’ such that.
//a^x ≡ 1 (mod m)
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

void modInverse(int a, int m) //Works when m and a are coprime
{
    //The idea is to use Extended Euclidean algorithms that takes two integers ‘a’ and ‘b’
    //finds their gcd and also find ‘x’ and ‘y’ such that
    //ax + by = gcd(a, b)
    //To find multiplicative inverse of ‘a’ under ‘m’, we put b = m in above formula.
    //Since we know that a and m are relatively prime, we can put value of gcd as 1.
    //ax + my = 1
    //We can remove the second term on left side as ‘my (mod m)’ would always be 0 for an integer y.
    //ax  ≡ 1 (mod m)

    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }
}
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

void modInverse2(int a, int m) //Works when m is prime
{
    //If we know m is prime, then we can also use Fermats’s little theorem to find the inverse.
    //a^(m-1) ≡ 1 (mod m)
    //If we multiply both sides with a^-1, we get
    //a^-1 ≡ a^(m-2) (mod m)

    int g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m-2, m);
    }
}


int main() {

}

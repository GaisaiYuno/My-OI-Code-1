#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

const long long MANY = 5e18;

// a * b >= c ? 
bool cmp(long long a, long long b, long long c)
{
    if (a == 0 || b == 0)
        return c == 0;
    if (MANY / a <= b)
        return true;
    return a * b >= c;
}

int main()
{
    ifstream in("a.in");
    ofstream out("a.out");
    long long n, a, b, w, h;
    in >> n >> a >> b >> w >> h;
    
    long long left = 0;
    long long right = w;
    while (right - left > 1)
    {
        long long mid = (left + right) / 2;
        long long w1 = w / (a + 2 * mid);
        long long h1 = h / (b + 2 * mid);
        long long w2 = w / (b + 2 * mid);
        long long h2 = h / (a + 2 * mid);
        if (cmp(w1, h1, n) || cmp(w2, h2, n))
            left = mid;
        else
            right = mid;
    }
    out << left << "\n";
}

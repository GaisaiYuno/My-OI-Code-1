#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 150;
long long c[MAXN][MAXN];
long long MOD = (long long)(1e+9+7);

void initC() {
    for (int i = 0; i < MAXN; i++) {
        c[i][0] = (i == 0) ? 1 : 0;   
    }
    for (int i = 1; i < MAXN; i++) {
        c[i][0] = 1;
        for (int j = 1; j < MAXN; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }
}

bool fine(string number) {
    for (unsigned int i = 1; i < number.length(); i++) {
        if (number[i] < number[i-1]) {
            return false;
        }
    }
    return true;
}

vector<int> stringToArray(string number) {
    vector<int> res;
    for (unsigned int i = 0; i < number.length(); i++) {
        res.push_back(number[i] - '0');
    }
    return res;
}


long long numberOfPut(int places, int digits) {
    return c[places + digits - 1][digits - 1];
}

long long countNumbers(vector<int> number) {
    int n = number.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int prev = (i == 0) ? 0 : number[i - 1];
        if (number[i] < prev) {
            return ans;
        }
        for (int j = prev; j < number[i]; j++) {
            ans = (ans + numberOfPut(n - i - 1, 10 - j)) % MOD;
        }
    }
    return ans;
}


int main()
{
    initC();
    string l, r;
    ifstream in("b.in");
    in >> l >> r;
    long long ans = countNumbers(stringToArray(r)) - countNumbers(stringToArray(l));
    if (fine(r)) {
        ans++;
    }
    ans = (ans % MOD + MOD) % MOD;		
    ofstream("b.out") << ans << "\n";
}

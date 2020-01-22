#include <bits/stdc++.h>

using namespace std;

vector <int> x, y, z;
vector <long long> sum_x, sum_y, sum_z;

void build_prefix_sums(vector <int> &a, vector <long long> &sum) {
  sort(a.begin(), a.end());
  sum.resize(a.size() + 1);
  sum[0] = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    sum[i + 1] = sum[i] + a[i];
  }
}

long long get_sum(vector <int> &a, vector <long long> &sum, int v) {
  int cnt = a.size();
  int pos = lower_bound(a.begin(), a.end(), v) - a.begin();
  return (v * 1LL * pos - sum[pos]) + ((sum[cnt] - sum[pos]) - v * 1LL * (cnt - pos));
}

const long long inf = (long long)1e18;

long long ans = inf;

long long test_answer(int rot, int p1, int p2) {
  int xx = 0, yy = 0, zz = 0;
  if (rot == 0) xx = p1, yy = p2, zz = p2 - p1;
  if (rot == 1) xx = p1 - p2, yy = p1, zz = p2;
  if (rot == 2) xx = p2, yy = p1 + p2, zz = p1;
  long long cur = get_sum(x, sum_x, xx) + get_sum(y, sum_y, yy) + get_sum(z, sum_z, zz);
  ans = min(ans, cur);
  return cur;
}

int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  int n;
  scanf("%d", &n);
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    vector <int> &to = (i % 3 == 0 ? x : (i % 3 == 1 ? y : z));
    to.push_back(i / 3 % 2 == 0 ? a[i] : -a[i]);
  }
  build_prefix_sums(x, sum_x);
  build_prefix_sums(y, sum_y);
  build_prefix_sums(z, sum_z);
  for (int rot = 0; rot < 3; rot++) {
    vector <int> p = (rot == 0 ? x : (rot == 1 ? y : z));
    vector <int> q = (rot == 0 ? y : (rot == 1 ? z : x));
    p.resize(unique(p.begin(), p.end()) - p.begin());
    q.resize(unique(q.begin(), q.end()) - q.begin());
    int pn = p.size();
    int qn = q.size();
    int j = 0;
    for (int i = 0; i < pn; i++) {
      test_answer(rot, p[i], q[j]);
      while (j + 1 < qn && test_answer(rot, p[i], q[j]) > test_answer(rot, p[i], q[j + 1])) {
        j++;
      }
      while (j - 1 >= 0 && test_answer(rot, p[i], q[j]) > test_answer(rot, p[i], q[j - 1])) {
        j--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

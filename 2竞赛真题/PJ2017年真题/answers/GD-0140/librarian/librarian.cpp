#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n, q;
string book[1005];

bool cmp (string a, string b) {
	if (a.size () == b.size ()) return a < b;
	else return a.size () < b.size ();
}

int main () {
	freopen ("librarian.in", "r", stdin);
	freopen ("librarian.out", "w", stdout);
	scanf ("%d %d\n", &n, &q);
	for (int i = 1; i <= n; i++)
		getline (cin, book[i]);
	sort (book + 1, book + 1 + n, cmp);
	for (int i = 1; i <= q; i++) {
		int len;
		string qu, ans = "-1"; 
		scanf ("%d ", &len);
		getline (cin, qu);
		for (int j = 1; j <= n; j++) {
			bool flag = true;
			for (int k = 0; k < qu.size(); k++) 
				if (qu[k] != book[j][book[j].size () - qu.size() + k]) {
					flag = false;
					break;
				}
			if (flag) {
				ans = book[j];
				break;
			}
		}
		cout << ans << endl;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}

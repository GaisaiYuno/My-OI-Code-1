#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
bool flags [100];
bool flagq[100];
stack <int> sta[100];
queue <int> que[100];
stack <int> dis;//×öÏÔÊ¾Õ»

int main() {
	int i, j;
	int m;
	cin >> m;
	for(i = 0; i < m; i++) {
		int n, num;
		char op[4];
		flags[i] = true;
		flagq[i] = true;

		cin >> n;
		for(j = 0; j < n; j++) {
			cin >> op;
			if(strcmp(op, "pop") == 0) {


				if(que[i].empty()) {
					flagq[i] = false;

				} else {
					que[i].pop();
				}
				if(sta[i].empty()) {
					flags[i] = false;

				} else {
					sta[i].pop();
				}

			} else {
				cin >> num;
				que[i].push(num);
				sta[i].push(num);
			}
		}


	}

	for(i = 0; i < m; i++) {
		if(flagq[i]) {
			while(!que[i].empty()) {

				cout<<que[i].front()<<" ";
				que[i].pop();
			}
			cout  << endl;
		} else
			cout << "error" << endl;

		if(flags[i])

		{
			while(!sta[i].empty()) {
				dis.push(sta[i].top());
				sta[i].pop();
			}

			while(!dis.empty())

			{
				cout<<dis.top()<<" ";
				dis.pop();
			}

			cout  << endl;
		} else
			cout << "error" << endl;

	}
	return 0;
}

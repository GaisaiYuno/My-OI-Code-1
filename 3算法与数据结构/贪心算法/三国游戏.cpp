//洛谷 三国游戏 
#include <iostream>
#include <algorithm>
using namespace std;
long long map[501][501], ans[501];//为了省事，map[i][j]表示i与j的默契值
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> map[i][j];
            map[j][i] = map[i][j];
        }
        sort(map[i] + 1, map[i] + n + 1);//即将所有map[i]从小到大排序
        ans[i] = map[i][n - 1];//将其中第二小的放入ans数组
    }
    sort(ans + 1, ans + n + 1);//再将ans数组排序，输出最大者即可
    cout << "1" << endl << ans[n] << endl;
    return 0;
}

//��� ������Ϸ 
#include <iostream>
#include <algorithm>
using namespace std;
long long map[501][501], ans[501];//Ϊ��ʡ�£�map[i][j]��ʾi��j��Ĭ��ֵ
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> map[i][j];
            map[j][i] = map[i][j];
        }
        sort(map[i] + 1, map[i] + n + 1);//��������map[i]��С��������
        ans[i] = map[i][n - 1];//�����еڶ�С�ķ���ans����
    }
    sort(ans + 1, ans + n + 1);//�ٽ�ans���������������߼���
    cout << "1" << endl << ans[n] << endl;
    return 0;
}

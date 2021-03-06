#include <iostream>
using namespace std;

int n;
int dp[100001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    //1 위, 2 아래
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[2][0] = 3;
    dp[2][1] = 2;
    dp[2][2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][0] %= 9901;
        dp[i][1] %= 9901;
        dp[i][2] %= 9901;
    }
    printf("%d", (dp[n][0] + dp[n][1] + dp[n][2]) % 9901);
}
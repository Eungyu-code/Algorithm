#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int a[101][101];
int d[101][101];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool check[101][101];

void bfs()
{
    check[0][0] = true;
    d[0][0] = 1;
    queue<pair<int, int> > que;
    que.push({0, 0});
    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (a[nx][ny] == 1 && check[nx][ny] == false)
            {
                check[nx][ny] = true;
                d[nx][ny] = d[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            a[j][i] = str[j] - '0';
        }
    }
    bfs();
    printf("%d", d[m - 1][n - 1]);
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, result = 0;
int a[25][25];
int d[25][25];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool check[25][25];
queue<pair<int, int> > que;
vector<int> villa;

void answer()
{

    for (int i = 1; i <= result; i++)
    {
        int v = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == d[j][k])
                    v++;
            }
        }
        villa.push_back(v);
    }

    sort(villa.begin(), villa.end());
    cout << result << '\n';
    for (int i = villa.size() - result; i < villa.size(); i++)
    {
        cout << villa[i] << '\n';
    }
}

void bfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1 && check[i][j] == false)
            {
                result++;
                que.push(make_pair(i, j));
                check[i][j] = true;
                d[i][j] = result;
                while (!que.empty())
                {
                    int x = que.front().first;
                    int y = que.front().second;
                    que.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            if (check[nx][ny] == false && a[nx][ny] == 1)
                            {
                                check[nx][ny] = true;
                                d[nx][ny] = result;
                                que.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }
    answer();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = line[j] - '0';
        }
    }

    bfs();
}

#include <iostream>
#include <queue>
using namespace std;

int n, k, ans = 0;
int a[100001];
bool check[100001];
queue<pair<int, int> > que;

bool valid(int data)
{
    if (data < 0 || data > 100000 || check[data] == true)
        return false;
    return true;
}

void Search()
{
    while (!que.empty())
    {
        int data = que.front().first;
        int depth = que.front().second;
        if (data == k)
        {
            ans = depth;
            break;
        }
        que.pop();
        if (valid(data - 1))
        {
            check[data - 1] = true;
            que.push({data - 1, depth + 1});
        }
        if (valid(data + 1))
        {
            check[data + 1] = true;
            que.push({data + 1, depth + 1});
        }
        if (valid(data * 2))
        {
            check[data * 2] = true;
            que.push({data * 2, depth + 1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    que.push({n, 0});
    Search();
    printf("%d", ans);
}
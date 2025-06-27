// Uniqueone's Code
// Always try to verify that we get the correct ans for all the tc by current approach else try new one
// PS Do not limit yourselves and think totally rougue, try many things but dedicatedly!
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pi pair<int, int>

int dx[4]{1, 0, 0, 1}, dy[4]{0, 1, 0, 1};
// triplet
struct triplet
{
    int a, b, c;
    triplet(int x, int y, int z) : a(x), b(y), c(z) {}
};

// segment tree
struct segtree
{
    int size;
    vector<long long> sums;
    void initialize(int x)
    {
        size = 1;
        while (size < x)
        {
            size *= 2;
        }
        sums.assign(2 * size, 0);
    }
    void build(vector<int> &a, int x, int left, int right)
    {
        if (right - left == 1)
        {
            if (left < int(a.size()))
                sums[x] = a[left];
            return;
        }
        int mid = (left + right) / 2;
        build(a, 2 * x + 1, left, mid);
        build(a, 2 * x + 2, mid, right);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        return;
    }

    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    void update(int i, int value, int x, int left, int right)
    {
        if (right - left == 1)
        {
            sums[x] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (i < mid)
            update(i, value, 2 * x + 1, left, mid);
        else
            update(i, value, 2 * x + 2, mid, right);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        return;
    }
    void update(int pos, int value)
    {
        update(pos, value, 0, 0, size);
    }

    long long query(int ql, int qr, int x, int left, int right)
    {
        if (qr <= left || right <= ql)
            return 0;
        if (qr >= right && ql <= left)
        {
            return sums[x];
        }
        int mid = (left + right) / 2;
        long long leftpart = query(ql, qr, (2 * x + 1), left, mid);
        long long rightpart = query(ql, qr, (2 * x + 2), mid, right);
        return leftpart + rightpart;
    }
    long long query(int left, int right)
    {
        return query(left, right, 0, 0, size);
    }
};
// Disjoint set Union
class DSU
{
private:
    vector<int> parents;
    vector<int> sizes;

public:
    DSU(int size) : parents(size), sizes(size, 1)
    {
        for (int i = 0; i < size; i++)
        {
            parents[i] = i;
        }
    }

    /** @return the "representative" node in x's component */
    int find(int x)
    {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }

    /** @return whether the merge changed connectivity */
    bool unite(int x, int y)
    {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root)
        {
            return false;
        }

        if (sizes[x_root] < sizes[y_root])
        {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    /** @return whether x and y are in the same connected component */
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};
// gcd
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
// MergeSort
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp(high - low + 1, 0);
    int idx = 0;
    int lIdx = low;
    int rIdx = mid;
    while (lIdx < mid && rIdx <= high)
    {
        if (nums[lIdx] <= nums[rIdx])
        {
            temp[idx++] = nums[lIdx++];
        }
        else
        {
            temp[idx++] = nums[rIdx++];
        }
    }
    while (lIdx < mid)
    {
        temp[idx++] = nums[lIdx++];
    }
    while (rIdx <= high)
    {
        temp[idx++] = nums[rIdx++];
    }
    idx = 0;
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[idx++];
    }
}

void mergeSort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid + 1, high);
    }
}
// Modulo Inverse
//  a is the number u want mod inverse of and mod is the value with which mod is to be taken of like 1e9+7
int modInverse(int a, int mod)
{
    int res = 1;
    int p = mod - 2;
    while (p)
    {
        if (p & 1)
            res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        p >>= 1;
    }
    return res;
}
// start here
int mod = 998244353;
long long power(long long base, long long exp, int mod)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
void buildthree(vector<bool> &vis, vector<pi> &ans, int start, vector<int> tree[], vector<int> &indeg, vector<int> &outdeg, int prev = -1, int count = 0)
{
    if (count == 2)
        return;
    vis[start] = true;
    for (int x : tree[start])
    {
        if (x != prev && !vis[x])
        {
            ans.push_back({start, prev});
            indeg[prev]++;
            outdeg[start]++;
            vis[x] = true;
            buildthree(vis, ans, x, tree, indeg, outdeg, start, count + 1);
        }
    }
    return;
};
void dfs(vector<int> tree[], vector<bool> &vis, vector<int> &indeg, vector<int> &outdeg, vector<pi> &ans, int start)
{
    vis[start] = true;
    for (int x : tree[start])
    {
        if (!vis[x])
        {
            if (indeg[start])
            {
                ans.push_back({x, start});
                outdeg[x] = 1;
                dfs(tree, vis, indeg, outdeg, ans, x);
            }
            else
            {
                ans.push_back({start, x});
                indeg[x] = 1;
                dfs(tree, vis, indeg, outdeg, ans, x);
            }
        }
    }
    return;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<vector<char>> maze(n, vector<char>(m));
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'g')
                t++;
        }
    }
    int ans = 0;
    int dist = k - 1;
    // need to preprocess
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (maze[i - 1][j - 1] == 'g');
        }
    }
    auto check = [&](int x, int y)
    {
        int top = max(0, x - (k - 1));
        int bottom = min(n - 1, x + (k - 1));
        int left = max(0, y - (k - 1));
        int right = min(m - 1, y + (k - 1));
        return dp[bottom + 1][right + 1] - dp[top][right + 1] - dp[bottom + 1][left] + dp[top][left];
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '.')
            {
                ans = max(ans, t - (check(i, j)));
            }
        }
    }
    cout << ans << endl;
    return;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
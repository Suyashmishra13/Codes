#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pi pair<int, int>

int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};

struct triplet
{
    int a, b, c;
    triplet(int x, int y, int z) : a(x), b(y), c(z) {}
};

const int MAXN = 1e5 + 5;
int mod = 998244353;
vector<int> power2(MAXN);

void precompute_powers()
{
    power2[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        power2[i] = (2LL * power2[i - 1]) % mod;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_powers();

    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        map<int, int> mapa, mapb;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mapa[a[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            mapb[b[i]] = i;
        }

        vector<int> ans;
        int mxa = a[0];
        int mxb = b[0];
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                int val = (power2[a[0]] + power2[b[0]]) % mod;
                // ans.push_back(val);
                mxa = max(mxa, a[0]);
                mxb = max(mxb, b[0]);
                cout << val << " ";
                continue;
            }
            mxa = max(mxa, a[i]);
            mxb = max(mxb, b[i]);

            ll takemax;

            if (mxa > mxb)
            {
                int idx = i - mapa[mxa];
                takemax = (power2[mxa] + power2[b[idx]]) % mod;
            }
            else if (mxb > mxa)
            {
                int idx = i - mapb[mxb];
                takemax = (power2[mxb] + power2[a[idx]]) % mod;
            }
            else
            {
                int idx1 = i - mapa[mxa];
                int idx2 = i - mapb[mxb];
                ll option1 = (power2[mxa] + power2[b[idx1]]) % mod;
                ll option2 = (power2[mxb] + power2[a[idx2]]) % mod;
                takemax = (power2[mxa] + power2[max(b[idx1], a[idx2])]) % mod;
            }
            // 			ans.push_back(takemax);
            cout << takemax << " ";
        }
        // 		for (int x : ans)
        // 			cout << x << " ";
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> nums;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        nums.push_back(x);
    }
    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        ll cur = nums[i];
        ll leftval = (nums[i] * (i));
        ll next = i + 1;
        while (next < n && nums[next] == cur)
        {
            next++;
        }
        ll rightval = (nums[i] * (n - next));
        i = next - 1;
        ans = ans > leftval + rightval ? leftval + rightval : ans;
    }
    cout << ans << "\n";
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
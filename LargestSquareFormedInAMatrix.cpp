class Solution
{
public:
    int maxareahisto(vector<int> &cur)
    {
        // for(int x : cur) cout<<x<<" ";
        // cout<<endl;
        int m = cur.size();
        vector<int> ns(m, m), ps(m, -1);
        stack<int> trav;
        for (int i = 0; i < m; i++)
        {
            while (!trav.empty() && cur[trav.top()] >= cur[i])
            {
                trav.pop();
            }
            if (trav.empty())
            {
                ps[i] = -1;
            }
            else
                ps[i] = trav.top();
            trav.push(i);
        }
        while (!trav.empty())
            trav.pop();
        for (int i = m - 1; i >= 0; i--)
        {
            while (!trav.empty() && cur[trav.top()] >= cur[i])
            {
                trav.pop();
            }
            if (trav.empty())
            {
                ns[i] = m;
            }
            else
                ns[i] = trav.top();
            trav.push(i);
        }
        int ans = INT_MIN;
        int val = INT_MIN;
        // comments to check for the ns and ps arrays we made along the way :)
        // for(int x : ns) cout<<x<<" ";
        // cout<<endl;
        // for(int x : ps) cout<<x<<" ";
        // cout<<endl;
        for (int i = 0; i < m; i++)
        {
            if (ns[i] - ps[i] - 1 >= cur[i])
                ans = max(ans, cur[i]);
        }
        return ans;
    }
    int maxSquare(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> currow = mat[0];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j])
                    ans = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    currow[j] += 1;
                else
                    currow[j] = 0;
            }
            ans = max(ans, maxareahisto(currow));
        }
        return ans;
    }
};
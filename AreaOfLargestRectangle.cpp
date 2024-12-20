class Solution
{
public:
    // would help in solving another gfg question of which I would attach the link to
    // link to the below one : https://leetcode.com/problems/largest-rectangle-in-histogram/
    int largestRectangleArea(vector<int> &cur)
    {
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
        for (int x : ns)
            cout << x << " ";
        cout << endl;
        for (int x : ps)
            cout << x << " ";
        cout << endl;
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, (ns[i] - ps[i] - 1) * cur[i]);
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back
#define eb emplace_back

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a, int b)
{
    if (a < b)
        return a;
    return b;
}
ll min(int a, ll b)
{
    if (a < b)
        return a;
    return b;
}
ll max(ll a, int b)
{
    if (a > b)
        return a;
    return b;
}
ll max(int a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
const int MX = 2e5 + 123;


vi sum1[MX];

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;

    cin >> s;

    vector<vector<int>> preSum(n + 1, vi(26, 0));
    for (int i = 1; i <= n; i++)
    {
        int pos = s[i - 1] - 97;
        preSum[i][pos] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        
        for (int c = 0; c < 26; c++)
        {
            preSum[i][c] += preSum[i - 1][c];
        }
    }
    while (m--)
    {
        int l, r;
        char ch;
        cin >> l >> r >> ch;
        int rd = r / n;
        int rm = r % n;
        int cntr = (rd * preSum[n][ch - 97]) + (preSum[rm][ch - 97]);
        l--;
        int ld = l / n;
        int lm = l % n;
        int cntl = (ld * preSum[n][ch - 97]) + (preSum[lm][ch - 97]);
        cout << cntr - cntl << endl;
    }
    // cf(i, 1, 10001)
    // {
    //     sf += s;
    //     if (sf.length() >= 10001)
    //     {
    //         break;
    //     }
    // }
    // sf[0] = {0};
    // int p = sf.size();
    // while (m--)
    // {h
    //     int l, r, ans = 0;
    //     char ch;
    //     cin >> l >> r;
    //     cin >> ch;

    //     int z = *max_element(sum + l, sum + r + 1);
    //     if (r > n && r <= 2 * n)
    //     {
    //         int x = sum[n] - sum[l - 1];

    //         int y = sum[r % n];

    //         int k = floor(((r - l) / n) * z);

    //         ans = x + y;
    //         cout << ans << endl;
    //     }
    //     else if (r > 2 * n)
    //     {
    //         int x = sum[n] - sum[l - 1];

    //         int y = sum[r % n];

    //         int k = floor(((r - l) / n) * z);

    //         ans = x + y + (((r - l) / n) * z);
    //         cout << ans << endl;
    //     }
    //     else
    //     {
    //         cout << z << endl;
    //     }
    // }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
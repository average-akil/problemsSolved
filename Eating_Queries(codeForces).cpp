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

void solve()
{
    const int MX = 2e5 + 123;

    int n, m;
    cin >> n >> m;
    vll arr(n + 1), arr1(n + 1), preSum(n + 1, 0);
    cf(i, 1, n)
    {
        cin >> arr[i];
        // cout << arr[i] << " ";
    }

     sort(arr.begin(), arr.end(), greater<long long>());
  
    // //  reverse(arr, arr + (n + 1));
    cf(i, 1, n)
    {
        preSum[i] = preSum[i - 1] + arr[i-1];
    }
    /// reverse(preSum.begin(), preSum.end() + 1);


    // cf(i, 1, n)
    // {
    //     cout << preSum[i] << " ";
    // }
    // cout << endl;
    // // cout << preSum[];
    // map<ll, int> cnt;
    // cnt[0] = 1;
    while (m--)
    {
        int x, ans = 0;

        cin >> x;
        if (x > preSum[n])
        {
            cout << -1 << endl;
        }
        else
        {

            int ans = lower_bound(preSum.begin(), preSum.end(), x) - preSum.begin();

            cout << ans << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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
ll preSum[1000005];
void solve()
{
    int n;
    cin >> n;

    vi v(n);
    f(i, 0, n)
    {
        cin >> v[i];
    }
    f(i, 0, n)
    {
        preSum[i] = preSum[i - 1] + v[i];
        cout << preSum[i] << endl;
    }
}
int arr1[1000023];
int sum1[1000023];
void solve1()
{
    int n, q;
    cin >> n >> q;
    cf(i, 1, n) cin >> arr[i];
    cf(i, 1, n) sum[i] = sum[i - 1] ^ arr[i];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (sum[r] ^ sum[l - 1]) << endl;
    }
}
int mx = 2e5 + 123;
int arr0[mx];
ll sum0[mx];
void solve2()
{
    int n, x;
    cin >> n >> x;
    cf(i, 1, n) cin >> arr0[i];
    cf(i, 1, n) sum0[i] = sum0[i - 1] + arr0[i];

    ll ans = 0;
    map<ll, int> cnt;
    cnt[0] = 1;

    cf(i, 1, n)
    {
        ll sumLMinusOne = sum0[i] - x;
        ans += cnt[sumLMinusOne];
        cnt[sum0]++;
    }
    cout << ans << endl;

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}
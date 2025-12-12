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
    double h, l;
    cin >> h >> l;

    double ans = ((l * l) - (h * h)) / (2 * h);
    cout << fixed << setprecision(9) << ans << endl;
}
void solve2()
{
    string s;
    cin >> s;
    int n = s.size();
    string mirror = "AHIMOTUVWXY";
    if (n == 1)
    {
        int pos = mirror.find(s[0]);
        //  cout << pos << endl;
        if (pos > -1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    if (n == 2)
    {
        if (s[0] == s[1])
        {
            int pos = mirror.find(s[0]);
            //  cout << pos << endl;
            if (pos > -1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

            // cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (n > 2)
    {
        string s1, s2;
        s1 += s;
        s2 += s;
        reverse(s2.begin(), s2.end());
        sort(s1.begin(), s1.end());

        s1.erase(unique(s1.begin(), s1.end()), s1.end());
        // cout << s1 << endl;
        ll cnt = 0;
        f(i, 0, s1.size())
        {
            f(j, i, 11)
            {
                if (s1[i] == mirror[j])
                    cnt++;
            }
        }
        // cout << cnt << endl;
        // cout << s2 << endl;
        if (cnt == s1.size() && s == s2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
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
        cout << 0%6 << endl;
    }
    return 0;
}
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
    int n;
    cin >> n;
    vi arr(n + 1), preSum(201, 0), arr2, arr3;
    ll hundred = 0, twoHundred = 0;
    cf(i, 1, n)
    {
        cin >> arr[i];
        if (arr[i] == 100)
            hundred++;
        else if (arr[i] == 200)
            twoHundred++;
    }
    //cout << hundred << " " << twoHundred << endl;
    sort(arr.begin(), arr.end());
    ll sum100 = hundred * 100, sum200 = twoHundred * 200;

    bool flag = 0;

    if (sum100 == sum200)
    {
        flag = 1;
    }
    else if (sum100 > sum200)
    {
        for (int i =1; i <= hundred; i++)
        {
            sum200 += 100;
             sum100 -= 100;
            cout << sum100 << " " << sum200 << endl;
            if (sum100 == sum200)
            {
                flag = 1;
                break;
            }
        }
    }
    else if (sum200 > sum100)
    {
        for(int i = hundred ; i<=n ; i++)
        {

            sum100 += 200;
            sum200 -= 200;
            cout << sum100 << " " << sum200 << endl;
            if (sum100 == sum200)
            {
                flag = 1;
                break;
            }
        }
    }
    // for (auto u : arr2)
    // {
    //     cout << u << " ";
    // }
    // cout << endl;
    // for (auto u : arr3)
    // {
    //     cout << u << " ";
    // }
    // f(i, 1, n)
    // {
    //     f(j, 1, n)
    //     {
    //         if (arr2[i] == arr3[j])
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    // }
    if (flag == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
        solve();
    }
    return 0;
}
// if ((((hundred * 100) == (twoHundred * 200)) || (twoHundred * 200 == ((twoHundred-hundred) * (twoHundred * 200)) + (hundred * 100))) && (hundred != 0 && twoHundred != 0))
// {
//     cout << "YES" << endl;
// }
// else if (((hundred == 0 && twoHundred > 0) || (hundred > 0 && twoHundred == 0)) && n > 1)
// {
//     if ((n % 2 == 0))
//     {
//         cout << "YES" << endl;
//     }
// }
// else
//     cout << "NO" << endl;
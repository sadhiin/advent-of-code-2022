#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define dbg(x) cout << #x << " " << x << endl;
#define re return
#define en cout << "\n";
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 105;

int getval(char x)
{
    if (x >= 'a' and x <= 'z')
    {
        return abs(int('a' - x)) + 1;
    }
    else
    {
        x = tolower(x);
        return abs(int('a' - x)) + 1 + 26;
    }
}
int getval_second(vector<string> &arr)
{
    string temp = arr[0];
    for (int i = 0; i < temp.size(); i++)
    {
        if (arr[1].find(temp[i]) != string::npos and arr[2].find(temp[i]) != string::npos)
        {
            // cout << temp[i] << '\n';
            return getval(temp[i]);
            // break;
        }
    }
}

void solve_part_1()
{
    // Part-1
    ll ans = 0;
    string line;
    while (cin >> line)
    {
        // cout<<line<<"---> ";
        map<char, int> m;
        int h = (line.size() + 1) / 2;
        for (char x : line)
            m[x]++;

        string f = line.substr(0, h);
        string s = line.substr(h, line.size());
        // cout<<" f: "<<f<<'\n';
        // cout<<"S: "<<s<<' ';

        for (int i = 0; i < f.size(); i++)
        {
            if (m[f[i]] > 1 and (s.find(f[i]) != string::npos))
            {
                // cout<<line[i]<<' '<<getval(line[i])<<'\n';
                ans += getval(line[i]);
                break;
            }
        }
    }
    cout << ans;
}

void solve_part_2()
{
    ll ans = 0;
    string line;
    int i = 1;
    vector<string> arr;
    while (cin >> line)
    {

        if (arr.size() == 3)
        {
            ans += getval_second(arr);
            arr.clear();
        }
        arr.push_back(line);
    }
    if(arr.size()!=0)
        ans += getval_second(arr);
    cout << ans << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve_part_2();
    return 0;
}
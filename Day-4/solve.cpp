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

pii getID(string a)
{

    int i = 0;
    string f = "", s = "";
    while (a[i] != '-')
    {
        f += a[i];
        i++;
    }
    // cout<<a[i]<<' '<< i<<'\n';
    i++;
    while (i < a.size())
    {
        s += a[i];
        i++;
    }
    return {stoi(f), stoi(s)};
}

void solve_1()
{
    int ans = 0;
    string line;
    while (cin >> line)
    {
        int coma = line.find(',');
        string a = line.substr(0, coma), b = line.substr(coma + 1, line.size());
        pair<int, int> f = getID(a), s = getID(b);

        // cout << f.first << " " << f.second << " -- " << s.first << ' ' << s.second;
        // en;

        if ((s.first >= f.first and s.first <= f.second and s.second <= f.second) or (f.first >= s.first and f.first <= s.second and f.second <= s.second))
            ans += 1;

        // int mi = min(min(f.first, f.second), min(s.first, s.second));
        // int ma = max(max(f.first, f.second), max(s.first, s.second));

        // vi arr1(ma + 1, 0), arr2(ma + 1, 0);

        // int aa = min(f.first, f.second), ab = max(f.first, f.second);
        // int ba = min(s.first, s.second), bb = max(s.first, s.second);
        // for (int i = aa; i <= ab; i++)
        //     arr1[i] = 1;
        // for (int i = ba; i <= bb; i++)
        //     arr2[i] = 1;

        // bool allok = true;

        // vi arr = {f.first, f.second, s.first, s.second};
        // sort(all(arr));
        // int mid_min = arr[1], mid_max = arr[2];
        // // cout << mid_min << " " << mid_max;
        // en;
        // for (int i = mid_min; i <= mid_max; i++)
        // {
        //     if (arr1[i] != arr2[i])
        //     {
        //         allok = false;
        //         break;
        //     }
        // }
        // if (allok)
        // {
        //     ans += 1;
        //     cout << line << " --- " << mid_min << " " << mid_max;
        //     en;
        // }
    }
    cout << ans;
}

void solve_2()
{
    int ans = 0;
    string line;
    while (cin >> line)
    {
        int coma = line.find(',');
        string a = line.substr(0, coma), b = line.substr(coma + 1, line.size());
        pair<int, int> f = getID(a), s = getID(b);

        int mi = min(min(f.first, f.second), min(s.first, s.second));
        int ma = max(max(f.first, f.second), max(s.first, s.second));
        // 5-7,7-9
        // 2-8,3-7
        // 6-6,4-6
        // 2-6,4-8

        // if (((f.first <= s.first) and (f.second >= s.second)) or (f.second <= s.second))
        // if((f.first <= s.first and f.second<=s.first and f.second <= s.second) or (f.second >= f.first and f.second >= f.first and f.second <= s.second))
        // {
        //     ans += 1;
        //     cout << line;
        //     en;
        // }

        // if ((s.first >= f.first and s.first <= f.second and s.second <= f.second) and (f.first >= s.first and f.first <= s.second and f.second <= s.second))
        // if((s.first >= f.first or f.second <= s.first and f.second <= s.second))
        // if(s.first <= f.second)

        if((f.first <= s.second and f.second >= s.first) or (s.first <= f.first and f.second <= s.second))
        {
            ans += 1;
            // cout << line;
            // en;
        }
    }
    cout << ans;
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
    solve_2();
    return 0;
}
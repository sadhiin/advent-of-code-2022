#include <bits/stdc++.h>
#pragma GCC optimize(" Ofast")
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

bool duplicate_char(string inp, char x)
{
    return inp.find(x) == string::npos;
}

void solve()
{
    string seq;
    while (cin >> seq)
    {
        string f = seq.substr(0, 4);
        for (int i = 4; i < seq.size(); i++)
        {
            if (duplicate_char(f, seq[i]))
            {
                cout<<seq[i];en;
                cout << i + 1;break;
            }
            else if(seq[i] == f[0] and duplicate_char(f,seq[i])==false)
            {
                cout<< seq[i];en;
                cout<<i+1;break;
            }
            else{
                f += seq[i];
            }
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
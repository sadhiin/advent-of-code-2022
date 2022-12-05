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

int32_t main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    // solve();
    string inputfile = "input.txt";
    if (argc > 1)
    {
        inputfile = argv[1];
    }
    string line;
    fstream file(inputfile);
    vector<string> inp;
    while (getline(file, line) && line[1] != '1')
    {
        inp.push_back(line);
    }

    vector<stack<char>> stacks(line.size() / 4 + 1);
    for (int i = inp.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < stacks.size(); j++)
        {
            const int k = j * 4 + 1;
            if (inp[i][k] == ' ')
                continue;
            stacks[j].push(inp[i][k]);
        }
    }

    getline(file, line);
    const std::regex pattern(R"(move ([0-9]+) from ([0-9]+) to ([0-9]+))");
    while (getline(file, line))
    {
        smatch match;
        regex_match(line, match, pattern);
        const auto n = stoi(match[1]);
        const auto from = stoi(match[2]) - 1;
        const auto to = stoi(match[3]) - 1;
        for (int i = 0; i < n; i++)
        {
            const auto c = stacks[from].top();
            stacks[from].pop();
            stacks[to].push(c);
        }
    }
    for (const auto stk : stacks)
    {
        if (!stk.empty())
        {
            cout << stk.top();
        }
        else
        {
            cout << " ";
        }
    }
    en;
    return 0;
}
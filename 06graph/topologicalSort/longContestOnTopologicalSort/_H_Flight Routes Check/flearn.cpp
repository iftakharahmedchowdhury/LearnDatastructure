/*
Problem Name: Flight Routes Check
Problem Link: https://cses.fi/problemset/task/1682
Author: Sachin Srivastava (mrsac7)
*/
#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T &...args) { ((cin >> args), ...); }
template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }
template <typename... T>
void putl(T &&...args)
{
    ((cout << args << " "), ...);
    cout << '\n';
}
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << "=" << a << ", ";
    err(++it, args...);
}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout << '\n';
#define E cerr << '\n';
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed
#define sz size()
#define seea(a, x, y)           \
    for (int i = x; i < y; i++) \
    {                           \
        cin >> a[i];            \
    }
#define seev(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        v.push_back(x);         \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }
const ll inf = 1LL << 62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

vi adj1[100005], adj2[100005];
stack<int> st;
bool vis[100005];
void dfs(int s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto i : adj1[s])
        dfs(i);
    st.push(s);
}
void dfs2(int s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto i : adj2[s])
        dfs2(i);
}
int main()
{
    int n, m;
    see(n, m);
    rep(i, 0, m)
    {
        int a, b;
        see(a, b);
        adj1[a].pb(b);
        adj2[b].pb(a);
    }
    rep(i, 1, n + 1)
    {
        if (!vis[i])
            dfs(i);
    }
    memset(vis, 0, sizeof vis);
    int x = st.top();
    dfs2(x);
    rep(i, 1, n + 1)
    {
        if (i == x)
            continue;
        if (!vis[i])
        {
            putl("NO");
            for (auto j : adj1[i])
            {
                if (j == x)
                {
                    put(x, i);
                    return 0;
                }
            }
            put(i, x);
            return 0;
        }
    }
    put("YES");
}

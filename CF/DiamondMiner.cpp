/*
C. Diamond Miner
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Diamond Miner is a game that is similar to Gold Miner, but there are n miners instead of 1 in this game.

The mining area can be described as a plane. The n miners can be regarded as n points on the y-axis. There are n diamond mines in the mining area. We can regard them as n points on the x-axis. For some reason, no miners or diamond mines can be at the origin (point (0,0)).

Every miner should mine exactly one diamond mine. Every miner has a hook, which can be used to mine a diamond mine. If a miner at the point (a,b) uses his hook to mine a diamond mine at the point (c,d), he will spend (a−c)2+(b−d)2−−−−−−−−−−−−−−−√ energy to mine it (the distance between these points). The miners can't move or help each other.

The object of this game is to minimize the sum of the energy that miners spend. Can you find this minimum?

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤10) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤105) — the number of miners and mines.

Each of the next 2n lines contains two space-separated integers x (−108≤x≤108) and y (−108≤y≤108), which represent the point (x,y) to describe a miner's or a diamond mine's position. Either x=0, meaning there is a miner at the point (0,y), or y=0, meaning there is a diamond mine at the point (x,0). There can be multiple miners or diamond mines at the same point.

It is guaranteed that no point is at the origin. It is guaranteed that the number of points on the x-axis is equal to n and the number of points on the y-axis is equal to n.

It's guaranteed that the sum of n for all test cases does not exceed 105.

Output
For each test case, print a single real number — the minimal sum of energy that should be spent.

Your answer is considered correct if its absolute or relative error does not exceed 10−9.

Formally, let your answer be a, and the jury's answer be b. Your answer is accepted if and only if |a−b|max(1,|b|)≤10−9.

Example
inputCopy
3
2
0 1
1 0
0 -1
-2 0
4
1 0
3 0
-5 0
6 0
0 3
0 1
0 2
0 4
5
3 0
0 4
0 -3
4 0
2 0
1 0
-3 0
0 -10
0 -2
0 -10
outputCopy
3.650281539872885
18.061819283610362
32.052255376143336
Note
In the first test case, the miners are at (0,1) and (0,−1), while the diamond mines are at (1,0) and (−2,0). If you arrange the miners to get the diamond mines in the way, shown in the picture, you can get the sum of the energy 2–√+5–√.
*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair<ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();
int f(int n)
{
	if (n % 2 == 0) return n / 2;
	else return n / 2 + 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

	int t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}

void solve()
{
	ll n;
	cin >> n;
	vpll a(n), b(n);
	ll x1 = 0, y1 = 0;
	foi(2 * n) {
		ll x, y;
		cin >> x >> y;
		if (x == 0) {
			a[x1].ff = abs(x) ; a[x1].ss = abs(y) ;
			x1++;
		}
		else {
			b[y1].ff = abs(x); b[y1].ss = abs(y) ;
			y1++;
		}
	}

	sort(a.begin(), a.end());
	ld s = 0;
	sort(b.begin(), b.end());
	for (ll i = 0; i < n; i++) {
		s += (ld) sqrt(pow((a[i].ff - b[i].ff), 2)  + pow((a[i].ss - b[i].ss ), 2) ) ;
		}
	cout << fixed << setprecision (21);
	cout << s;

}

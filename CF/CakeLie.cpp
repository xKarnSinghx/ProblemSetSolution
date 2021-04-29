/*
B. The Cake Is a Lie
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a n×m grid. You are standing at cell (1,1) and your goal is to finish at cell (n,m).

You can move to the neighboring cells to the right or down. In other words, suppose you are standing at cell (x,y). You can:

move right to the cell (x,y+1) — it costs x burles;
move down to the cell (x+1,y) — it costs y burles.
Can you reach cell (n,m) spending exactly k burles?

Input
The first line contains the single integer t (1≤t≤100) — the number of test cases.

The first and only line of each test case contains three integers n, m, and k (1≤n,m≤100; 0≤k≤104) — the sizes of grid and the exact amount of money you need to spend.

Output
For each test case, if you can reach cell (n,m) spending exactly k burles, print YES. Otherwise, print NO.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
inputCopy
6
1 1 0
2 2 2
2 2 3
2 2 4
1 4 3
100 100 10000
outputCopy
YES
NO
YES
NO
YES
NO
Note
In the first test case, you are already in the final cell, so you spend 0 burles.

In the second, third and fourth test cases, there are two paths from (1,1) to (2,2): (1,1) → (1,2) → (2,2) or (1,1) → (2,1) → (2,2). Both costs 1+2=3 burles, so it's the only amount of money you can spend.

In the fifth test case, there is the only way from (1,1) to (1,4) and it costs 1+1+1=3 burles.


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
typedef pair< ll, pll>      plll;
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
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
ll TT = 1;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


	ll t ; cin >> t;
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
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}
ll a, b;
ll cal(ll x1, ll y1, ll x2, ll y2)
{
	ll area = x1 * y1 + x2 * y2;
	if (x1 + x2 <= a && y1 <= b && y2 <= b)
		return area;
	if (y1 + y2 <= b && x1 <= a && x2 <= a)
		return area;
	return 0;
}
void solve()
{

	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = 0;
	ans += (m - 1);
	ans += m * (n - 1);
	if (ans == k)
		cout << "YES";
	else
		cout << "NO";

}

 

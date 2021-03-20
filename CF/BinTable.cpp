/*
C1. Binary Table (Easy Version)
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is the easy version of the problem. The difference between the versions is in the number of possible operations that can be made. You can make hacks if and only if you solved both versions of the problem.

You are given a binary table of size n×m. This table consists of symbols 0 and 1.

You can make such operation: select 3 different cells that belong to one 2×2 square and change the symbols in these cells (change 0 to 1 and 1 to 0).

Your task is to make all symbols in the table equal to 0. You are allowed to make at most 3nm operations. You don't need to minimize the number of operations.

It can be proved that it is always possible.

Input
The first line contains a single integer t (1≤t≤5000) — the number of test cases. The next lines contain descriptions of test cases.

The first line of the description of each test case contains two integers n, m (2≤n,m≤100).

Each of the next n lines contains a binary string of length m, describing the symbols of the next row of the table.

It is guaranteed that the sum of nm for all test cases does not exceed 20000.

Output
For each test case print the integer k (0≤k≤3nm) — the number of operations.

In the each of the next k lines print 6 integers x1,y1,x2,y2,x3,y3 (1≤x1,x2,x3≤n,1≤y1,y2,y3≤m) describing the next operation. This operation will be made with three cells (x1,y1), (x2,y2), (x3,y3). These three cells should be different. These three cells should belong into some 2×2 square.

Example
inputCopy
5
2 2
10
11
3 3
011
101
110
4 4
1111
0110
0110
1111
5 5
01011
11001
00010
11011
10000
2 3
011
101
outputCopy
1
1 1 2 1 2 2
2 
2 1 3 1 3 2
1 2 1 3 2 3
4
1 1 1 2 2 2 
1 3 1 4 2 3
3 2 4 1 4 2
3 3 4 3 4 4
4
1 2 2 1 2 2 
1 4 1 5 2 5 
4 1 4 2 5 1
4 4 4 5 3 4
2
1 3 2 2 2 3
1 2 2 1 2 2
Note
In the first test case, it is possible to make only one operation with cells (1,1), (2,1), (2,2). After that, all symbols will be equal to 0.

In the second test case:

operation with cells (2,1), (3,1), (3,2). After it the table will be:

011
001
000
operation with cells (1,2), (1,3), (2,3). After it the table will be:

000
000
000
In the fifth test case:

operation with cells (1,3), (2,2), (2,3). After it the table will be:

010
110
operation with cells (1,2), (2,1), (2,2). After it the table will be:

000
000

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
const ll MOD = 1000000007;
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
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
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
ll fac(ll n) {
	while (n % 4 == 0) {
		n /= 4;
	}
	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % (i * i) == 0) {
			n /= (i * i);
		}
	}
	return n;
}
void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<vll> ans;
	char a[n][k];
	foi(n) {
		foj(k) {
			cin >> a[i][j];
			if (a[i][j] == '1')
			{
				ll x = 1, y = 1;
				if (i == n - 1)
				{
					x = -x;
				}
				if (j == k - 1)
				{
					y = -y;
				}
				ans.pb({i + 1, j + 1, i + x + 1, j + 1, i + x + 1, j + y + 1});
				ans.pb({i + 1, j + 1, i + 1, j + y + 1, i + x + 1, j + y + 1});
				ans.pb({i + 1, j + 1, i + x + 1, j + 1, i + 1, j + y + 1});
			}
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}

}

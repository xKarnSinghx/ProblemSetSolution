/*
A. Nezzar and Board
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
n distinct integers x1,x2,…,xn are written on the board. Nezzar can perform the following operation multiple times.

Select two integers x,y (not necessarily distinct) on the board, and write down 2x−y. Note that you don't remove selected numbers.
Now, Nezzar wonders if it is possible to have his favorite number k on the board after applying above operation multiple times.

Input
The first line contains a single integer t (1≤t≤105) — the number of test cases.

The first line of each test case contains two integers n,k (2≤n≤2⋅105, −1018≤k≤1018).

The second line of each test case contains n distinct integers x1,x2,…,xn (−1018≤xi≤1018).

It is guaranteed that the sum of n for all test cases does not exceed 2⋅105.

Output
For each test case, print "YES" on a single line if it is possible to have k on the board. Otherwise, print "NO".

You can print each letter in any case (upper or lower).

Example
inputCopy
6
2 1
1 2
3 0
2 3 7
2 -1
31415926 27182818
2 1000000000000000000
1 1000000000000000000
2 -1000000000000000000
-1000000000000000000 123
6 80
-5 -20 13 -14 -2 -11
outputCopy
YES
YES
NO
YES
YES
NO
Note
In the first test case, the number 1 is already on the board.

In the second test case, Nezzar could perform the following operations to write down k=0 on the board:

Select x=3 and y=2 and write down 4 on the board.
Select x=4 and y=7 and write down 1 on the board.
Select x=1 and y=2 and write down 0 on the board.
In the third test case, it is impossible to have the number k=−1 on the board.

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

	ll n, k;
	cin >> n >> k;
	ll a[n];
	foi(n) {
		cin >> a[i];

	}

	sort(a, a + n);
	ll x = a[0];
	foi(n) {
		a[i] -= x;
	}
	k -= x;
	ll b = 0;
	for (ll i = 1; i < n; ++i)
	{
		b = __gcd(b, a[i]);
	}
	if (k % b)
		cout << "NO";
	else
		cout << "YES";




}
 

/*
E. Binary Subsequence Rotation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Naman has two binary strings s and t of length n (a binary string is a string which only consists of the characters "0" and "1"). He wants to convert s into t using the following operation as few times as possible.

In one operation, he can choose any subsequence of s and rotate it clockwise once.

For example, if s=1110100, he can choose a subsequence corresponding to indices (1-based) {2,6,7} and rotate them clockwise. The resulting string would then be s=1010110.

A string a is said to be a subsequence of string b if a can be obtained from b by deleting some characters without changing the ordering of the remaining characters.

To perform a clockwise rotation on a sequence c of size k is to perform an operation which sets c1:=ck,c2:=c1,c3:=c2,…,ck:=ck−1 simultaneously.

Determine the minimum number of operations Naman has to perform to convert s into t or say that it is impossible.

Input
The first line contains a single integer n (1≤n≤106) — the length of the strings.

The second line contains the binary string s of length n.

The third line contains the binary string t of length n.

Output
If it is impossible to convert s to t after any number of operations, print −1.

Otherwise, print the minimum number of operations required.

Examples
inputCopy
6
010000
000001
outputCopy
1
inputCopy
10
1111100000
0000011111
outputCopy
5
inputCopy
8
10101010
01010101
outputCopy
1
inputCopy
10
1111100000
1111100001
outputCopy
-1
Note
In the first test, Naman can choose the subsequence corresponding to indices {2,6} and rotate it once to convert s into t.

In the second test, he can rotate the subsequence corresponding to all indices 5 times. It can be proved, that it is the minimum required number of operations.

In the last test, it is impossible to convert s into t.

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
#define graph          vector<vector<ll>>
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
typedef  map<ll, vll>             mvll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
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

//	ll t ; cin >> t;
//	while (t--)
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
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
void solve() {
	ll n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vll a;
	ll cnt = 0, cur = 0, mx = 0, cur1 = 0, mx1 = 0;
	foi(s.size()) {
		if (s[i] != t[i] and s[i] == '1')
			a.pb(-1LL);
		else if (s[i] != t[i] and s[i] == '0')
			a.pb(1LL);
	}
	foi(a.size()) {
		cnt += a[i];
		cur += 1ll * a[i];
		cur1 += -1ll * a[i];
		mx = max(mx, cur), mx1 = max(mx1, cur1);
		if (cur1 < 0)
			cur1 = 0;
		if (cur < 0)
			cur = 0;
	}
	if (cnt != 0) {
		cout << -1;
		return;
	}
	cout << max(mx1, mx);


}

 

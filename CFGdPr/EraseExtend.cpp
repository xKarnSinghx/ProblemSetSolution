/*
E2. Erase and Extend (Hard Version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is the hard version of the problem. The only difference is the constraints on n and k. You can make hacks only if all versions of the problem are solved.

You have a string s, and you can do two types of operations on it:

Delete the last character of the string.
Duplicate the string: s:=s+s, where + denotes concatenation.
You can use each operation any number of times (possibly none).

Your task is to find the lexicographically smallest string of length exactly k that can be obtained by doing these operations on string s.

A string a is lexicographically smaller than a string b if and only if one of the following holds:

a is a prefix of b, but a≠b;
In the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
Input
The first line contains two integers n, k (1≤n,k≤5⋅105) — the length of the original string s and the length of the desired string.

The second line contains the string s, consisting of n lowercase English letters.

Output
Print the lexicographically smallest string of length k that can be obtained by doing the operations on string s.

Examples
inputCopy
8 16
dbcadabc
outputCopy
dbcadabcdbcadabc
inputCopy
4 5
abcd
outputCopy
aaaaa
Note
In the first test, it is optimal to make one duplication: "dbcadabc" → "dbcadabcdbcadabc".

In the second test it is optimal to delete the last 3 characters, then duplicate the string 3 times, then delete the last 3 characters to make the string have length k.

"abcd" → "abc" → "ab" → "a" → "aa" → "aaaa" → "aaaaaaaa" → "aaaaaaa" → "aaaaaa" → "aaaaa".


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
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
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
	//while (t--)
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
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}
void solve() {
	ll n, k;
	cin >> n >> k;
	string s, t = "";
	cin >> s;
	ll cnt = 0, idx = 0;
	foi(n) {
		if (i == 0)
			continue;
		if (s[i] == s[cnt]) {
			if (cnt == 0)
				idx = i;
			cnt++;

		}
		else if (s[i] > s[cnt]) {
			break;
		}
		else if (s[i] < s[cnt]) {
			cnt = 0; idx = i + 1;
		}
	}
	if (idx == 0)
		idx ++;
	foi(k / idx) {
		foj(idx) {
			t += s[j];
		}
	}
	foi(k % idx) {
		t += s[i];
	}
	cout << t;

}


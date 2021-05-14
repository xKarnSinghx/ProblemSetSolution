/*
A. Juggling Letters
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given n strings s1,s2,…,sn consisting of lowercase Latin letters.

In one operation you can remove a character from a string si and insert it to an arbitrary position in a string sj (j may be equal to i). You may perform this operation any number of times. Is it possible to make all n strings equal?

Input
The first line contains t (1≤t≤10): the number of test cases.

The first line of each test case contains a single integer n (1≤n≤1000): the number of strings.

n lines follow, the i-th line contains si (1≤|si|≤1000).

The sum of lengths of all strings in all test cases does not exceed 1000.

Output
If it is possible to make the strings equal, print "YES" (without quotes).

Otherwise, print "NO" (without quotes).

You can output each character in either lowercase or uppercase.

Example
inputCopy
4
2
caa
cbb
3
cba
cba
cbb
4
ccab
cbac
bca
acbcc
4
acb
caf
c
cbafc
outputCopy
YES
NO
YES
NO
Note
In the first test case, you can do the following:

Remove the third character of the first string and insert it after the second character of the second string, making the two strings "ca" and "cbab" respectively.
Remove the second character of the second string and insert it after the second character of the first string, making both strings equal to "cab".
In the second test case, it is impossible to make all n strings equal.


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
void solve() {
	ll n;
	cin >> n;
	ll cnt[27] = {};
	foi(n) {
		string s;
		cin >> s;
		foi(s.size()) {
			cnt[s[i] - 'a']++;
		}
	}
	foi(27) {
		if (cnt[i] % n) {
			cout << "No";
			return;
		}
	}
	cout << "Yes";
}



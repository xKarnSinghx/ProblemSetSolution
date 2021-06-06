/*
B. Prinzessin der Verurteilung
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
I, Fischl, Prinzessin der Verurteilung, descend upon this land by the call of fate an — Oh, you are also a traveler from another world? Very well, I grant you permission to travel with me.

It is no surprise Fischl speaks with a strange choice of words. However, this time, not even Oz, her raven friend, can interpret her expressions! Maybe you can help us understand what this young princess is saying?

You are given a string of n lowercase Latin letters, the word that Fischl just spoke. You think that the MEX of this string may help you find the meaning behind this message. The MEX of the string is defined as the shortest string that doesn't appear as a contiguous substring in the input. If multiple strings exist, the lexicographically smallest one is considered the MEX. Note that the empty substring does NOT count as a valid MEX.

A string a is lexicographically smaller than a string b if and only if one of the following holds:

a is a prefix of b, but a≠b;
in the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Find out what the MEX of the string is!

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). Description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤1000) — the length of the word. The second line for each test case contains a single string of n lowercase Latin letters.

The sum of n over all test cases will not exceed 1000.

Output
For each test case, output the MEX of the string on a new line.

Example
inputCopy
3
28
qaabzwsxedcrfvtgbyhnujmiklop
13
cleanairactbd
10
aannttoonn
outputCopy
ac
f
b

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
vs s1, s2, s3;
void lex(ll x, ll y, string s) {
	if (x == y) {
		s1.push_back(s);
		return;
	}
	foi(26) {
		string t = s;
		t += char('a' + i);
		lex(x + 1, y, t);
	}
}
void lex1(ll x, ll y, string s) {
	if (x == y) {
		s2.push_back(s);
		return;
	}
	foi(26) {
		string t = s;
		t += char('a' + i);
		lex1(x + 1, y, t);
	}
}
void lex2(ll x, ll y, string s) {
	if (x == y) {
		s3.push_back(s);
		return;
	}
	foi(26) {
		string t = s;
		t += char('a' + i);
		lex2(x + 1, y, t);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	lex(0, 1, "");
	lex1(0, 2, "");
	lex2(0, 3, "");
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
	ll n;
	cin >> n;
	string s;
	cin >> s;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	sort(s3.begin(), s3.end());
	set<string> st;
	foi(n) {
		foj(4) {
			if (j == 0)
				continue;
			st.insert(s.substr(i, j));
		}
	}
	foi(s1.size()) {
		if (!st.count(s1[i])) {
			cout << s1[i];
			return;
		}
	}
	foi(s2.size()) {
		if (!st.count(s2[i])) {
			cout << s2[i];
			return;
		}
	}
	foi(s3.size()) {
		if (!st.count(s3[i])) {
			cout << s3[i];
			return;
		}
	}


}

/*
C. Two Brackets
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string s, consisting of brackets of two types: '(', ')', '[' and ']'.

A string is called a regular bracket sequence (RBS) if it's of one of the following types:

empty string;
'(' + RBS + ')';
'[' + RBS + ']';
RBS + RBS.
where plus is a concatenation of two strings.

In one move you can choose a non-empty subsequence of the string s (not necessarily consecutive) that is an RBS, remove it from the string and concatenate the remaining parts without changing the order.

What is the maximum number of moves you can perform?

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

Each of the next t lines contains a non-empty string, consisting only of characters '(', ')', '[' and ']'. The total length of the strings over all testcases doesn't exceed 2⋅105.

Output
For each testcase print a single integer — the maximum number of moves you can perform on a given string s.

Example
inputCopy
5
()
[]()
([)]
)]([
)[(]
outputCopy
1
2
2
0
1
Note
In the first example you can just erase the whole string.

In the second example you can first erase the brackets on positions 1 and 2: "[]()", then "()" is left. After that you can erase it whole. You could erase the whole string from the beginning but you would get one move instead of two.

In the third example you can first erase the brackets on positions 1 and 3: "([)]". They form an RBS "()". Then "[]" is left, so you can erase it whole.

In the fourth example there is no subsequence that is an RBS, so you can't perform a move at all.

In the fifth example you can erase the brackets on positions 2 and 4: ")[(]" and get ")(" as a result. You can erase nothing from it
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
	string s;
	cin >> s;
	ll n = s.size();
	ll  ans = 0, s1 = 0, s2 = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '(') {
			s1++;
		}

		if (s[i] == '[') {
			s2++;
		}
		if (s[i] == ')') {
			if (s1) {
				s1--;
				ans++;
			}
		}
		if (s[i] == ']') {
			if (s2) {
				s2--;
				ans++;

			}

		}
	}
	cout << ans;
}


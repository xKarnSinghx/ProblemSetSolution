/*
F2. Promising String (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is the easy version of Problem F. The only difference between the easy version and the hard version is the constraints.

We will call a non-empty string balanced if it contains the same number of plus and minus signs. For example: strings "+--+" and "++-+--" are balanced, and strings "+--", "--" and "" are not balanced.

We will call a string promising if the string can be made balanced by several (possibly zero) uses of the following operation:

replace two adjacent minus signs with one plus sign.
In particular, every balanced string is promising. However, the converse is not true: not every promising string is balanced.

For example, the string "-+---" is promising, because you can replace two adjacent minuses with plus and get a balanced string "-++-", or get another balanced string "-+-+".

How many non-empty substrings of the given string s are promising? Each non-empty promising substring must be counted in the answer as many times as it occurs in string s.

Recall that a substring is a sequence of consecutive characters of the string. For example, for string "+-+" its substring are: "+-", "-+", "+", "+-+" (the string is a substring of itself) and some others. But the following strings are not its substring: "--", "++", "-++".

Input
The first line of the input contains an integer t (1≤t≤104) —the number of test cases in the test.

Then the descriptions of test cases follow.

Each test case of input data consists of two lines. The first line consists of the number n (1≤n≤2⋅105): the length of s.

The second line of the test case contains the string s of length n, consisting only of characters "+" and "-".

It is guaranteed that the sum of values n over all test cases does not exceed 2⋅105.

Output
For each test case, print a single number: the number of the promising non-empty substrings of string s. Each non-empty promising substring must be counted in the answer as many times as it occurs in string s.

Example
inputCopy
5
3
+-+
5
-+---
4
----
7
--+---+
6
+++---
outputCopy
2
4
2
7
4
Note
The following are the promising substrings for the first three test cases in the example:

s[1…2]="+-", s[2…3]="-+";
s[1…2]="-+", s[2…3]="+-", s[1…5]="-+---", s[3…5]="---";
s[1…3]="---", s[2…4]="---".

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
typedef vector<ld>          vld;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<vll, ll>             mvlll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 100010;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
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
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll ans = 0;
	foi(n) {
		ll cnt = 0;
		foj(n) {
			if (j < i)
				continue;
			if (s[j] == '+')
				cnt--;
			else
				cnt++;
			if (cnt >= 0 and cnt % 3 == 0)
				ans++;
		}
	}
	cout << ans;
}

/*
C. Binary String Reconstruction
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Consider the following process. You have a binary string (a string where each character is either 0 or 1) w of length n and an integer x. You build a new binary string s consisting of n characters. The i-th character of s is chosen as follows:

if the character wi−x exists and is equal to 1, then si is 1 (formally, if i>x and wi−x= 1, then si= 1);
if the character wi+x exists and is equal to 1, then si is 1 (formally, if i+x≤n and wi+x= 1, then si= 1);
if both of the aforementioned conditions are false, then si is 0.
You are given the integer x and the resulting string s. Reconstruct the original string w.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

Each test case consists of two lines. The first line contains the resulting string s (2≤|s|≤105, each character of s is either 0 or 1). The second line contains one integer x (1≤x≤|s|−1).

The total length of all strings s in the input does not exceed 105.

Output
For each test case, print the answer on a separate line as follows:

if no string w can produce the string s at the end of the process, print −1;
otherwise, print the binary string w consisting of |s| characters. If there are multiple answers, print any of them.
Example
inputCopy
3
101110
2
01
1
110
1
outputCopy
111011
10
-1
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
string to_oct(ll n) {
	string s;
	while (n) {
		s = to_string(n % 8) + s;
		n /= 8;
	}
	return s;
}
void solve() {
	string s;
	cin >> s;
	ll n;
	cin >> n;
	string w = string(s.size(), '1');
	foi(s.size()) {
		if (s[i] == '0') {
			if (i >= n)
				w[i - n] = '0';
			if (i + n < s.size())
				w[i + n] = '0';
		}
	}
	string t = w;
	foi(s.size()) {
		if ((i + n < s.size() and w[i + n] == '1') or i >= n and w[i - n] == '1')
			t[i] = '1';
		else
			t[i] = '0';
	}
	if (t == s)
		cout << w;
	else
		cout << -1;



}


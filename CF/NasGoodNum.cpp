/*
A. Nastia and Nearly Good Numbers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Nastia has 2 positive integers A and B. She defines that:

The integer is good if it is divisible by A⋅B;
Otherwise, the integer is nearly good, if it is divisible by A.
For example, if A=6 and B=4, the integers 24 and 72 are good, the integers 6, 660 and 12 are nearly good, the integers 16, 7 are neither good nor nearly good.

Find 3 different positive integers x, y, and z such that exactly one of them is good and the other 2 are nearly good, and x+y=z.

Input
The first line contains a single integer t (1≤t≤10000) — the number of test cases.

The first line of each test case contains two integers A and B (1≤A≤106, 1≤B≤106) — numbers that Nastia has.

Output
For each test case print:

"YES" and 3 different positive integers x, y, and z (1≤x,y,z≤1018) such that exactly one of them is good and the other 2 are nearly good, and x+y=z.
"NO" if no answer exists.
You can print each character of "YES" or "NO" in any case.
If there are multiple answers, print any.

Example
inputCopy
3
5 3
13 2
7 11
outputCopy
YES
10 50 60
YES
169 39 208
YES
28 154 182
Note
In the first test case: 60 — good number; 10 and 50 — nearly good numbers.

In the second test case: 208 — good number; 169 and 39 — nearly good numbers.

In the third test case: 154 — good number; 28 and 182 — nearly good numbers.


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
	ll a, b;
	cin >> a >> b;
	ll x = 0, y = 0, z = 0;
	x = a, y = a * b, z = a * (b + 1);
	if (b == 1)
		cout << "NO";
	else {
		cout << "YES" << endl;
		cout << x << " " << y << " " << z ;
	}


}

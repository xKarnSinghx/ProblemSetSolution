/*
B. Last Year's Substring
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp has a string s[1…n] of length n consisting of decimal digits. Polycarp performs the following operation with the string s no more than once (i.e. he can perform operation 0 or 1 time):

Polycarp selects two numbers i and j (1≤i≤j≤n) and removes characters from the s string at the positions i,i+1,i+2,…,j (i.e. removes substring s[i…j]). More formally, Polycarp turns the string s into the string s1s2…si−1sj+1sj+2…sn.
For example, the string s="20192020" Polycarp can turn into strings:

"2020" (in this case (i,j)=(3,6) or (i,j)=(1,4));
"2019220" (in this case (i,j)=(6,6));
"020" (in this case (i,j)=(1,5));
other operations are also possible, only a few of them are listed above.
Polycarp likes the string "2020" very much, so he is wondering if it is possible to turn the string s into a string "2020" in no more than one operation? Note that you can perform zero operations.

Input
The first line contains a positive integer t (1≤t≤1000) — number of test cases in the test. Then t test cases follow.

The first line of each test case contains an integer n (4≤n≤200) — length of the string s. The next line contains a string s of length n consisting of decimal digits. It is allowed that the string s starts with digit 0.

Output
For each test case, output on a separate line:

"YES" if Polycarp can turn the string s into a string "2020" in no more than one operation (i.e. he can perform 0 or 1 operation);
"NO" otherwise.
You may print every letter of "YES" and "NO" in any case you want (so, for example, the strings yEs, yes, Yes and YES will all be recognized as positive answer).

Example
inputCopy
6
8
20192020
8
22019020
4
2020
5
20002
6
729040
6
200200
outputCopy
YES
YES
YES
NO
NO
NO
Note
In the first test case, Polycarp could choose i=3 and j=6.

In the second test case, Polycarp could choose i=2 and j=5.

In the third test case, Polycarp did not perform any operations with the string.


*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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
	ll n;
	cin >> n;
	string s;
	cin >> s;
	for (ll i = 0; i <= 4; i++) {
		if (s.substr(0, i) + s.substr(n - 4 + i, 4 - i) == "2020") {
			cout << "YES" ;
			return;
		}
	}
	cout << "NO" ;

}




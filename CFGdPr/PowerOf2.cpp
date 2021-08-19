/*
D. Make a Power of Two
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an integer n. In 1 move, you can do one of the following actions:

erase any digit of the number (it's acceptable that the number before the operation has exactly one digit and after the operation, it is "empty");
add one digit to the right.
The actions may be performed in any order any number of times.

Note that if, after deleting some digit from a number, it will contain leading zeroes, they will not be deleted. E.g. if you delete from the number 301 the digit 3, the result is the number 01 (not 1).

You need to perform the minimum number of actions to make the number any power of 2 (i.e. there's an integer k (k≥0) such that the resulting number is equal to 2k). The resulting number must not have leading zeroes.

E.g. consider n=1052. The answer is equal to 2. First, let's add to the right one digit 4 (the result will be 10524). Then let's erase the digit 5, so the result will be 1024 which is a power of 2.

E.g. consider n=8888. The answer is equal to 3. Let's erase any of the digits 8 three times. The result will be 8 which is a power of 2.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case consists of one line containing one integer n (1≤n≤109).

Output
For each test case, output in a separate line one integer m — the minimum number of moves to transform the number into any power of 2.

Example
inputCopy
12
1052
8888
6
75
128
1
301
12048
1504
6656
1000000000
687194767
outputCopy
2
3
1
3
0
0
2
1
3
4
9
2
Note
The answer for the first test case was considered above.

The answer for the second test case was considered above.

In the third test case, it's enough to add to the right the digit 4 — the number 6 will turn into 64.

In the fourth test case, let's add to the right the digit 8 and then erase 7 and 5 — the taken number will turn into 8.

The numbers of the fifth and the sixth test cases are already powers of two so there's no need to make any move.

In the seventh test case, you can delete first of all the digit 3 (the result is 01) and then the digit 0 (the result is 1).
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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
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
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
ld PI = 3.1415926535897;
const ll N = 200010;
ull pows(ull x1, ll y1, ll mod)
{
	ull r1 = 1;
	x1 = x1 % mod;
	while (y1 > 0)	{
		if (y1 & 1)
			r1 = (r1 * x1) % mod;
		y1 = y1 >> 1;
		x1 = (x1 * x1) % mod;
	}
	return r1;
}
ull f[N];
ull mi(ull x, ll mod) {
	return pows(x, mod - 2, mod);
}
ull ncr(ull x, ll y, ll mod) {
	if (x < y)
		return 0;
	if (y == 0)
		return 1;
	ll ans = f[x] * mi(f[y], mod) % mod;
	ll z = (ans * mi(f[x - y], mod) % mod) % mod;
	return z % mod;
}
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
	/*foi(N) {
		if (i == 0) {
			f[i] = 1;
			continue;
		}
		f[i] = (f[i - 1] * i) % MOD;
	}*/
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
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
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
string ask(ll x, ll y) {
	cout << x + 1 << " " << y + 1;
	string s;
	cin >> s;
	return s;
}
ll findLCS(string a, string b, ll m, ll n)
{

	ll LCS[m + 1][n + 1];
	ll result = 0;
	for (ll i = 0; i <= m; i++)
	{
		for (ll j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				LCS[i][j] = 0;

			else if (a[i - 1] == b[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				result = max(result, LCS[i][j]);
			}
			else
				LCS[i][j] = 0;
		}
	}
	return result;
}
void solve() {
    string s;
	cin >> s;
	ll ans = 1111111111;
	foi(60) {
		string t = to_string(1ll << i);
		ll k=0;
		foj(s.size()){
		    if(s[j]==t[k]){
		        k++;
		    }
		}
		ans = min(ans, s.size() + t.size() - 2 * k);
	}
	cout << ans;


}


 

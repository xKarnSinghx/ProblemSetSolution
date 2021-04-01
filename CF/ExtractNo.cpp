/*
A. Extract Numbers
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given string s. Let's call word any largest sequence of consecutive symbols without symbols ',' (comma) and ';' (semicolon). For example, there are four words in string "aba,123;1a;0": "aba", "123", "1a", "0". A word can be empty: for example, the string s=";;" contains three empty words separated by ';'.

You should find all words in the given string that are nonnegative INTEGER numbers without leading zeroes and build by them new string a. String a should contain all words that are numbers separating them by ',' (the order of numbers should remain the same as in the string s). By all other words you should build string b in the same way (the order of numbers should remain the same as in the string s).

Here strings "101", "0" are INTEGER numbers, but "01" and "1.0" are not.

For example, for the string aba,123;1a;0 the string a would be equal to "123,0" and string b would be equal to "aba,1a".

Input
The only line of input contains the string s (1 ≤ |s| ≤ 105). The string contains only symbols '.' (ASCII 46), ',' (ASCII 44), ';' (ASCII 59), digits, lowercase and uppercase latin letters.

Output
Print the string a to the first line and string b to the second line. Each string should be surrounded by quotes (ASCII 34).

If there are no words that are numbers print dash (ASCII 45) on the first line. If all words are numbers print dash on the second line.

Examples
inputCopy
aba,123;1a;0
outputCopy
"123,0"
"aba,1a"
inputCopy
1;;01,a0,
outputCopy
"1"
",01,a0,"
inputCopy
1
outputCopy
"1"
-
inputCopy
a
outputCopy
-
"a"
Note
In the second example the string s contains five words: "1", "", "01", "a0", "".


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
typedef pair<pll, ll>      plll;
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


		solve();


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
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
vb is_prime(1e6 + 1, true);

ll binomialCoeffSpaceEff(ll n, ll k)
{
	ll C[k + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // nC0 is 1

	for (ll i = 1; i <= n; i++) {
		// Compute next row of pascal triangle using
		// the previous row
		for (ll j = min(i, k); j > 0; j--)
			C[j] = (C[j] + C[j - 1]) % MOD;
	}
	return C[k];
}
ll primeFactors(ll n)
{
	vll ar;
	ll i = 2;
	while (n > 0)
	{
		if (i > n) break;
		if (n % i == 0)
		{
			ar.pb(i);
			while (n > 0 and n % i == 0) n = n / i;
		}
		i++;
	}
	return ar.size();
}

vpll primeFactorsFreq(ll n)
{
	vpll ar;
	ll i = 2;
	while (n > 0)
	{
		// cout<<n<<" ";
		if (i > n) break;
		if (n % i == 0)
		{
			ll cnt = 0;
			while (n > 0 and n % i == 0) n = n / i, cnt++;
			ar.pb(mp(i, cnt));
		}
		i++;
	}
	return ar;
}
void seive()
{
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= 1e6 + 1; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= 1e6 + 1; j += i)
				is_prime[j] = false;
		}
	}
}

bool isSorted(vll &ar)
{
	ll n = ar.size();

	for (ll i = 0; i < n - 1; i++)
	{
		if (ar[i + 1] < ar[i]) return false;
	}

	return true;
}

ll fastPower(ll x, ll y)
{
	ll res = 1;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % MOD;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % MOD; // Change x to x^2
	}
	return res;
}

ll kadanesAlgo(vll ar)
{
	ll n = ar.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	for (ll i = 0; i < n; i++)
	{
		currMax += ar[i];

		if (currMax <= ar[i])
		{
			currMax = ar[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}

pll kadanesAlgoIdx(vll ar)
{
	ll n = ar.size();
	ll currMax = 0;
	ll mx = INT_MIN;
	ll a = 0, b;
	for (ll i = 0; i < n; i++)
	{
		currMax += ar[i];

		if (currMax <= ar[i])
		{
			currMax = ar[i];
			a = i;
		}

		if (mx < currMax)
		{
			mx = currMax;
			b = i;
		}
	}
	return mp(a, b);
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
ll fac(ll n) {
	while (n % 4 == 0) {
		n /= 4;
	}
	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % (i * i) == 0) {
			n /= (i * i);
		}
	}
	return n;
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
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll f(ll x) {
	ll d = 0;
	while (x > 0)
	{
		d += x % 10;
		x /= 10;
	}

	return d;
}
void solve()
{
	string s;
	cin >> s;
	string i = "", w = "", t = "";
	i += '"', w += '"';
	ll f = 0;
	foj(s.size()) {
		if ( s[j] <= 'z' and s[j] >= 'a' or s[j] <= 'Z' and s[j] >= 'A'  and f == 0 ) {
			f = 2;
			t += s[j];
		}
		else if (s[j] == ';' or s[j] == ',') {
			if (f == 0) {
				w += t;
				t.clear();
				w += ',';
				f = 0;
			}

			if (f == 1) {
				if (t.size() != 1 and t[0] == '0') {
					w += t;
					t.clear();
					w += ',';
					f = 0;

				}
				else {
					i += t;
					t.clear();
					i += ',';
					f = 0;
				}
			}
			if (f == 2) {
				w += t;
				t.clear();
				w += ',';
				f = 0;
			}
			if (j == s.size() - 1) {
				w += ',';
				f = 0;
			}
		}
		else if ( f == 2 ) {
			t += s[j];
		}
		else if ((s[j] != ';' or s[j] != ',' ) and f != 2) {
			f = 1;
			t += s[j];
			if ( s[j] <= 'z' and s[j] >= 'a' or s[j] <= 'Z' and s[j] >= 'A' or s[j] == '.')
				f = 2;
		}
		else if ((s[j] != ';' or s[j] != ',' ) and f == 1) {
			t += s[j];

		}

	}
	if (f == 1) {
		if (t.size() != 1 and t[0] == '0') {
			w += t;
			t.clear();
			w += ',';
			f = 0;

		}
		else {
			i += t;
			t.clear();
			i += ',';
			f = 0;
		}
	}
	if (f == 2) {
		w += t;
		t.clear();
		w += ',';
		f = 0;
	}


	string ans1 = "", ans2 = "";
	if (i.size() == 1) {
		ans1 += "-";
	}
	if (w.size() == 1) {
		ans2 += "-";
	}
	if (i.size() != 1) {
		foj(i.size() - 1) {
			ans1 += i[j];
		}
		ans1 += '"';
	}
	if (w.size() != 1) {
		foj(w.size() - 1) {
			ans2 += w[j];
		}
		ans2 += '"';
	}
	cout << ans1 << endl;
	cout << ans2;

}
 

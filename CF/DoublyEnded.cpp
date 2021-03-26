/*
C. Double-ended Strings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given the strings a and b, consisting of lowercase Latin letters. You can do any number of the following operations in any order:

if |a|>0 (the length of the string a is greater than zero), delete the first character of the string a, that is, replace a with a2a3…an;
if |a|>0, delete the last character of the string a, that is, replace a with a1a2…an−1;
if |b|>0 (the length of the string b is greater than zero), delete the first character of the string b, that is, replace b with b2b3…bn;
if |b|>0, delete the last character of the string b, that is, replace b with b1b2…bn−1.
Note that after each of the operations, the string a or b may become empty.

For example, if a="hello" and b="icpc", then you can apply the following sequence of operations:

delete the first character of the string a ⇒ a="ello" and b="icpc";
delete the first character of the string b ⇒ a="ello" and b="cpc";
delete the first character of the string b ⇒ a="ello" and b="pc";
delete the last character of the string a ⇒ a="ell" and b="pc";
delete the last character of the string b ⇒ a="ell" and b="p".
For the given strings a and b, find the minimum number of operations for which you can make the strings a and b equal. Note that empty strings are also equal.

Input
The first line contains a single integer t (1≤t≤100). Then t test cases follow.

The first line of each test case contains the string a (1≤|a|≤20), consisting of lowercase Latin letters.

The second line of each test case contains the string b (1≤|b|≤20), consisting of lowercase Latin letters.

Output
For each test case, output the minimum number of operations that can make the strings a and b equal.

Example
inputCopy
5
a
a
abcd
bc
hello
codeforces
hello
helo
dhjakjsnasjhfksafasd
adjsnasjhfksvdafdser
outputCopy
0
2
13
3
20

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

	ll LCSuff[m + 1][n + 1];
	ll result = 0;
	for (ll i = 0; i <= m; i++)
	{
		for (ll j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				LCSuff[i][j] = 0;

			else if (a[i - 1] == b[j - 1]) {
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				result = max(result, LCSuff[i][j]);
			}
			else
				LCSuff[i][j] = 0;
		}
	}
	return result;
}

void solve()
{
	string s, s1;
	cin >> s >> s1;
	ll n = s.size(), n1 = s1.size();
	ll ans = 0;
	foi(n) {
		foj(n1)
		{
			ll ans1 = 0;
			while (s[i + ans1] == s1[j + ans1])
			{
				ans1++;
				if ((i + ans1) == n or (j + ans1) == n1)
					break;
			}
			ans = max(ans1, ans);
		}
	}
	cout << n + n1 - 2 * ans;



}



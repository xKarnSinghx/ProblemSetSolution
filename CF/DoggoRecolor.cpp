/*
A. Doggo Recoloring
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Panic is rising in the committee for doggo standardization — the puppies of the new brood have been born multi-colored! In total there are 26 possible colors of puppies in the nature and they are denoted by letters from 'a' to 'z' inclusive.

The committee rules strictly prohibit even the smallest diversity between doggos and hence all the puppies should be of the same color. Thus Slava, the committee employee, has been assigned the task to recolor some puppies into other colors in order to eliminate the difference and make all the puppies have one common color.

Unfortunately, due to bureaucratic reasons and restricted budget, there's only one operation Slava can perform: he can choose a color x such that there are currently at least two puppies of color x and recolor all puppies of the color x into some arbitrary color y. Luckily, this operation can be applied multiple times (including zero).

For example, if the number of puppies is 7 and their colors are represented as the string "abababc", then in one operation Slava can get the results "zbzbzbc", "bbbbbbc", "aaaaaac", "acacacc" and others. However, if the current color sequence is "abababc", then he can't choose x='c' right now, because currently only one puppy has the color 'c'.

Help Slava and the committee determine whether it is possible to standardize all the puppies, i.e. after Slava's operations all the puppies should have the same color.

Input
The first line contains a single integer n (1≤n≤105) — the number of puppies.

The second line contains a string s of length n consisting of lowercase Latin letters, where the i-th symbol denotes the i-th puppy's color.

Output
If it's possible to recolor all puppies into one color, print "Yes".

Otherwise print "No".

Output the answer without quotation signs.

Examples
inputCopy
6
aabddc
outputCopy
Yes
inputCopy
3
abc
outputCopy
No
inputCopy
3
jjj
outputCopy
Yes
Note
In the first example Slava can perform the following steps:

take all puppies of color 'a' (a total of two) and recolor them into 'b';
take all puppies of color 'd' (a total of two) and recolor them into 'c';
take all puppies of color 'b' (three puppies for now) and recolor them into 'c'.
In the second example it's impossible to recolor any of the puppies.

In the third example all the puppies' colors are the same; thus there's no need to recolor anything.


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
typedef map<pair<ll, ll>, ll>  mplll;
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
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
//	ll t ; cin >> t;
//	while (t--)
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
	vll a(26, 0);
	foi(n)
	{
		a[s[i] - 'a']++;
		if (a[s[i] - 'a'] == 2) {
			cout << "Yes";
			return ;
		}
	}
	if (n == 1)
		cout << "Yes";
	else
		cout << "No";
}

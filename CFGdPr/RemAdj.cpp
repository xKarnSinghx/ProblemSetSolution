/*
C. Remove Adjacent
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string s consisting of lowercase Latin letters. Let the length of s be |s|. You may perform several operations on this string.

In one operation, you can choose some index i and remove the i-th character of s (si) if at least one of its adjacent characters is the previous letter in the Latin alphabet for si. For example, the previous letter for b is a, the previous letter for s is r, the letter a has no previous letters. Note that after each removal the length of the string decreases by one. So, the index i should satisfy the condition 1≤i≤|s| during each operation.

For the character si adjacent characters are si−1 and si+1. The first and the last characters of s both have only one adjacent character (unless |s|=1).

Consider the following example. Let s= bacabcab.

During the first move, you can remove the first character s1= b because s2= a. Then the string becomes s= acabcab.
During the second move, you can remove the fifth character s5= c because s4= b. Then the string becomes s= acabab.
During the third move, you can remove the sixth character s6='b' because s5= a. Then the string becomes s= acaba.
During the fourth move, the only character you can remove is s4= b, because s3= a (or s5= a). The string becomes s= acaa and you cannot do anything with it.
Your task is to find the maximum possible number of characters you can remove if you choose the sequence of operations optimally.

Input
The first line of the input contains one integer |s| (1≤|s|≤100) — the length of s.

The second line of the input contains one string s consisting of |s| lowercase Latin letters.

Output
Print one integer — the maximum possible number of characters you can remove if you choose the sequence of moves optimally.

Examples
inputCopy
8
bacabcab
outputCopy
4
inputCopy
4
bcda
outputCopy
3
inputCopy
6
abbbbb
outputCopy
5
Note
The first example is described in the problem statement. Note that the sequence of moves provided in the statement is not the only, but it can be shown that the maximum possible answer to this test is 4.

In the second example, you can remove all but one character of s. The only possible answer follows.

During the first move, remove the third character s3= d, s becomes bca.
During the second move, remove the second character s2= c, s becomes ba.
And during the third move, remove the first character s1= b, s becomes a.

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
		cout << endl;
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
ll ask(ll x, ll y) {
	cout << "? " << x << " " << y << endl;
	ll z;
	cin >> z;
	return z;
}
qll l;
vsll g;
void solve() {
	ll n;
	cin >> n;
	g.resize(n + 1);
	foi(n - 1) {
		ll x, y;
		cin >> x >> y;
		g[x].insert(y);
		g[y].insert(x);
	}
	foi(n+1) {
	    if(i==0)
	    continue;
		if (g[i].size() == 1) {
			l.push(i);
		}
	}
	while (true) {
		if (l.size() == 1) {
			cout << "! " << l.front() << endl;
			return;
		}
		ll a = l.front();
		l.pop();
		ll b = l.front();
		l.pop();
		ll ans=ask(a,b);
		if (ans == a or ans == b) {
			cout << "! " << ans << endl;
			return;
		}
		ll x = *g[a].begin(), y = *g[b].begin();
		g[x].erase(a), g[y].erase(b);
		if (g[x].size() <= 1) {
			l.push(x);
		}
		if (x != y and g[y].size() <= 1) {
			l.push(y);
		}
	}

}

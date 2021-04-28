/*
D. Suitable Replacement
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two strings s and t consisting of small Latin letters, string s can also contain '?' characters.

Suitability of string s is calculated by following metric:

Any two letters can be swapped positions, these operations can be performed arbitrary number of times over any pair of positions. Among all resulting strings s, you choose the one with the largest number of non-intersecting occurrences of string t. Suitability is this number of occurrences.

You should replace all '?' characters with small Latin letters in such a way that the suitability of string s is maximal.

Input
The first line contains string s (1 ≤ |s| ≤ 106).

The second line contains string t (1 ≤ |t| ≤ 106).

Output
Print string s with '?' replaced with small Latin letters in such a way that suitability of that string is maximal.

If there are multiple strings with maximal suitability then print any of them.

Examples
inputCopy
?aa?
ab
outputCopy
baab
inputCopy
??b?
za
outputCopy
azbz
inputCopy
abcd
abacaba
outputCopy
abcd
Note
In the first example string "baab" can be transformed to "abab" with swaps, this one has suitability of 2. That means that string "baab" also has suitability of 2.

In the second example maximal suitability you can achieve is 1 and there are several dozens of such strings, "azbz" is just one of them.

In the third example there are no '?' characters and the suitability of the string is 0.


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
ll TT = 1;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


//	ll tc ; cin >> tc;
//	while (tc--)
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
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

void solve()
{
	string s, t;
	cin >> s >> t;
	ll n = s.size(), m = t.size(), cnt[27] = {};
	foi(n)
	if (s[i] != '?') {
		cnt[s[i] - 'a']++;
	}
	ll x = 0;
	foi(n) {
		if (s[i] == '?') {
			x++;
			x %= m;
			if (cnt[t[x] - 'a']) {
				cnt[t[x] - 'a']--;
				i--;
			} else {
				s[i] = t[x];
			}
		}
	}
	cout << s;

}

 

/*
A. Split it!
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kawashiro Nitori is a girl who loves competitive programming.

One day she found a string and an integer. As an advanced problem setter, she quickly thought of a problem.

Given a string s and a parameter k, you need to check if there exist k+1 non-empty strings a1,a2...,ak+1, such that
s=a1+a2+…+ak+ak+1+R(ak)+R(ak−1)+…+R(a1).
Here + represents concatenation. We define R(x) as a reversed string x. For example R(abcd)=dcba. Note that in the formula above the part R(ak+1) is intentionally skipped.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤100)  — the number of test cases. The description of the test cases follows.

The first line of each test case description contains two integers n, k (1≤n≤100, 0≤k≤⌊n2⌋)  — the length of the string s and the parameter k.

The second line of each test case description contains a single string s of length n, consisting of lowercase English letters.

Output
For each test case, print "YES" (without quotes), if it is possible to find a1,a2,…,ak+1, and "NO" (without quotes) otherwise.

You can print letters in any case (upper or lower).

Example
inputCopy
7
5 1
qwqwq
2 1
ab
3 1
ioi
4 2
icpc
22 0
dokidokiliteratureclub
19 8
imteamshanghaialice
6 3
aaaaaa
outputCopy
YES
NO
YES
NO
YES
NO
NO
Note
In the first test case, one possible solution is a1=qw and a2=q.

In the third test case, one possible solution is a1=i and a2=o.

In the fifth test case, one possible solution is a1=dokidokiliteratureclub.
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



	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll f = 0;


	for (ll i = 0; i < k ; i++) {
		if (s[i] != s[n-i-1])
		{	f = 1;
			break;
		}
	}
	if (2*k >=n)
		cout << "NO";
	else if (f ==1 )
		cout << "NO";
	else
		cout << "YES";

}

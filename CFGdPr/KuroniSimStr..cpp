/*
B. Kuroni and Simple Strings
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Now that Kuroni has reached 10 years old, he is a big boy and doesn't like arrays of integers as presents anymore. This year he wants a Bracket sequence as a Birthday present. More specifically, he wants a bracket sequence so complex that no matter how hard he tries, he will not be able to remove a simple subsequence!

We say that a string formed by n characters '(' or ')' is simple if its length n is even and positive, its first n2 characters are '(', and its last n2 characters are ')'. For example, the strings () and (()) are simple, while the strings )( and ()() are not simple.

Kuroni will be given a string formed by characters '(' and ')' (the given string is not necessarily simple). An operation consists of choosing a subsequence of the characters of the string that forms a simple string and removing all the characters of this subsequence from the string. Note that this subsequence doesn't have to be continuous. For example, he can apply the operation to the string ')()(()))', to choose a subsequence of bold characters, as it forms a simple string '(())', delete these bold characters from the string and to get '))()'.

Kuroni has to perform the minimum possible number of operations on the string, in such a way that no more operations can be performed on the remaining string. The resulting string does not have to be empty.

Since the given string is too large, Kuroni is unable to figure out how to minimize the number of operations. Can you help him do it instead?

A sequence of characters a is a subsequence of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters.

Input
The only line of input contains a string s (1≤|s|≤1000) formed by characters '(' and ')', where |s| is the length of s.

Output
In the first line, print an integer k  — the minimum number of operations you have to apply. Then, print 2k lines describing the operations in the following format:

For each operation, print a line containing an integer m  — the number of characters in the subsequence you will remove.

Then, print a line containing m integers 1≤a1<a2<⋯<am  — the indices of the characters you will remove. All integers must be less than or equal to the length of the current string, and the corresponding subsequence must form a simple string.

If there are multiple valid sequences of operations with the smallest k, you may print any of them.

Examples
inputCopy
(()((
outputCopy
1
2
1 3 
inputCopy
)(
outputCopy
0
inputCopy
(()())
outputCopy
1
4
1 2 5 6 
Note
In the first sample, the string is '(()(('. The operation described corresponds to deleting the bolded subsequence. The resulting string is '(((', and no more operations can be performed on it. Another valid answer is choosing indices 2 and 3, which results in the same final string.

In the second sample, it is already impossible to perform any operations.
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

void solve() {
	string s;
	cin >> s;
	vll a;
	ll i = 0, j = s.size() - 1;
	while (i < j)
	{
		if (s[i] == '(')
		{
			while (j > i)
			{
				if (s[j] == ')')
				{
					a.pb(i + 1);
					a.pb(j + 1);
					j--;
					break;
				}
				j--;
			}
		}
		i++;
	}
	if (a.size()) {
		cout << 1 << endl;
	}
	else {
		cout << 0;
		return;
	}
	cout<<a.size()<<endl;
	sort(all(a));
	foi(a.size()) {
		cout << a[i] << " ";
	}

}


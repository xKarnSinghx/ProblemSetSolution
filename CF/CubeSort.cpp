/*
A. Cubes Sorting
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
For god's sake, you're boxes with legs! It is literally your only purpose! Walking onto buttons! How can you not do the one thing you were designed for?
Oh, that's funny, is it? Oh it's funny? Because we've been at this for twelve hours and you haven't solved it either, so I don't know why you're laughing. You've got one hour! Solve it!

Wheatley decided to try to make a test chamber. He made a nice test chamber, but there was only one detail absent — cubes.

For completing the chamber Wheatley needs n cubes. i-th cube has a volume ai.

Wheatley has to place cubes in such a way that they would be sorted in a non-decreasing order by their volume. Formally, for each i>1, ai−1≤ai must hold.

To achieve his goal, Wheatley can exchange two neighbouring cubes. It means that for any i>1 you can exchange cubes on positions i−1 and i.

But there is a problem: Wheatley is very impatient. If Wheatley needs more than n⋅(n−1)2−1 exchange operations, he won't do this boring work.

Wheatly wants to know: can cubes be sorted under this conditions?

Input
Each test contains multiple test cases.

The first line contains one positive integer t (1≤t≤1000), denoting the number of test cases. Description of the test cases follows.

The first line of each test case contains one positive integer n (2≤n≤5⋅104) — number of cubes.

The second line contains n positive integers ai (1≤ai≤109) — volumes of cubes.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, print a word in a single line: "YES" (without quotation marks) if the cubes can be sorted and "NO" (without quotation marks) otherwise.

Example
inputCopy
3
5
5 3 2 1 4
6
2 2 2 2 2 2
2
2 1
outputCopy
YES
YES
NO
Note
In the first test case it is possible to sort all the cubes in 7 exchanges.

In the second test case the cubes are already sorted.

In the third test case we can make 0 exchanges, but the cubes are not sorted yet, so the answer is "NO".

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
	ll n;
	cin >> n;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	ll cnt = 0;
	foi(n - 1) {
		if (a[i] > a[i + 1])
			cnt++;
	}
	if (cnt == n - 1)
		cout << "NO";
	else
		cout << "YES";

}

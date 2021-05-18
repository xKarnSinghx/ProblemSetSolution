/*
C. Omkar and Baseball
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Patrick likes to play baseball, but sometimes he will spend so many hours hitting home runs that his mind starts to get foggy! Patrick is sure that his scores across n sessions follow the identity permutation (ie. in the first game he scores 1 point, in the second game he scores 2 points and so on). However, when he checks back to his record, he sees that all the numbers are mixed up!

Define a special exchange as the following: choose any subarray of the scores and permute elements such that no element of subarray gets to the same position as it was before the exchange. For example, performing a special exchange on [1,2,3] can yield [3,1,2] but it cannot yield [3,2,1] since the 2 is in the same position.

Given a permutation of n integers, please help Patrick find the minimum number of special exchanges needed to make the permutation sorted! It can be proved that under given constraints this number doesn't exceed 1018.

An array a is a subarray of an array b if a can be obtained from b by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

The first line of each test case contains integer n (1≤n≤2⋅105)  — the length of the given permutation.

The second line of each test case contains n integers a1,a2,...,an (1≤ai≤n)  — the initial permutation.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output one integer: the minimum number of special exchanges needed to sort the permutation.

Example
inputCopy
2
5
1 2 3 4 5
7
3 2 4 5 1 6 7
outputCopy
0
2
Note
In the first permutation, it is already sorted so no exchanges are needed.

It can be shown that you need at least 2 exchanges to sort the second permutation.

[3,2,4,5,1,6,7]
Perform special exchange on range (1,5)

[4,1,2,3,5,6,7]
Perform special exchange on range (1,4)

[1,2,3,4,5,6,7]
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
	ll ans = 1, c = 0, d = 0;
	foi(n - 1) {
		if (a[i] >= a[i + 1])
			c++;
	}
	ll x = 0, y = n - 1;
	while (a[x] == x + 1)
		x++;
	while (a[y] == y + 1)
		y--;
	for (ll i = x; i <= y; i++) {
		if (a[i] == i + 1)
			d++;
	}
	if (c == 0)
		cout << c;
	else if (d)
		cout << 2;
	else
		cout << 1;
}


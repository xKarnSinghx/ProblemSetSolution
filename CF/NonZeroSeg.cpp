/*
D. Non-zero Segments
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kolya got an integer array a1,a2,…,an. The array can contain both positive and negative integers, but Kolya doesn't like 0, so the array doesn't contain any zeros.

Kolya doesn't like that the sum of some subsegments of his array can be 0. The subsegment is some consecutive segment of elements of the array.

You have to help Kolya and change his array in such a way that it doesn't contain any subsegments with the sum 0. To reach this goal, you can insert any integers between any pair of adjacent elements of the array (integers can be really any: positive, negative, 0, any by absolute value, even such a huge that they can't be represented in most standard programming languages).

Your task is to find the minimum number of integers you have to insert into Kolya's array in such a way that the resulting array doesn't contain any subsegments with the sum 0.

Input
The first line of the input contains one integer n (2≤n≤200000) — the number of elements in Kolya's array.

The second line of the input contains n integers a1,a2,…,an (−109≤ai≤109,ai≠0) — the description of Kolya's array.

Output
Print the minimum number of integers you have to insert into Kolya's array in such a way that the resulting array doesn't contain any subsegments with the sum 0.

Examples
inputCopy
4
1 -5 3 2
outputCopy
1
inputCopy
5
4 -2 3 -9 2
outputCopy
0
inputCopy
9
-1 1 -1 1 -1 1 1 -1 -1
outputCopy
6
inputCopy
8
16 -5 -11 -15 10 5 4 -4
outputCopy
3
Note
Consider the first example. There is only one subsegment with the sum 0. It starts in the second element and ends in the fourth element. It's enough to insert one element so the array doesn't contain any subsegments with the sum equal to zero. For example, it is possible to insert the integer 1 between second and third elements of the array.

There are no subsegments having sum 0 in the second example so you don't need to do anything.


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


//	ll t ; cin >> t;
	//while (t--)
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
	mll m;
	m[0] = 1;
	ll s = 0, ans = 0;
	foi(n)
	{
		ll x;
		cin >> x;
		s += x;
		if (m[s]) {
			ans++, s = x, m.clear(), m[0] = 1;
		}
		m[s] = 1;
	}
	cout << ans;
}

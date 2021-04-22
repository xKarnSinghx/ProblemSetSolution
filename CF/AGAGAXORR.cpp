/*
B. AGAGA XOOORRR
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Baby Ehab is known for his love for a certain operation. He has an array a of length n, and he decided to keep doing the following operation on it:

he picks 2 adjacent elements; he then removes them and places a single integer in their place: their bitwise XOR. Note that the length of the array decreases by one.
Now he asks you if he can make all elements of the array equal. Since babies like to make your life harder, he requires that you leave at least 2 elements remaining.

Input
The first line contains an integer t (1≤t≤15) — the number of test cases you need to solve.

The first line of each test case contains an integers n (2≤n≤2000) — the number of elements in the array a.

The second line contains n space-separated integers a1, a2, …, an (0≤ai<230) — the elements of the array a.

Output
If Baby Ehab can make all elements equal while leaving at least 2 elements standing, print "YES". Otherwise, print "NO".

Example
inputCopy
2
3
0 2 2
4
2 3 1 10
outputCopy
YES
NO
Note
In the first sample, he can remove the first 2 elements, 0 and 2, and replace them by 0⊕2=2. The array will be [2,2], so all the elements are equal.

In the second sample, there's no way to make all the elements equal.


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
void solve()
{
	ll n;
	cin >> n ;
	ll a[n], s = 0;
	foi(n) {
		cin >> a[i];
		s ^= a[i];
	}
	if (s == 0) {
		cout << "YES";
		return;
	}
	else {
		ll x = 0, cnt = 0;
		foi(n) {
			x ^= a[i];
			if (x == s)
				cnt++, x = 0;
		}
		if (cnt >= 2)
			cout << "YES";
		else
			cout << "NO";
	}

}



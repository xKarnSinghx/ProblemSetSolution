/*
B. WeirdSort
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of length n.

You are also given a set of distinct positions p1,p2,…,pm, where 1≤pi<n. The position pi means that you can swap elements a[pi] and a[pi+1]. You can apply this operation any number of times for each of the given positions.

Your task is to determine if it is possible to sort the initial array in non-decreasing order (a1≤a2≤⋯≤an) using only allowed swaps.

For example, if a=[3,2,1] and p=[1,2], then we can first swap elements a[2] and a[3] (because position 2 is contained in the given set p). We get the array a=[3,1,2]. Then we swap a[1] and a[2] (position 1 is also contained in p). We get the array a=[1,3,2]. Finally, we swap a[2] and a[3] again and get the array a=[1,2,3], sorted in non-decreasing order.

You can see that if a=[4,1,2,3] and p=[3,2] then you cannot sort the array.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤100) — the number of test cases.

Then t test cases follow. The first line of each test case contains two integers n and m (1≤m<n≤100) — the number of elements in a and the number of elements in p. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤100). The third line of the test case contains m integers p1,p2,…,pm (1≤pi<n, all pi are distinct) — the set of positions described in the problem statement.

Output
For each test case, print the answer — "YES" (without quotes) if you can sort the initial array in non-decreasing order (a1≤a2≤⋯≤an) using only allowed swaps. Otherwise, print "NO".

Example
inputCopy
6
3 2
3 2 1
1 2
4 2
4 1 2 3
3 2
5 1
1 2 3 4 5
1
4 2
2 1 4 3
1 3
4 2
4 3 2 1
1 3
5 2
2 1 2 3 3
1 4
outputCopy
YES
NO
YES
YES
NO
YES

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
	ll n, m;
	cin >> n >> m;
	ll a[n], p[m], ok = 0;
	foi(n)
	cin >> a[i];
	foi(m)
	cin >> p[i];
	sort(p, p + m);
	foj(n) {
		foi(m) {
			if (a[p[i] - 1] > a[p[i]])
				swap(a[p[i] - 1], a[p[i]]);
		}
	}
	foi(n - 1) {
		if (a[i] > a[i + 1]) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

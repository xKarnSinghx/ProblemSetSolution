/*
B. Arrays Sum
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a non-decreasing array of non-negative integers a1,a2,…,an. Also you are given a positive integer k.

You want to find m non-decreasing arrays of non-negative integers b1,b2,…,bm, such that:

The size of bi is equal to n for all 1≤i≤m.
For all 1≤j≤n, aj=b1,j+b2,j+…+bm,j. In the other word, array a is the sum of arrays bi.
The number of different elements in the array bi is at most k for all 1≤i≤m.
Find the minimum possible value of m, or report that there is no possible m.

Input
The first line contains one integer t (1≤t≤100): the number of test cases.

The first line of each test case contains two integers n, k (1≤n≤100, 1≤k≤n).

The second line contains n integers a1,a2,…,an (0≤a1≤a2≤…≤an≤100, an>0).

Output
For each test case print a single integer: the minimum possible value of m. If there is no such m, print −1.

Example
inputCopy
6
4 1
0 0 0 1
3 1
3 3 3
11 3
0 1 2 2 3 3 3 4 4 4 4
5 3
1 2 3 4 5
9 4
2 2 3 5 7 11 13 13 17
10 7
0 1 1 2 3 3 4 5 5 6
outputCopy
-1
1
2
2
2
1
Note
In the first test case, there is no possible m, because all elements of all arrays should be equal to 0. But in this case, it is impossible to get a4=1 as the sum of zeros.

In the second test case, we can take b1=[3,3,3]. 1 is the smallest possible value of m.

In the third test case, we can take b1=[0,1,1,1,2,2,2,2,2,2,2] and b2=[0,0,1,1,1,1,1,2,2,2,2]. It's easy to see, that ai=b1,i+b2,i for all i and the number of different elements in b1 and in b2 is equal to 3 (so it is at most 3). It can be proven that 2 is the smallest possible value of m.


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
	ll n, k;
	cin >> n >> k;
	ll a[n], s = 0;
	foi(n)
	cin >> a[i];
	foi(n - 1) {
		if (a[i] == a[i + 1])
			s++;
	}
	if (k == 1) {
		if (s == n - 1) {
			cout << 1;
		}
		else
			cout << -1;
		return;
	}
	else if (s == n - 1)
		cout << 1;
	else
		cout << ceils(n - s - 1, k - 1);



}

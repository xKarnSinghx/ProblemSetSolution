/*
K. King's Task
time limit per test3 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
The brave Knight came to the King and asked permission to marry the princess. The King knew that the Knight was brave, but he also wanted to know if he was smart enough. So he asked him to solve the following task.

There is a permutation pi of numbers from 1 to 2n. You can make two types of operations.

Swap p1 and p2, p3 and p4, ..., p2n−1 and p2n.
Swap p1 and pn+1, p2 and pn+2, ..., pn and p2n.
The task is to find the minimal number of operations required to sort the given permutation.

The Knight was not that smart actually, but quite charming, so the princess asks you to help him to solve the King's task.

Input
The first line contains the integer n (1≤n≤1000). The second line contains 2n integers pi — the permutation of numbers from 1 to 2n.

Output
Print one integer — the minimal number of operations required to sort the permutation. If it is impossible to sort the permutation using these operations, print −1.

Examples
inputCopy
3
6 3 2 5 4 1
outputCopy
3
inputCopy
2
3 4 2 1
outputCopy
-1
inputCopy
4
1 2 3 4 5 6 7 8
outputCopy
0
Note
In the first example, you can sort the permutation in three operations:

Make operation 1: 3,6,5,2,1,4.
Make operation 2: 2,1,4,3,6,5.
Make operation 1: 1,2,3,4,5,6.

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
	ll a[2 * n], f = 0;
	foi(2 * n) {
		cin >> a[i];
	}
	foi(2 * n - 1) {
		if (a[i + 1] < a[i]) {
			f = 1;
			break;
		}
	}
	if (f == 0) {
		cout << 0;
		return;
	}
	ll f1 = 0;
	ll cnt = 2 * n;
	foi(2 * n) {
		foj(2 * n - 1) {
			if (a[j + 1] < a[j]) {
				f1 = 1;
				break;
			}
		}
		if (f1 == 0)
			cnt = min(cnt, min(i, 2 * n - i));
		if (i % 2) {
			for (ll j = 0; j < 2 * n; j += 2)
				swap(a[j], a[j + 1]);
		}
		else {
			for (ll j = 0; j < n; j++)
				swap(a[j], a[j + n]);
		}
		if (f1 and i != 2 * n - 1)
			f1 = 0 ;
	}
	if (cnt == 2 * n)
		cout << -1;
	else
		cout << cnt;


}

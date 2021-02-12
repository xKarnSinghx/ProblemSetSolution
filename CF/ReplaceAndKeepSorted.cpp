/*
B. Replace and Keep Sorted
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Given a positive integer k, two arrays are called k-similar if:

they are strictly increasing;
they have the same length;
all their elements are positive integers between 1 and k (inclusive);
they differ in exactly one position.
You are given an integer k, a strictly increasing array a and q queries. For each query, you are given two integers li≤ri. Your task is to find how many arrays b exist, such that b is k-similar to array [ali,ali+1…,ari].

Input
The first line contains three integers n, q and k (1≤n,q≤105, n≤k≤109) — the length of array a, the number of queries and number k.

The second line contains n integers a1,a2,…,an (1≤ai≤k). This array is strictly increasing  — a1<a2<…<an.

Each of the following q lines contains two integers li, ri (1≤li≤ri≤n).

Output
Print q lines. The i-th of them should contain the answer to the i-th query.

Examples
inputCopy
4 2 5
1 2 4 5
2 3
3 4
outputCopy
4
3
inputCopy
6 5 10
2 4 6 7 8 9
1 4
1 2
3 5
1 6
5 5
outputCopy
8
9
7
6
9
Note
In the first example:

In the first query there are 4 arrays that are 5-similar to [2,4]: [1,4],[3,4],[2,3],[2,5].

In the second query there are 3 arrays that are 5-similar to [4,5]: [1,5],[2,5],[3,5].
TAG:  dp    implementation    math
*/
#include<bits/stdc++.h>
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
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

	//int t ; cin >> t;
	//while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()

{
	ll n, q, k;
	cin >> n >> q >> k;
	ll a[n];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	vpll b(q + 1);
	for (ll i = 1; i <= q; i++) {
		cin >> b[i].first >> b[i].second;

	}



	for (ll i = 1; i <= q; i++) {
		ll c = 0;
		c +=  1 + a[b[i].ss] - a[b[i].ff ]  + k - 2 * b[i].ss + 2 * b[i].ff - 2;
		cout << c  << "\n";
	}



}
 

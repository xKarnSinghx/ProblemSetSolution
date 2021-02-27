/*
F. Graph Without Long Directed Paths
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a connected undirected graph consisting of n vertices and m edges. There are no self-loops or multiple edges in the given graph.

You have to direct its edges in such a way that the obtained directed graph does not contain any paths of length two or greater (where the length of path is denoted as the number of traversed edges).

Input
The first line contains two integer numbers n and m (2≤n≤2⋅105, n−1≤m≤2⋅105) — the number of vertices and edges, respectively.

The following m lines contain edges: edge i is given as a pair of vertices ui, vi (1≤ui,vi≤n, ui≠vi). There are no multiple edges in the given graph, i. e. for each pair (ui,vi) there are no other pairs (ui,vi) and (vi,ui) in the list of edges. It is also guaranteed that the given graph is connected (there is a path between any pair of vertex in the given graph).

Output
If it is impossible to direct edges of the given graph in such a way that the obtained directed graph does not contain paths of length at least two, print "NO" in the first line.

Otherwise print "YES" in the first line, and then print any suitable orientation of edges: a binary string (the string consisting only of '0' and '1') of length m. The i-th element of this string should be '0' if the i-th edge of the graph should be directed from ui to vi, and '1' otherwise. Edges are numbered in the order they are given in the input.

Example
inputCopy
6 5
1 5
2 1
1 4
3 1
6 1
outputCopy
YES
10100
Note
The picture corresponding to the first example:

And one of possible answers:
*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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


		solve();
	

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


void solve()

{

	ll n, m;
	cin >> n >> m;
	vll v[n + 1];
	vll e;
	vll g(n + 1, -1);
	foi (m)
	{
		ll a, b ;
		cin >> a >> b;
		e.pb(a);
		v[a].pb(b);
		v[b].pb(a);
	}
	queue<ll> q;
	q.push(1);
	g[1] = 1;
	while (!q.empty())
	{	ll p, t;
		p = q.front();
		q.pop();
		if (g[p] == 1)
			t = 0;
		else
			t = 1;

		foi(v[p].size())
		{
			if (g[v[p][i]] == -1)
			{
				g[v[p][i]] = t;
				q.push(v[p][i]);
			}
			else if (g[v[p][i]] != t)
			{
				cout << "NO";
				return;
			}

		}
	}
	cout << "YES" << endl;
	for (ll i = 0; i < m; i++)
	{
		cout << g[e[i]];
	}
}



 

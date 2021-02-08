/*
Homer has two friends Alice and Bob. Both of them are string fans.

One day, Alice and Bob decide to play a game on a string s=s1s2…sn of length n consisting of lowercase English letters. They move in turns alternatively and Alice makes the first move.

In a move, a player must choose an index i (1≤i≤n) that has not been chosen before, and change si to any other lowercase English letter c that c≠si.

When all indices have been chosen, the game ends.

The goal of Alice is to make the final string lexicographically as small as possible, while the goal of Bob is to make the final string lexicographically as large as possible. Both of them are game experts, so they always play games optimally. Homer is not a game expert, so he wonders what the final string will be.

A string a is lexicographically smaller than a string b if and only if one of the following holds:

a is a prefix of b, but a≠b;
in the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
Input
Each test contains multiple test cases. The first line contains t (1≤t≤1000)  — the number of test cases. Description of the test cases follows.

The only line of each test case contains a single string s (1≤|s|≤50) consisting of lowercase English letters.

Output
For each test case, print the final string in a single line.

Example
input
3
a
bbbb
az
output
b
azaz
by
Note
In the first test case: Alice makes the first move and must change the only letter to a different one, so she changes it to 'b'.

In the second test case: Alice changes the first letter to 'a', then Bob changes the second letter to 'z', Alice changes the third letter to 'a' and then Bob changes the fourth letter to 'z'.

In the third test case: Alice changes the first letter to 'b', and then Bob changes the second letter to 'y'.
TAG:  games    greedy    strings

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
typedef pair<int, pii>      piii;
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

	int t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()

{
	string s;
	cin >> s;

	forrrr(i, 0, s.size(), 2) {
		if (s[i] != 'a')
			s[i] = 'a';
		else
			s[i] = 'b';
	}
	forrrr(i, 1, s.size(), 2) {
		if (s[i] != 'z')
			s[i] = 'z';
		else
			s[i] = 'y';
	}
	cout << s;


}

 

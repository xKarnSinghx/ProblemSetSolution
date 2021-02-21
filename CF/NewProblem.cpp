/*
B. New Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Coming up with a new problem isn't as easy as many people think. Sometimes it is hard enough to name it. We'll consider a title original if it doesn't occur as a substring in any titles of recent Codeforces problems.

You've got the titles of n last problems — the strings, consisting of lowercase English letters. Your task is to find the shortest original title for the new problem. If there are multiple such titles, choose the lexicographically minimum one. Note, that title of the problem can't be an empty string.

A substring s[l... r] (1 ≤ l ≤ r ≤ |s|) of string s = s1s2... s|s| (where |s| is the length of string s) is string slsl + 1... sr.

String x = x1x2... xp is lexicographically smaller than string y = y1y2... yq, if either p < q and x1 = y1, x2 = y2, ... , xp = yp, or there exists such number r (r < p, r < q), that x1 = y1, x2 = y2, ... , xr = yr and xr + 1 < yr + 1. The string characters are compared by their ASCII codes.

Input
The first line contains integer n (1 ≤ n ≤ 30) — the number of titles you've got to consider. Then follow n problem titles, one per line. Each title only consists of lowercase English letters (specifically, it doesn't contain any spaces) and has the length from 1 to 20, inclusive.

Output
Print a string, consisting of lowercase English letters — the lexicographically minimum shortest original title.

Examples
inputCopy
5
threehorses
goodsubstrings
secret
primematrix
beautifulyear
outputCopy
j
inputCopy
4
aa
bdefghijklmn
opqrstuvwxyz
c
outputCopy
ab
Note
In the first sample the first 9 letters of the English alphabet (a, b, c, d, e, f, g, h, i) occur in the problem titles, so the answer is letter j.

In the second sample the titles contain 26 English letters, so the shortest original title cannot have length 1. Title aa occurs as a substring in the first title.

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


		solve();
		

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()

{


	ll n;
	cin >> n;
	string s;
	for (ll i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		s += x;
		s += '?';
	}
	string ans;
	for (ll i = 1; i > 0; i++)
	{
		string temp;
		for (ll j = 0; j < i; j++)
		{
			temp += 'a';
		}
		ll pointer = temp.length() - 1;
		while (pointer >= 0)
		{
			if (s.find(temp) == string::npos)
			{
				ans = temp;
				break;
			}
			if (temp[pointer] != 'z')
				++temp[pointer];
			else
			{
				temp[pointer] = 'a';
				if (pointer - 1 >= 0 && temp[pointer - 1] != 'z')
				{
					++temp[pointer - 1];
				}
				else
					break;
			}

		}
		if (ans.length() != 0)
			break;
	}
	cout << ans ;


}



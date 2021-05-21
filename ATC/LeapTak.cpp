/*
D - Leaping Tak  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
400
 points

Problem Statement
There are 
N
 cells arranged in a row, numbered 
1
,
2
,
…
,
N
 from left to right.

Tak lives in these cells and is currently on Cell 
1
. He is trying to reach Cell 
N
 by using the procedure described below.

You are given an integer 
K
 that is less than or equal to 
10
, and 
K
 non-intersecting segments 
[
L
1
,
R
1
]
,
[
L
2
,
R
2
]
,
…
,
[
L
K
,
R
K
]
. Let 
S
 be the union of these 
K
 segments. Here, the segment 
[
l
,
r
]
 denotes the set consisting of all integers 
i
 that satisfy 
l
≤
i
≤
r
.

When you are on Cell 
i
, pick an integer 
d
 from 
S
 and move to Cell 
i
+
d
. You cannot move out of the cells.
To help Tak, find the number of ways to go to Cell 
N
, modulo 
998244353
.

Constraints
2
≤
N
≤
2
×
10
5
1
≤
K
≤
min
(
N
,
10
)
1
≤
L
i
≤
R
i
≤
N
[
L
i
,
R
i
]
 and 
[
L
j
,
R
j
]
 do not intersect (
i
≠
j
)
All values in input are integers.

*/

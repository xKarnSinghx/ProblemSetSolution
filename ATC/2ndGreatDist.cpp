/*
A - 2nd Greatest Distance  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
400
 points

Problem Statement
There are 
N
 houses numbered 
1
 through 
N
 on a two-dimensional plane. House 
i
 is at 
(
x
i
,
y
i
)
.

We use Chebyshev distance to calculate the distance between two houses. That is, the distance between Houses 
i
 and 
j
 is 
max
(
|
x
i
−
x
j
|
,
|
y
i
−
y
j
|
)
.

There are 
N
(
N
−
1
)
2
 pairs formed by two different houses. For each of these pairs, we will calculate the distance between the houses, and then we will sort these distances in descending order to get a sequence of length 
N
(
N
−
1
)
2
. Find the second value from the beginning of this sequence.

Constraints
All values in input are integers.
3
≤
N
≤
2
×
10
5
−
10
9
≤
x
i
,
y
i
≤
10
9
*/

/*
C - H and V  / 
Time Limit: 1 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
We have a grid of 
H
 rows and 
W
 columns of squares. The color of the square at the 
i
-th row from the top and the 
j
-th column from the left 
(
1
≤
i
≤
H
,
1
≤
j
≤
W
)
 is given to you as a character 
c
i
,
j
: the square is white if 
c
i
,
j
 is ., and black if 
c
i
,
j
 is #.

Consider doing the following operation:

Choose some number of rows (possibly zero), and some number of columns (possibly zero). Then, paint red all squares in the chosen rows and all squares in the chosen columns.
You are given a positive integer 
K
. How many choices of rows and columns result in exactly 
K
 black squares remaining after the operation? Here, we consider two choices different when there is a row or column chosen in only one of those choices.

Constraints
1
≤
H
,
W
≤
6
1
≤
K
≤
H
W
c
i
,
j
 is . or #.

*/

# DNA Alignment

## Description
This project is to solve a fundamental problem in computational biology and to learn about a powerful programming paradigm known as dynamic programming.

### Example
One of my test case is:
- string 1: at
- string 2: cag
and the result will be:
Edit distance = 3, because:
|-|c|2|
|a|a|0|
|t|g|1|
I run this test with my program and it is correct.

### Features
My project consists of 2 part, the first one is filling the matrix (I used 2D vector for this, I think vector for this case is just easier to manage the memory than using arrays). I fill out the matrix using the logic matrix[r][c] = min {matrix[r+1][c+1] + penalty, matrix[r+1][c] + 2, matrix[r][c+1] + 2}. I then implement the traceback function, which is also based on the logic above, using if-else statements.

### Testing
I wrote 4 tests to test my program because I have 4 public methods for my EDistance class, including checking if the function min3 returns the smallest number between 3 numbers, the function penalty returns the correct penalty if 2 characters are identical/different, etc.

### Issues
One of the biggest issue I have is missing the end line of the string produced by the alignment function. I figured out that this is due to the way I set the condition to check the index, so I adjusted a little my code to cover the edge cases, for example if there is only 7 rows then the code shouldn't go to the condition when it checks the 8th row as this will cause segmentation fault.


### Runtime Report
| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |


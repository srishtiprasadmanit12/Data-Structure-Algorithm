# RECURSION

## What is recursion
Recursion is a programming technique where a function calls itself repeatedly until it reaches a base case that stops.

## Explain recursion using stack based and function calls

**DRAW STCK & EXPLAIN**

Let's understand what happens behind the scene of when
 function calls itself , so it adds a new frame to the call stack whenever a function is called and it  remains in stack until processed it follows LIFO principle(last in first out).
That is when function reaches a base case, at which point it returns and the frame is removed from the call stack.


## Why to use recursion
Recursion is useful when the problem can be broken down into smaller sub-problems of the same type.

## How to use recursion
1. Define a function that calls itself.
2. Define a base case that stops the recursion.
3. Use the recursive function to solve the problem.

## Pseudo code to explain recursion
Q.Let's take problem : to print number from 1 to 5

break to sub-problem - n=1 , 1+1 = 2, 2+1=3, 3+1=4, 4+1=5 
pattern is adding 1 every time

draw call stack & explain 
```cpp
#include <bits/stdc++.h>
using namespace std;
void fun(int cnt){
    if(cnt==5){
        cout<<cnt<<endl;
        return;
    }
    cout << "Going down with cnt = " << cnt << endl; // Action before the recursive call
    //this prints ---> 1,2,3,4,5
    fun(cnt+1);
    cout << "Returning back up with cnt = " << cnt <<endl;//Action after the recursive call
    // while returning this prints -> 5,4,3,2,1 this is backtracking
}

int main()
{
    fun(1);
    return 0;
}
```

### Recursive Execution and Call Stack Growth
The function keeps calling itself recursively, adding new calls to the stack until it hits the base case (cnt == 5):

- First Call (fun(1)):

- cnt is 1 (not 5), so it prints 1.
Calls fun(2) and pushes this call onto the stack.
Second Call (fun(2)):

- cnt is 2 (not 5), so it prints 2.
Calls fun(3) and pushes this call onto the stack.
Third Call (fun(3)):

- cnt is 3 (not 5), so it prints 3.
Calls fun(4) and pushes this call onto the stack.
Fourth Call (fun(4)):

- cnt is 4 (not 5), so it prints 4.
Calls fun(5) and pushes this call onto the stack.
Fifth Call (fun(5)):

- cnt is 5, matching the base case.
Prints 5 and returns without any further calls.
At this point, all calls have reached the base case, and fun(5) starts to return. Each call will now unwind back up the stack.

### Returning Back Through the Call Stack
When each function call returns, it goes back to the previous call in the stack. In this specific example, there is no additional code to execute after the recursive call, so each return simply moves control back up the stack.

Returning from fun(5): Control goes back to fun(4), which finishes and is removed from the stack.
Returning from fun(4): Control goes back to fun(3), which finishes and is removed from the stack.
Returning from fun(3): Control goes back to fun(2), which finishes and is removed from the stack.
Returning from fun(2): Control goes back to fun(1), which finishes and is removed from the stack.

### incase of backtracking 
Now, each function call starts returning up the stack, executing the backtracking part of the code.

- Returning from fun(5): fun(4) resumes and prints "Returning back up with cnt = 4".
- Returning from fun(4): fun(3) resumes and prints "Returning back up with cnt = 3".
- Returning from fun(3): fun(2) resumes and prints "Returning back up with cnt = 2".
- Returning from fun(2): fun(1) resumes and prints "Returning back up with cnt = 1".

**Explaination**
**Going Down**: When fun(cnt) is called, it prints "Going down with cnt = X" before making the recursive call. This simulates the downward journey in the recursive process.
**Base Case**: When cnt reaches 5, it prints a message indicating that it has hit the base case, and the function returns without further recursion.
**Backtracking**: After each recursive call returns, the code executes the statement "Returning back up with cnt = X", which simulates the backtracking step as it moves back up the stack.


## Question

[fibonacci number](https://leetcode.com/problems/fibonacci-number/)
In order to understand wheather a problem can be solved by recursion or not , if we are able to break problem down into smaller problem we would get a start.

fib(n) = fib(n-1)+fib(n-2)
when u write recursion in a formula this is called recurrence relation & base condition is answer we have already.

If we want to find 5th fibonacci number 
                      5
                /          \
                4          3
                / \       / \
                3   2     2  1
                / \ / \  / \
                2   1 1  0 0

### how to approach a recursive problem 
1.  **Break down the problem**: Break down the problem into smaller sub-problems.
2. **Formulate the recurrence relation**: Formulate the recurrence relation based on the sub-pro
3.  **Identify the base case**: Identify the base case or the smallest sub-problem

4. **Draw recursive tree**
    - see the flow of function & how they are getting in stack.
    - Identify & focus on left tree calls and right tree calls (first left tree is resolved then right)
    - Draw tree using pen and paper
5. See how values are returned at each step and see where function call will come out of 


### Working with variables in recursion
Variables can be in arguments, body of function or return type

### Binary search with recursion

[Binary search](https://leetcode.com/problems/binary-search/description/)

How will u approach this problem: 
- search space is getting divided by half
- we are looking for a number in this space
- varibales : left, right pointer
- if u want to pass any varible to its next sub-problem,put it in argument
- varible if want it in that particular function call keep it in body
- make sure to return it when there is a return type of function

```
class Solution {
public:
    int binarySearch(int l,int r,int target,vector<int>&nums){
        if(l>r){
            return -1;
        }
        /*Mid varible is in body & not in recursive function, becoz current mid is not of any vlaue for next recursive function*/
        int mid = l + (r-l)/2; 

        if(target==nums[mid]){
            return mid;
        }
        else if(target>nums[mid]){
            //right search space
           return binarySearch(mid+1,r,target,nums);
        }
        //left search space
       return binarySearch(l,mid-1,target,nums);
    }
    int search(vector<int>& nums, int target) {
    
        return binarySearch(0,nums.size()-1,target,nums);
                
    }
};
```

## factorial of a number 
```

#include <bits/stdc++.h>

int factorial(int n){
    //base
    if(n==0){
        return 1;
    }
    //recursive function
    int res  = n * factorial(n-1);
    return res;
}

int main()
{
    int n = 5;
    std::cout<<factorial(5);
    return 0;
        
}
```

### Add digits
[Add digits Leetcode](https://leetcode.com/problems/add-digits/description/)

```
    int addDigits(int num) {
        int sum=0;
        while(num){
            sum+=(num%10);
            num/=10;
        }
        if(sum<10){
            return sum;
        }
        else{
            return addDigits(sum);
        }        
    }
```

### Reverse an integer

[Reverse an integer Leetcode](https://leetcode.com/problems/reverse-integer/description/)

`This is gem question --> includes concept of recursion,handling overflow,signed & unsigned`

```
class Solution {
public:
int sum=0;
    bool recur(int n){
        if(n==0)
            return true;
        int rem = n%10;
        if ((sum > INT_MAX / 10) || (sum < INT_MIN / 10)) {
            return false;  // Return false to indicate overflow
        }
        sum=sum*10+rem;
       return recur(n/10);
    }
    int reverse(int x) {
      int sign = (x<0)?-1:1;
      bool ans = recur(abs(x));
      return ans ? sign * sum : 0;
    }
};
```

### Check if palindrome or not using recursion
steps:
draw tree and find recurrence relation
find base case
find the variables in recursion

```
#include <bits/stdc++.h>

using namespace std;
bool palindrome(string s,int i,int j){
    if(i>j){
        return true;
    }
    if(s[i]!=s[j]){
        return false;
    }
    return palindrome(s,i+1,j-1);
    
}

int main()
{
    string str = "abcclba";
    int n= str.size();
    cout<<palindrome(str,0,n-1);
    return 0;
}
```

### Count number of zeros in given number
```
int countZeros(int num){
    //base
    if(num==0){
        return 1;
    }
    //extract last digit
    if(num<10){
        return (num==0)?1:0;
    }
    
    //recursive case
    int rem=num%10;
    int cnt=0;
    if(rem==0)
        cnt++;
    
    return cnt+countZeros(num/10);
}

int main()
{
    int num = 120404032;
    cout<<countZeros(num);
    return 0;
}
```

### Check for sorted array in ascending order
steps:
- Firstly find sub-problem by breaking it down
- Draw recursion tree
- identify base case

```
    [1,2,3,4]

__Recursion tree__:
    (arr,0)
        |
    (1<2) && (arr,1)
        |
    (2<3) && (arr,2)
        |
    (3<4) && (arr,3)
```


```
#include <bits/stdc++.h>
using namespace std;

bool checkForSorted(int arr[],int idx,int len){
    if(idx==len-1){
        return true;
    }
    if(arr[idx]>arr[idx+1]){
        return false;
    }
    return (arr[idx]<arr[idx+1]) && checkForSorted(arr,idx+1,len);
    
}
int main()
{
    
    int arr[]={1,2,3,8,5,6,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<checkForSorted(arr,0,len);
    return 0;
}
```
### Linear search in array using recursion

```

```
[1,2,8,5] target - 8
__Recursion tree__:

(arr,0)
    |
  (1=8) || (arr,1)
    |
   (2=8) || (arr,2)
    |
   (8=8) || (arr,3)

from here return true


```
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[],int len,int target,int idx){
    //base case
    if(idx==len-1){
        return false;
    }
    
    if(arr[idx]==target){
        return true;
    }
    //recursive case
    return (arr[idx]==target)||linearSearch(arr,len,target,idx+1);
    
    
}
int main()
{
    
    int arr[]={1,2,3,8,5,6,7};
    int target = 8;
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<linearSearch(arr,len,target,0);
    return 0;
}
```

### Return list of all indices of that matches target value

Here the return type will be array/vector

```
#include <bits/stdc++.h>
using namespace std;

vector<int>linearSearch(int arr[],int len,int target,int idx,vector<int>&ans){
    //base case
    if(idx==len){
        return ans;
    }
    
    if(arr[idx]==target){
        // return true;
        ans.push_back(idx);
    }
    //recursive case
    return linearSearch(arr,len,target,idx+1,ans);
    
}
int main()
{
    
    int arr[]={1,2,3,8,5,6,8};
    int target = 8;
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"len: "<<len<<endl;
    vector<int>ans;
    vector<int>ans = linearSearch(arr,len,target,0,ans);
    for(auto x:list){
        cout<<x<<" ";
    }
    
    return 0;
}
```

## Recursion on subset,string,subsequence

### Skip a character
s1 = "baccad" -->  s2 = "bccd"  (remove all a's from given string and return new string)

Two ways:
1. pass string to function argument (can be passed to future calls)
2. create ans variable in function body (every recursive call creats new ans)

The recursive tree for both approach is diffrent

```
#include <bits/stdc++.h>
using namespace std;

//Way:1
string solve1(string str,int idx,string ans){
    //base case
    if(ans.size()==str.size()){
        return ans;
    }
    
    
    if(str[idx]=='a'){
        return solve1(str,idx+1,ans);
    }
        return solve1(str,idx+1,ans+str[idx]);

}

//Way:2
string solve2(string str,int idx){
    //Base case
        if(idx==str.size()){
        return "";
    }
    
    char ch = str[idx];
    
    if(str[idx]!='a'){
        return ch+solve2(str,idx+1);
    }
    return solve2(str,idx+1);
}

int main()
{
    string str = "baccad";
    cout<<"solve1:passing ans in function argument : "<<solve1(str,0,"")<<endl;
    cout<<"solve2:keeping ans string in body itself : "<<solve2(str,0);
    return 0;
}
```

## Subset Problem
str = "abc"
ans = ["a","b","c","ab","bc", "ac","abc"] 

This is a pattern of taking some elements & removing some is known as subset pattern

For every character we have 2 choices - **take it or ignore it.**

```
    ""/abc
     /      \
    a/bc    ""/bc
    /   \    /   \
ab/c    a/c   b/c  ""/c
/  \    /  \   / \   / \
abc ab  ac  c  bc c  c  "" ==> these are all subset, we got this as a result other string becomes empty

hence the base condition is if initial string becomes empty then other string will give output


```
**Subset & subsequence are same, subset is for arrays and subsequences is for string**

### Subsequence
```
#include <bits/stdc++.h>

using namespace std;

void subseq(string s1,string s2){
    if(s1.empty()){
        cout<<s2<<" ";
        return;
    }
    
    //include
    subseq(s1.substr(1),s2+s1[0]);
    //exclude
    subseq(s1.substr(1),s2);

}
int main()
{
    string s1 = "abc";
    subseq(s1,"");
    return 0;
}
```

**Another approach by storing output in vector**

```
#include <bits/stdc++.h>

using namespace std;

vector<string>subseq(string s1,string s2){
    if(s1.empty()){
        return {s2};//return a vector containing the current subsequence
    }
    
    //include
    vector<string>include = subseq(s1.substr(1),s2+s1[0]);
    //exclude
    vector<string>exclude = subseq(s1.substr(1),s2);
    
    //this block will execute after all recursive call is completed
    vector<string>res;
    for(auto s:include){
        res.push_back(s);
    }
    
    for(auto s:exclude){
        res.push_back(s);
    }
    
    return res;

}
int main()
{
    string s1 = "abc";
    vector<string>ans = subseq(s1,"");
    
    for(auto s:ans){
        cout<<s<<" ";
    }
    return 0;
}
```

### Maze Problem

#### Counting path i.e. no. of ways to reach destination

[Unique path: Leetcode](https://leetcode.com/problems/unique-paths/)

```cpp
            ("",3,3)
        /d                 \r
    (D,2,3)             (R,3,2)
    /d     \r           /d     \r
(DD,1,3)  (DR,2,2)   (RD,2,2)   (RR,3,1)
(ret 1)     d/  r\                 (ret 1)
        (DRD,1,2) (DRR,2,1)

if either of row or col is 1 than return 1 as it is valid path
```

**So there are 3 types of problem here:**
1. count all paths (countWays)
2. print all paths (printPaths)
3. store all paths in vector or array (printArrayPath)

```cpp

#include <bits/stdc++.h>
using namespace std;


int countWays(int r,int c){
    if(r==1 ||c==1){
        return 1;
    }
    
    int left  = countWays(r,c-1);
    int up =  countWays(r-1,c);
    
    return left+up;
}
void printPaths(int r,int c,string ans){
    if(r==1||c==1){
        cout<<ans<<" ";
        return;
    }
    if(c>1)
        printPaths(r,c-1,ans+"R");
    if(r>1)
        printPaths(r-1,c,ans+"D");
    
    
}

vector<string>printArrayPath(int r, int c){
    if(r==1 || c==1){
        return {""};
    }
    
    vector<string>paths; //local variable (vector)
    
    if(c>1){
        vector<string>rightPath = printArrayPath(r,c-1);
        for(auto path:rightPath){
            paths.push_back("R"+path);
        }
    }
    
    if(r>1){
        vector<string>downPath = printArrayPath(r-1,c);
        for(auto path:downPath){
            paths.push_back("D"+path);
        }
    }
    
    return paths;
    
}

int main()
{
    
    int r,c;
    r=3,c=3;
    cout<<"unique paths: "<<countWays(r,c)<<endl;
    printPaths(r,c,"");
    vector<string>allPaths=printArrayPath(r,c);
    for(string path:allPaths){
        cout<<path<<" ";
    }

    return 0;
}
```

### Maze with obstacle

```cpp
#include <iostream>
using namespace std;

void pathRestriction(string ans, int maze[3][3], int r, int c, int rows, int cols) {
    // Base case: if we reach the bottom-right cell
    if (r == rows - 1 && c == cols - 1) {
        cout << ans << " ";
        return;
    }

    // If current cell is restricted (0), return immediately
    if (maze[r][c] == 0) {
        return;
    }

    // Move Down if within bounds
    if (r < rows - 1) {
        pathRestriction(ans + "D", maze, r + 1, c, rows, cols);
    }

    // Move Right if within bounds
    if (c < cols - 1) {
        pathRestriction(ans + "R", maze, r, c + 1, rows, cols);
    }
}

int main() {
    int maze[3][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    int rows = 3, cols = 3;
    
    pathRestriction("", maze, 0, 0, rows, cols);
    
    return 0;
}

```






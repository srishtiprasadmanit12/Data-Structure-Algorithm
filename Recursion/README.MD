# RECURSION

## What is recursion
Recursion is a programming technique where a function calls itself repeatedly until it reaches a base case that stops.

## Explain recursion using stack based and function calls
The function calls itself by adding a new frame to the call stack, which contains the function's parameters.
The function then executes until it reaches a base case, at which point it returns and the frame is
removed from the call stack.


## Why to use recursion
Recursion is useful when the problem can be broken down into smaller sub-problems of the same type.

## How to use recursion
1. Define a function that calls itself.
2. Define a base case that stops the recursion.
3. Use the recursive function to solve the problem.

## pseudo code to explain recursion

```
#include <bits/stdc++.h>

void fun(int cnt){
    if(cnt==5){
        std::cout<<cnt<<std::endl;
        return;
    }
    std::cout << "Going down with cnt = " << cnt << std::endl; // Action before the recursive call
    //this prints -> 1,2,3,4,5
    fun(cnt+1);
    std::cout << "Returning back up with cnt = " << cnt << std::endl;//Action after the recursive call
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

### find if a given number is prime or not 
O(N)
```
int main(){
    int n;
    cin>>n;
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<"Not Prime"<<endl;
            break;
        }
    }
    cout<<"Prime"<<endl;

}

```
### Same we can find in O(sqrt(N)) as will check only till sqrt(N) to justofy a given number is prime or not

```
int main(){
    int n;
    cin>>n;
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            cout<<"Not Prime"<<endl;
            break;
        }
    }
    cout<<"Prime"<<endl;

}
```

###  find all prime factor of a number by brute force approach O(sqrt(N))

n=36
----- 
1X36
2x18
3x12
4x9
6x6
------after this its getting repeated
9x4
12x3
18x2
36x1

```
int main(){
    int n;
    cin>>n;
    vector<int>prime_factor;
    // looping only sqrt(n)
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            prime_factor.push_back(i);
            n=n/i;
        }
    }
    //this is when we are left with prime number at last: case n=24 --> 2*2*2*3
    if(n>1){
        prime_factor.push_back(n);
    }
    for(int x:prime_factor){
        cout<<x<<" "<<endl;
    }

}
```


# Sieve algorithm
All numbers that are multiple of prime number will not be prime number ,so once we encounter a prime number we'll filter-out all the multiples of it.
So, the numbers remaining will be prime numbers.

[youtube link](https://youtu.be/T8PaMnb0GPo?si=wSZFgFozKtypifjv)

step 1: assume all numbers till N are prime initially 
step 2: loop over N and check if any number is prime then mark all the multiple of it as non-prime
step 3: print all the numbers that are not marked as non-prime

if q=10^7 and n=10^7 then this question would have been solved only by sieve approach 
```
int main(){
    int n;
    cin>>n;
    vector<bool>isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<n;i++){
        if(isPrime[i]==true){
            for(int j=2*i;j<n;j+=i){
                isPrime[j]=false;
            }
    }
}
//if we have been given q queries 

int q;
cin>>q;
while(q--){
    int num;
    cin>>num;
    if(isPrime[num]){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"not prime"<<endl;
    }
}

}
```
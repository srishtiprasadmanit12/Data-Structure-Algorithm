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
// If we have been given q queries 

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

## Variation of sieve algorithm 
Example : highest prime, lowest prime, prime factorization, divisors
### 1.  Highest prime, Lowest prime
```
int main(){
    int n;cin>>n;
    vector<bool>isPrime(n,true);
    vector<int>hp(n,0);
    vector<int>lp(n,0);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<n;i++){
        if(isPrime[i]==true){ // if i th number is prime means all the mulitples of it is not prime
        lp[i]=hp[i]=i;
            for(int j=2*i;j<n;j+=i){
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==0){
                    lp[j]=i;
                }
            }
        }
    }

}
```

### 2. stores all prime factors in a array 

```
int n;cin>>n; // find all prime factor of n 
vector<int>primeFactor;

while(n>1){

    int pf = hp[n]; // later we'll divide by highest primefactor 
    while(n%pf == 0){
        n = n/pf;
        primeFactor.push_back(pf);
    }

}

for(int i=0;i<primeFactor.size();i++){
    cout<<primeFactor[i]<<endl;
}

```
### 3. stores all prime factors in a map (create frequency map of prime factor)


````
int n;cin>>n;
map<int,int>mp;
while(n>1){
    int pf = hp[n]; // later we'll divide by highest primefactor
    while(n%pf==0){
        n=n/pf;
        mp[pf]++; // increment the frequency of prime factor
    }
}

for(auto x:mp){
    cout<<x.first << "" << endl;
}
````
### 4. find divisors

```
const n= 1e5;
vector<int>divisor[n];
for(int i=2;i<n;i++>){
    for(int j = i;j<n;j+=i>){ // iterating on multiple of i 
        
        divisor[j].push_back(i); // j is a multiple of i

    }
}
```

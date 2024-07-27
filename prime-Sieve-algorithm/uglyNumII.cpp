class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        st.insert(1); // Start with the first ugly number, which is 1
        long num = 1;
        for (int i = 0; i < n; i++) {
            num = *st.begin(); // Get the smallest number in the set
            st.erase(num); // Remove this number from the set
            st.insert(num * 2); // Insert the next potential ugly number (num * 2)
            st.insert(num * 3); // Insert the next potential ugly number (num * 3)
            st.insert(num * 5); // Insert the next potential ugly number (num * 5)
        }
        return num; // After n iterations, num will be the nth ugly number
    }
};

/*
Let’s walk through the first few iterations for n = 10:

Initialization:

st = {1}
num = 1
i = 0
First Iteration:

num = 1 (smallest in st)
st.erase(1)
st.insert(1 * 2) = st.insert(2)
st.insert(1 * 3) = st.insert(3)
st.insert(1 * 5) = st.insert(5)
st = {2, 3, 5}
Second Iteration:

num = 2 (smallest in st)
st.erase(2)
st.insert(2 * 2) = st.insert(4)
st.insert(2 * 3) = st.insert(6)
st.insert(2 * 5) = st.insert(10)
st = {3, 4, 5, 6, 10}
Third Iteration:

num = 3 (smallest in st)
st.erase(3)
st.insert(3 * 2) = st.insert(6) (6 is already in the set)
st.insert(3 * 3) = st.insert(9)
st.insert(3 * 5) = st.insert(15)
st = {4, 5, 6, 9, 10, 15}
... and so on until the 10th iteration.

After 10 iterations, the value of num will be the 10th ugly number, which is 12.
*/
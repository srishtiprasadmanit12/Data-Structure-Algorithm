/*
Simple array or math related question

std::vector::insert() function to insert the element at the given index. 
All the elements to the right of the given index will be shifted once place to the right to
make space for new element.

vec.insert (pos, val);

#Parameters

position – It specifies the iterator which points to the position where the insertion is to be done.

val – It specifies the value to be inserted.

##Return Value

This function returns an iterator to the inserted element.


*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      for(int i=n-1;i>=0;i--){
        if(digits[i]==9){
            digits[i]=0;

        }else{
            digits[i]++;
            return digits;
        }
      }

      //If control comes at this point , means all digits are 9
      digits.insert(digits.begin(),1);
      return digits;  
    }
};
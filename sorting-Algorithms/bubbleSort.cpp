// Bubble Sort 
// Basic logic is to push larger element to the end of the array
// Logic
//1. Start from the first element of the array
//2. Compare the current element with the next element
//3. If the current element is greater than the next element, swap them
//4. Repeat steps 2 and 3 until the end of the array is reached

// this will check for all values even sorted one 
void bubbleSort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            swap(arr[j],arr[j+1]);
        }
    }
}

//this will not check sorted values, but will loop over all elements even if sorted
void bubbleSort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            swap(arr[j],arr[j+1]);
        }
}
}

//this approach will not check sorted values & will break out of loop once array is sorted by flag variable
void bubbleSort(int arr[],int n){
    int i,j;
    bool flag;
    for(i=0;i<n-1;i++){
        flag = false;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(flag == false)
            break;

}
}

int main(){

    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);
    //print arr array

}
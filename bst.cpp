#include<iostream>
using namespace std;

// Binary search implementation in c++.
// The program asks for a sorted array and a target element to search for.
// If the array is not sorted, the program exits.
// If the target element is found, its position is displayed.
// If the element is not found on the first try, the user gets a second chance to enter another target.

/* Example:

Enter the number of elements: 5
Enter a sorted array of elements: 
Position 1: 2
Position 2: 4
Position 3: 6
Position 4: 8
Position 5: 10
Enter the target element: 7
Element 7 not found. Please enter another target element. One try remaining.
6
Element 6 found at position: 3

*/


// Recursive function to perform the binary search.
int findMe(int arr[], int start, int end, int target){
    if(start>end){
        return -1;
    }
    int mid=start+(end-start)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        return findMe(arr, start, mid-1, target);
    }
    else{
        return findMe(arr, mid+1, end, target);
    }
}

// Main function does input and output operations.
int main(){
    int n=0, target, result;

    // Input number of elements (n).
    cout<<"Enter the number of elements: ";
    cin>>n;

    // Declare the array of size n.
    int arr[n];
    cout<<"Enter a sorted array of elements: "<<endl;

    // Input the elements of the array
    for(int i=0; i<n;i++){
        cout<<"Position "<< i+1 <<": ";
        cin>>arr[i];
    }

    // If the array is not sorted, exit the program.
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            cout<<"Error! Array is not sorted. Exiting program."<<endl;
            return 0;
        }
    }

    // Input the target element to search for.
    cout<<"Enter the target element: ";
    cin>>target;

    // Call the binary search function.
    result = findMe(arr,0, n-1, target);

    // If the element is not found, give the user another chance to enter a target.
    if(result==-1){
        cout<<"Element "<<target<<" not found. Please enter another target element. One try remaining!"<<endl;
        cin>>target;
        result = findMe(arr, 0, n-1, target);
        if(result==-1){
            cout<<"Element "<<target<<" not found. Exiting Program."<<endl;
            return 0;
        }
        else{
            cout<<"Element "<<target<<" found at position: "<< result+1 << endl;
        }
    }
    else{
        cout<<"Element "<<target<<" found at position: "<< result+1 << endl;
    }

    return 0;
}
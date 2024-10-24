//binary search in a sorted array by taking user input

#include<stdio.h>
#define SIZE 5
int arr[SIZE],loc=-1;
int binary_search(int key_val); // function declaration
int main(){
  int i,key;
  printf("Enter 5 array elements in ascending order\n");
  for(i=0;i<SIZE;i++){
    scanf("%d",&arr[i]); // taking array elements
  }
  printf("Enter which element you want : ");
  scanf("%d",&key); //taking key value
  loc = binary_search(key);
  if(loc==-1){
    printf("Value not found !"); //showing searching results
  }else{
    printf("Value Found at index %d",loc);  //showing searching results
  }
  return 0;
}

// Function for Binary Search
int binary_search(int key_val){
     int lb = 0 , ub = SIZE-1 , mid ; // lb = lower bound , ub = upper bound
     while(lb<=ub){
        mid = (lb+ub)/2;
        if(arr[mid]==key_val){
            return mid; //returning index value of key value
        }else if(key_val>arr[mid]){
            lb = mid+1;
        }else{
            ub = mid-1;
        }
     }
    return loc;  // returning old loc if searching failed
}
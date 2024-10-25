// linear search in a array by taking user input

#include <stdio.h>
#define SIZE 5
int arr[SIZE], loc = -1;
int linear_search(int key_val); // function declaration
int main()
{
  int i, key;
  printf("Enter 5 array elements\n");
  for (i = 0; i < SIZE; i++)
  {
    scanf("%d", &arr[i]); // taking array elements
  }
  printf("Enter which element you want to search : ");
  scanf("%d", &key); // taking key value
  loc = linear_search(key);
  if (loc == -1)
  {
    printf("Value not found !"); // showing searching results
  }
  else
  {
    printf("Value Found at index %d", loc); // showing searching results
  }
  return 0;
}

// Function for Linear Search
int linear_search(int key_val)
{
  int i;
  for (i = 0; i < SIZE; i++)
  {
    if (arr[i] == key_val)
    {
      loc = i;
      return loc; // returning key value index
    }
  }
  return loc; // returning old loc if searching failed
}
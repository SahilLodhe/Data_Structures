//#include<iostream>
//using namespace std;
//
//int length(char input[]){
//    if(input[0]=='\0'){
//        return 0;
//    }
//    return 1 + length(input+1);;
//}
//
//void removeConsecutiveDuplicates(char input[]){
//     if(input[0]=='\0'){
//        return;
//     }
//     if(input[0] != input[1]){
//        removeConsecutiveDuplicates(input + 1);
//     }else{
//        for(int i = 0;input[i]!='\0';i++){
//            input[i] = input[i+1];
//        }
//        removeConsecutiveDuplicates(input);
//     }
//}
//
//int main(){
//  char input[100];
//  cin>>input;
//  int l = length(input);
//  cout<<l<<endl;
//  cout<<input<<endl;
//
//  removeConsecutiveDuplicates(input);
//
//  cout<<length(input)<<endl;
//  cout<<input<<endl;
//  return 0;
//}
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int data[] = {123, 170, 164, 187, 150, 149, 172};
int n = sizeof(data) / sizeof(data[0]);
//time complexity => O(1)
//to swap two numbers.
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
//time complexity => O(N)
//to print the array.
void printArr(int arr[], int s) {
  int i;
  for (i = 0; i < s; i++)
    cout << arr[i] << " ";
  cout << endl;
}
//time complexity => O(N)
//to perform partition in the array.
int partition(int arr[], int low, int high) {

  int pivot = arr[high];
  cout<<pivot<<endl;

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
      printArr(data, n);
    }
  }
   swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
//time complexity => O(log N)
//to sort the array by quicksort algorithm.
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    printArr(data, n);
    quickSort(arr, low, pi - 1); // quicksorts left part of the array from pivot.
    printArr(data, n);
    quickSort(arr, pi + 1, high); // quicksorts right part of the array from pivot.
    printArr(data, n);
  }
}
int main()
{
  cout << "Heights of students in Unsorted manner: "<<endl;
  printArr(data, n);
  cout<<endl;
  quickSort(data, 0, n - 1);

  cout << "/nHeights of students in ascending order: \n";
  printArr(data, n);
    return 0;
}
#include<iostream>
using namespace std;

void swap(int *x, int *y){
   int temp = *x;
   *x = *y;
   *y = temp;
}

void v(int arr[]){
   arr[0] = 100;
}

int main(){
   int arr[4] = {1,3,4,5};
    
   swap(&arr[0], &arr[1]);

   v(arr);

   for(int i = 0; i < 4; i++){
      cout << arr[i] << " ";
   } 


    return 0;
}
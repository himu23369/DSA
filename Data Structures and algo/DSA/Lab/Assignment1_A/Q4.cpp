//Find saddle point in a 2 dimensional array
/*A saddle point in a numerical array is a number that is larger than or equal to every number in its column,and smaller than or equal to every number in its row.
(OR)
A saddle point is an element of the matrix such that it is the minimum element in its row and the maximum in its column. 
*/
#include <iostream>
using namespace std;

int main()
{
    //Asking array from the user
    int r = 0, c = 0;
    cout << "Enter the number of rows and columns for 2D-array" << endl;
    cin >> r >> c;
    int arr[r][c]; // Array created statically
    for (int i = 0; i < r; i++)
    {
        cout << "Enter the elements of the " << i + 1 << " row" << endl;
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    // int arr[3][3] = {1,2,6,
    //                  4,5,8,
    //                  6,8,0};

//Finding the minimum element in each row
  int Rmin[r],Cmax[c];
  for(int i = 0; i < r; i++){
    int min = arr[i][0];
     for(int j = 0; j < c; j++){
        if(arr[i][j] <= min){
            min = arr[i][j];
        }
     }
    Rmin[i] = min; 
  }

//Finding the maximum element in each column
  for(int i = 0; i < r; i++){
     int max = arr[0][i];
     for(int j = 0; j < c; j++){
       if(arr[j][i] >= max){
         max = arr[j][i];
       }  
     }
     Cmax[i] = max; 
  }

  int flag = 0;

//Checking for each element of array
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
       if(Rmin[i] == Cmax[j]){
         cout << "Saddle point is " << Rmin[i];
         flag = 1;
         break;
       } 
    }
  }

if(flag == 0){
    cout << "Saddle point not found" << endl;
} 

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // A 1D vector is a vector that stores elements in a single row or column.
    vector<int> v = {1, 2, 3, 4};

    //Some methods used for vectors
    v.push_back(3);  //Adds new element at the end
    v.pop_back();   //Removes element from the end
    v.size(); 

    // A 2D vector is a vector that stores elements in a two-dimensional grid or matrix
    vector<vector<int>> v1 = {
        {1, 2, 4},
        {3, 5, 6},
        {7, 8, 9}};

    /*
    For initialising a 2D matrix
    vector<vector<int>> v(rows, vector<int>(cols, init_value));
    */

    //For creating a 2D matrix with 3 rows and 4 columns initialised to 1
    vector<vector<int>> v2(3, vector<int>(4,1));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
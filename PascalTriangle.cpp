#include <iostream>
#include <vector>
using namespace std;

//Unsigned long long for the ability to generate very large pascal triangles
vector<vector<unsigned long long>> generatePascal(int length);
int main()
{
    /*USER INPUT*/
    int rows;
    cout << "How many pascal rows would you like? Enter: ";
    cin >> rows;

    /*Calls Pascal Function*/
    generatePascal(rows);
    return 0;
}
vector<vector<unsigned long long>> generatePascal(int length)
{
    vector<vector<unsigned long long>> pascal(length);

    for (int row = 0; row < length; row++)
    {

        for (int col = 0; col <= row; col++)
        {
            //If we're at either side of the column it automatically makes it a 1
            if (col == 0 || col == row)
            {
                pascal[row].push_back(1);
            }
            else
            {
                pascal[row].push_back(pascal[row - 1][col - 1] + pascal[row - 1][col]);
            }
        }

        //Prints out the elements of each row shortly after generating it
        for (int i = 0; i <= row; i++)
        {
            cout << pascal[row][i] << " ";
        }
        cout << endl;
    }
    return pascal;
}
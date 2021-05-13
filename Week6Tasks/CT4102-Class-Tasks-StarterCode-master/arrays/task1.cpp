#include <iostream>
using namespace std;



int main() 
{

    
    int index[5]; 
    int i, j;

   
    for (i = 0; i < 5; i++)
    {
        cout << "Please enter a value for index: " << i << endl;
        cin >> index[i];
    }

    cout << " You entered the following values: \n\n";
  
    for (j = 0; j < 5; j++)
    {
        
        cout << "ABassicArray[" << j << "] = " << index[j] << endl;
    }

    return 0;
}
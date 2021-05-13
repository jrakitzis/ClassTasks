#include <iostream>
using namespace std;




// Array board  

//int main()
//{
//    
//    int array[15];
//
//    cout << " element - value" << endl;
//
//    for (int x = 0; x < 15; x++)
//    {
//        array[x] = 15;
//
//        cout << x << " ----------- " << array[x] << endl;
//    }
//
//
//}







// Calculate sum 
 

//int main()
//{
//    int number[5]{ 20, 54, 76 ,343,563 };
//    int sum = 0;
//
//    for (int x = 0; x < 5; x++)
//    {
//        sum += number[x];
//
//        cout << sum << endl;
//
//    }
//}






// arrays with functions

//void printArray(int theArray[], int sizeOfArray);
//
//
//int main()
//{
//	int arrayOne[3] = { 20,34,664 };
//	int arraytwo[6] = { 30,34,22,67,343,657 };
//
//	printArray(arrayOne, 3);
//}
//
//
//void printArray(int theArray[], int sizeOfArray)
//{
//	for (int x = 0; x < sizeOfArray; x++)
//		cout << theArray[x] << endl;
//}


// multi dimensional arrays


//int main()
//{
//	int array[2][3] = { {2,3,4},{8,9,10} };
//
//	// row one = 2,3,4 
//	// row two = 8,9,10
//
//
//	cout << array[0][2];
//}


// print multi dimensional arrays

int main()
{
	int array[2][3] = { {2,5,7}, {3,8,1} };

	for(int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			cout << array[row][column] << " ";

		}
		cout << endl;
	}
}
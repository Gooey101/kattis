/*(NOT FINISHED)https://open.kattis.com/problems/granica*/

#include <iostream>
using namespace std;

bool compare(const long long arr[], int j, int numIntegers);

int main()
{
     int numIntegers;
     long long min;
     
     cin >> numIntegers;
     long long arr[numIntegers];
     
     cin >> arr[0];
     min = arr[0];
     for (int i = 1; i < numIntegers; i++)
     {
          cin >> arr[i];
          if (arr[i] < min)
          {
               min = arr[i];
          //min is the smallest of the values arr[0],..., arr[i]
          }
     }
     
     for (int j = 2; j <= min; j++) //possible values of numSpecial
     {
          if (compare(arr, j, numIntegers))
          {
               cout << j << " ";
          }
     }

     return 0;
}

bool compare(const long long arr[], int j, int numIntegers)
{
     int compareX, compareY, l = 1;
     for (int k = 0; k < numIntegers; k++)
     {
          compareX = arr[k] % j;
          while (l < numIntegers)
          {
               compareY = arr[l] % j;
               l++;
               break;
          }
          if (compareX != compareY)
          {
               return false;
          }
     }
     return true;
}

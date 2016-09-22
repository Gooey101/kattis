/*
Algorithm:
1. number is inputted into a specific array number, etc. a[14]
2. number and array position go to the sort function
3. the number is compared to all the other numbers in the array sratging from
the smallest numbers (a[1]) (a[0] will store the set number)
4. if the number is smaller than the next number in the array, then that's its
position in the array
5. when its position is found, calculate the # of numbers that need to go back
a space to make room for the new number
6. then move all the numbers that need to move 1 spot to the right in the array
7. do this for each new number that is inputted in the main function
*/

#include <iostream>
using namespace std;

int sort(int array[], int arrayPosition, int numberUsed);

int main()
{
     int array[21];
     int totalNumSets;
     int arrayPosition, num;
     cin >> totalNumSets;
     for (int index = 0; index < totalNumSets; index++)
     {
          cin >> array[0];
          int numberUsed = 0;
          int moveBack = 0;
          for (int i = 1; i <= 20; i++)
          {
               cin >> num;
               array[i] = num;
               numberUsed++;
               arrayPosition = i;
               moveBack = moveBack + sort(array, arrayPosition, numberUsed);
          }
          cout << array[0] << " " << moveBack << " " << endl;
     }
     return 0;
}

int sort(int array[], int arrayPosition, int numberUsed)
{
     int temporary[1];
     int moveBack = 0;
     if (numberUsed > 1)
     {
          for (int i = 1; i < numberUsed; i++)
          {
               if (array[arrayPosition] < array[i])
               {
                    temporary[0] = array[arrayPosition];
                    for (int j = numberUsed - 1; j > i - 1; j--)
                    {
                         array[j + 1] = array[j];
                         moveBack++;
                    }
                    array[i] = temporary[0];
               }
          }
     }
     return moveBack;
}

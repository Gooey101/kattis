/*https://open.kattis.com/problems/safepassage*/

#include <iostream>
#include <algorithm> //used for sort & min functions
using namespace std;

bool increment(int arr[], int totalPeople);

int main()
{
     int totalPeople, x;
     cin >> totalPeople;
     
     //filling & sorting array of times
     int arr[totalPeople];
     for (int i = 0; i < totalPeople; i++)
     {
          cin >> arr[i];
     }
     sort(&arr[0], &arr[totalPeople]);
     
     
     
     int totalTime = 0;
     
     if (increment(arr, totalPeople))
     {
          if (totalPeople - 2 > 0)
          {
               for (int j = 1; totalPeople - j > 1; j++)
               {
                    totalTime += max(arr[0], arr[totalPeople - j]); //fastest & slowest depart
                    totalTime += arr[0]; //fastest returns
               }
               
               totalTime += max(arr[0], arr[1]); //2 fastest depart
               cout << totalTime << endl;
          }
          else
          {
               totalTime += max(arr[0], arr[1]); //2 fastest depart
               cout << totalTime << endl;
          }
     }
     else
     {
          totalTime += max(arr[0], arr[1]); //2 fastest depart
          
          if (totalPeople - 2 > 0)
          {
               totalTime += arr[0]; //fastest returns
               totalTime += max(arr[totalPeople - 1], arr[totalPeople - 2]); //2 slowest depart
               totalTime += arr[1]; //2nd fastest returns
               
               for (int j = 3; totalPeople - j > 1; j++)
               {
                    totalTime += max(arr[0], arr[totalPeople - j]); //fastest & next slowest depart
                    totalTime += arr[0]; //fastest returns
               }
               
               totalTime += max(arr[0], arr[1]); //2 fastest depart
          }
          
          cout << totalTime << endl;
          return 0;
     }

}

bool increment(int arr[], int totalPeople)
{
     for (int i = 1; i < totalPeople - 1; i++)
     {
          if (arr[i] + 1 != arr[i + 1])
          {
               return false;
          }
     }
     return true;
}

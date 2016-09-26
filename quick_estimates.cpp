/*https://open.kattis.com/problems/quickestimate*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
     int totalDataSets;
     string num;
     cin >> totalDataSets;
     
     for (int i = 0; i < totalDataSets; i++)
     {
          cin >> num;
          cout << num.size() << endl;
     }
     
     return 0;
}

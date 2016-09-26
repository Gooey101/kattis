/*(NOT FINISHED)https://open.kattis.com/problems/robotopia*/

#include <iostream>
using namespace std;

int main()
{
     double leg1, leg2, arm1, arm2, legTotal, armTotal,
            determinant, x, y;
     int totalDataSets;
     cin >> totalDataSets;
     
     for (int i = 0; i < totalDataSets; i++)
     {
          cin >> leg1 >> arm1 >> leg2 >> arm2 >> legTotal >> armTotal;
          
          determinant = (leg1 * arm2) - (leg2 * arm1);
          if (determinant != 0)
          {
               x = ((legTotal * arm2) - (leg2 * armTotal)) / determinant;
               y = ((leg1 * armTotal) - (legTotal * arm1)) / determinant;
               if (((x / 1) == static_cast<int>(x)) && ((y / 1) == static_cast<int>(y)))
               {
                    if ((x <= 0) || (y <= 0))
                    {
                         cout << "?" << endl;
                    }
                    else
                    {
                         cout << x << " " << y << endl;
                    }
               }
               else
               {
                    cout << "?" << endl;
               }
          }
          else
          {
               
               
               cout << "?" << endl;
          }
     }
     
     return 0;
}

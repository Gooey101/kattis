/*https://open.kattis.com/problems/happyprime*/

#include <iostream>
#include <set>
using namespace std;

bool isPrime (int x);
bool isHappy (int x);

int main()
{
     int totalDataSets;
     cin >> totalDataSets;
     for (int i = 0; i < totalDataSets; i++)
     {
          unsigned a, b;
          cin >> a >> b;
          cout << a << " " << b << " ";
          if (isPrime(b) && isHappy(b))
          {
               cout << "YES" << endl;
          }
          else
          {
               cout << "NO" << endl;
          }
     }
     return 0;
}

bool isPrime (int x)
{
     if (x == 1)
          return false;
     for (int i = 2; i < x; i++)
     {
          if (x % i == 0)
          {
               return false;
          }
     }
     return true;
}

bool isHappy (int x)
{
     set <int> seen; // empty set of ints called "seen"
     do
     {
          seen.insert(x); // inserting value into set
          int digit, sum = 0;
          while (x > 0)
          {
               digit = x % 10;
               x = x / 10;
               sum += digit * digit;
          }
          x = sum;
          if (x == 1)
          {
               return true;
          }
     } while (seen.find(x) == seen.end());
     return false;
}

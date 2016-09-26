/*https://open.kattis.com/problems/rationalsequence*/

#include <iostream>
using namespace std;

int main()
{
     int totalDataSets;
     int setNum;
     long long p, q;
     char c;
     
     long long numOfNext, denomOfNext;
     
     long long numLeftRoot, denomLeftRoot;
     long long numRightRoot, denomRightRoot;
     
     long long numLeftChild, denomLeftChild;
     long long numRightChild, denomRightChild;
     
     cin >> totalDataSets;
     
     for (int index = 0; index < totalDataSets; index++)
     {
          int countLeft = 0, countRight = 0;
          cin >> setNum >> p >> c >> q;
          
          if (p == q) //if numerator == denominator
          {
               cout << setNum << " " << p << c << p + 1 << endl; // add 1 to the denominator
          }
          else if (p < q) //if numerator < denominator
          {
               //numerator and denominator of right child of right root
               numOfNext = q;
               denomOfNext = q - p;
               
               cout << setNum << " " << numOfNext << c << denomOfNext << endl;
          }
          else if (p > q) //if numerator > denominator
          {
               if (q == 1) //if denominator is 1
               {
                    cout << setNum << " " << q << c << p + q << endl; // switch and add 1 to the denominator
               }
               else
               {
                    //finding the root that is on the right of the current root
                    numLeftRoot = p - q;
                    denomLeftRoot = q;
                    countLeft++;
                    do
                    {
                         if (numLeftRoot > denomLeftRoot)
                         {
                              numLeftRoot = numLeftRoot - denomLeftRoot;
                              denomLeftRoot = denomLeftRoot;
                              countLeft++;
                         }
                         else if (numLeftRoot < denomLeftRoot)
                         {
                              numRightRoot = numLeftRoot;
                              denomRightRoot = denomLeftRoot - numLeftRoot;
                              countRight++;
                         }
                    } while (countRight != 1);
                    
                    //finding right child of the root
                    numRightChild = numRightRoot + denomRightRoot;
                    denomRightChild = denomRightRoot;
                    
                    //finding all the left children of the roots
                    numLeftChild = numRightChild;
                    denomLeftChild = numRightChild + denomRightChild;
                    countLeft--;
                    while (countLeft > 0)
                    {
                         numLeftChild = numLeftChild;
                         denomLeftChild = numLeftChild + denomLeftChild;
                         countLeft--;
                    }
                    
                    cout << setNum << " " << numLeftChild << c << denomLeftChild << endl;
               }
          }
     }
     return 0;
}

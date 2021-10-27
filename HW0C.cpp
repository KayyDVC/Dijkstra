#include <iostream>
using namespace std;
/*This function will be returning a value inside of an 'if-then' statement, int functions give
a warning that I want to avoid, so I'll be using a void function and returning the value needed via
pointer
*/
void recDijkstra(int firInp,int secInp,int &gcd);

int main (void)
{

  int first, second, gcd;

  cout<< "Please enter two numbers seperated by a space" << endl;
  cin>> first >> second;

  recDijkstra(first, second, gcd);

  cout<< "The greatest common factor of " << first << " and " << second << " is "<< gcd<< endl;

  return 0;
}

void recDijkstra (int firInp, int secInp, int &gcd)
{
  int iniFir=firInp;
  int iniSec=secInp;

  if (firInp<secInp)//Determines which number is bigger and which to subtract from the other
  {
    secInp = secInp-firInp;
  }
  else if (secInp<firInp)
  {
    firInp = firInp-secInp;
  }

/* Determines the which number gets returned based on last calculation
If the values are equal to each other such as with the eventual calculations of 18 and 81,
it returns one of the newly subtracted values otherwise it would return the wrong value.
If the either values after calculation is less than zero it returns the value of the respective negative variable
orginially plugged into the equation (iniFir/iniSec)
*/
  if (secInp<0 )
  {
    gcd= iniSec;
  }
  else if (firInp<0)
  {
    gcd= iniFir;
  }
  else if (firInp==secInp)
  {
    gcd= firInp;
  }
  else if (secInp>0 && firInp>0 )
  {
      recDijkstra(firInp,secInp, gcd);
  }

}

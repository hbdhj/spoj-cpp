/*
 * 2012/11/27
 */
#include  <iostream>

using namespace std; 

int main() 
{
  int current_number;
  cin >> current_number; // Read the first number

  while(current_number != 42) 
  {
    // Print out the number that we just checked is NOT 42
    cout << current_number << endl;
    cin >> current_number; // Read the next number
  }
}

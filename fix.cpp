#include <iostream>

using namespace std;

bool increasing(int a)
{
    if (a > 0)
    {
        //If recursive call fails, don't bother to check further.
        if (!increasing(a / 10))
            return false;
        
        //least significant digit
        int last = a % 10;
        
        //Second least significant digit, 0 if a < 10
        int prev = (a / 10) % 10;
        
        //make your changes only below this line.
        
        if (prev <= last) return true;
            return false;
        }
    // changed to true.
    // the function recursively widdles to 0 intentionally - from there it can scan from leading the int character to end
    return true;
}


int main (int argc, char* argv[])
{
    int x;
    cin >> x;
    cout << increasing(x) << endl;
    return 0;
}
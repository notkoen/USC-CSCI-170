#include <iostream>
#include <string>

using namespace std;

int collatz(int n, int count)
{
    if (n < 1)
    {
        cout << "invalid input. n must be >= 1" <<  endl;
        return -1;
    }
    
    //Check if input is 1
    if (n == 1)
        return count;
    
    //Collatz conjecture
    if(n%2 == 1)
    {
        n *= 3;
        n++;
    }
    else
    {
        n /= 2;
    }
    
    //Recursive call
    return collatz(n, ++count);
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    cout << collatz(n,0) << endl;
    return 0;
}
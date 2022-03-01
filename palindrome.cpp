#include <iostream>
#include <string>

using namespace std;

bool pal(string str, int len)
{
    //If input is only 1 character long, then return true
    if (len == 0 || len == 1)
        return true;
    
    //If ends match, continue moving to the next pair
    if (str[0] == str[len-1])
    {
        //Narrow down the array
        string sub_str = str.substr(1, len-2);
        return pal(sub_str, sub_str.length());
    }
    //If a masmatch is detected, return false
    return false;
}

int main(int argc, char* argv[])
{
    string str;
    cin >> str;
    int n = str.length();
    cout << pal(str, n) << endl;
    return 0;
}
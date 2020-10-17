#include <iostream>

using namespace std;

int main()
{
    unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};

    cout << b << endl;
    cout << b+2 << endl;
    cout << *(b+2) << endl;
    cout << *(b+2)+1 << endl;
    cout << *(*(b+2)+1) << endl;
    cout << b[3][1] << endl;
    cout << b+1 << endl;

    return 0;
}

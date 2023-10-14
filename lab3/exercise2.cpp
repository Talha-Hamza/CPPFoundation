#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

for (int j=1; j<=10; j++)
{
    for (int i=10; i>0; i--)
    {
        cout << setw(4) << i*j;
    }
    cout << endl;
}

return 0;
}
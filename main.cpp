#include <iostream>

using namespace std;

int main()
{
     double Test1, Test2, final, Name, SSN, Percentage;

    cout << "What was your grade for Test1? ";
    cin >> Test1;

    cout << "What was your grade for Test2? ";
    cin >> Test2;

    cout << " What was your final grade? ";
    cin >> final;

    cout << "What is your name? ";
    cin >> Name;

    cout << "What is your Social Security Number? ";
    cin >> SSN;

    // Calculate Percentage
    Percentage = .25 * Test1 + .25 * Test2 + .50 * final / .90;

    //Display
    cout << Percentage;

    return 0;

}



#include <iostream>
#include <cstdlib>
#include <ctime>

#include "vect.h"
#include <vector>
int main()
{
    using namespace std;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    cout << "Podaj dystes do przejscia (k, aby zakonczyc ):";
    while (cin>>target)
    {
        cout << "podaj dlugosc kroku: ";
        if (!(cin >> dstep))
            break;

        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "Po " << steps << " krokach delikwent osiagnal polozenie \n";
        cout << result << endl;
        result.polar_mode();
        cout << "czyli \n" << result << endl;
        cout << "srednia dlugosc kroku pozornego = " << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "podaj dystans do przejscia (k, konczy): ";
    }
    cout << "Koniec !" << endl;
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
    {

    }
}


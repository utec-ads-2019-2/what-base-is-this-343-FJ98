#include <bits/stdc++.h>
using namespace std;

int firstInTen [36 + 3];
int secondInTen [36 + 3];
char first [100];
char second [100];

void resetArrays();
int determineStartBase(char *s);
void convertToTen(char *s, int *save);
void printResult();

int main () {
    while ( cin >> first >> second )
    {
        resetArrays();

        convertToTen(first, firstInTen);
        convertToTen(second, secondInTen);

        printResult();
    }

    return 0;
}


void resetArrays ()
{
    for ( int i = 0; i < 36 + 3; i++ ) {
        firstInTen [i] = -1;
        secondInTen [i] = -2;
    }
}


int determineStartBase(char *s)
{
    int equivalentBase = 0; int sizeOfS = strlen(s); int startBase = 0;
    for (int i = 0; i < sizeOfS; ++i)
    {
        if ( !isdigit( s[i] ) ) equivalentBase = s[i] - 55;
        else equivalentBase = s[i] - 48;
        startBase = max (startBase, equivalentBase);
    }
    return startBase;
}


int sumOfBase(char* s, int i)
{
    int sum = 0; int equivalentBase = 0; int sizeOfS = strlen(s);
    for (int j = sizeOfS - 1; j >= 0; --j)
    {
        if ( !isdigit(s[j]) ) equivalentBase = s[j] - 55;
        else equivalentBase = s [j] - 48;

        sum += static_cast<int>(equivalentBase * std::pow(i, sizeOfS - 1 - j));
    }
    return sum;
}


void convertToTen (char *s, int *save)
{
    int startBase = determineStartBase(s); int sum = 0;
    for ( int i = startBase + 1; i <= 36; ++i )
    {
        sum = sumOfBase(s, i);
        save[i] = sum;
    }
}


void printResult ()
{
    for ( int i = 2; i <= 36; i++ ) {
        for ( int j = 2; j <= 36; j++ ) {
            if ( firstInTen [i] == secondInTen [j] ) {
                cout << first << " (base "<< i << ") = " << second << " (base "<< j << ")" << endl;
                return;
            }
        }
    }
    cout << first << " is not equal to " << second << " in any base 2..36" << endl;
}

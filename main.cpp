#include<bits/stdc++.h>
using namespace std;

int firstInTen [36 + 3];
int secondInTen [36 + 3];
char first [100];
char second [100];

void resetArrays();
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


void convertToTen (char *s, int *save)
{
    int equivalentBase = 0; int sizeOfS = strlen (s); int startBase = 0;

    for (int i = 0; s [i]; ++i)
    {
        if ( !isdigit( s[i] ) ) equivalentBase = s[i] - 55;
        else equivalentBase = s[i] - 48;
        startBase = max (startBase, equivalentBase);
    }
    int sum = 0;
    for ( int i = startBase + 1; i <= 36; ++i )
    {
        sum = 0;
        for (int j = sizeOfS - 1; j >= 0; --j)
        {
            if ( !isdigit (s [j]) ) equivalentBase = s [j] - 55;
            else equivalentBase = s [j] - 48;

            sum += static_cast<int>(equivalentBase * std::pow(i, sizeOfS - 1 - j));
        }
        save[i] = sum;
    }
}


void printResult ()
{
    for ( int i = 2; i <= 36; i++ ) {
        for ( int j = 2; j <= 36; j++ ) {
            if ( firstInTen [i] == secondInTen [j] ) {
                printf ("%s (base %i) = %s (base %i)\n", first, i, second, j);
                return;
            }
        }
    }
    printf ("%s is not equal to %s in any base 2..36\n", first, second);
}

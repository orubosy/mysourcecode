// aplusb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    int noofdigits = 0;
    cin >> noofdigits;
    int digits[noofdigits];
    for (int i = 0; i < noofdigits; i++)
    {
        //digits[i] = 0;
        cin >> digits[i];
    }
    sort((digits), digits + noofdigits);
    int firstpos = noofdigits - 1;
    for (int i = 0; i < noofdigits; i++)
    {
        if (digits[i] >= 0)
        {
            firstpos = i;
            break;
        }
    }
    int noofhits = 0;
    int sum = 0;
    // Starting the real evaluation

    // Two negs
    for (int i = 0; i < firstpos - 1; i++)
    {
        for (int j = i + 1; j < firstpos; j++)
        {
            sum = digits[i] + digits[j];
            for (int k = 0; k < i; k++)
            {
                if (digits[k] == sum)
                {
                    noofhits += 2;
                }

                else
                {
                    if (digits[k] > sum)
                        break;
                }
            }
        }
    }

    // Two pos
    for (int i = firstpos; i < noofdigits - 1; i++)
    {
        for (int j = i + 1; j < noofdigits; j++)
        {
            sum = digits[i] + digits[j];
            for (int k = i + 1; k < noofdigits; k++)
            {
                if (digits[k] == sum)
                {
                    if (k != i && k != j)
                    {
                        noofhits += 2;
                    }
                }

                else
                {
                    if (digits[k] > sum)
                        break;
                }
            }
        }
    }

    // One pos and one neg
    for (int i = 0; i < firstpos; i++)
    {
        for (int j = firstpos; j < noofdigits; j++)
        {
            sum = digits[i] + digits[j];
            if (sum >= 0)
            {
                for (int k = firstpos; k < noofdigits; k++)
                {
                    if (digits[k] == sum)
                    {
                        if (k != j)
                        {
                            noofhits += 2;
                        }
                    }

                    else
                    {
                        if (digits[k] > sum)
                            break;
                    }
                }
            }
            else
            {
                for (int k = 0; k < firstpos; k++)
                {
                    if (digits[k] == sum)
                    {
                        if (k != i)
                        {
                            noofhits += 2;
                        }
                        else
                        {
                            if (digits[k] > sum)
                                break;
                        }
                    }
                }
            }
        }
    }

    //Printing result
    cout << endl
         << noofhits << endl;

    return 0;
}

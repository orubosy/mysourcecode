// aplusb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int casecnt[10];
    int casehits[10];
    for (int i = 0; i < 10; i++)
    {
        casecnt[i] = 0;
        casehits[i] = 0;
    }
    int mycase;
    int noofdigits = 0;
    cin >> noofdigits;
    int digits[noofdigits];
    int firstpos = noofdigits - 1;
    for (int i = 0; i < noofdigits; i++)
    {
        digits[i] = 0;
        cin >> digits[i];
        //cout << digits[i] << " " << to_string(i);
    }

    sort((digits), digits + noofdigits);
    for (int i = 0; i < noofdigits; i++)
    {
        if(digits[i]>=0)
        {
            firstpos=i;
            break;
        }
    }

    // Starting the real evaluation
    int noofhits = 0;
    int sum = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        for (int j = i + 1; j < noofdigits; j++)
        {
            sum = digits[i] + digits[j];
            // Find out case #
            if (digits[i] < 0 && digits[i] % 2 == 0 && digits[j] < 0 && digits[j] % 2 == 0 || digits[j] < 0 && digits[j] % 2 == 0 && digits[i] < 0 && digits[i] % 2 == 0)
            {
                mycase = 0;
                casecnt[mycase]++;
            }
            else if (digits[i] < 0 && digits[i] % 2 == 0 && digits[j] < 0 && digits[j] % 2 == -1 || digits[j] < 0 && digits[j] % 2 == 0 && digits[i] < 0 && digits[i] % 2 == -1)
            {
                mycase = 1;
                casecnt[mycase]++;
            }
            else if (digits[i] < 0 && digits[i] % 2 == 0 && digits[j] >= 0 && digits[j] % 2 == 0 || digits[j] < 0 && digits[j] % 2 == 0 && digits[i] >= 0 && digits[i] % 2 == 0)
            {
                mycase = 2;
                casecnt[mycase]++;
            }
            else if (digits[i] < 0 && digits[i] % 2 == 0 && digits[j] >= 0 && digits[j] % 2 == 1 || digits[j] < 0 && digits[j] % 2 == 0 && digits[i] >= 0 && digits[i] % 2 == 1)
            {
                mycase = 3;
                casecnt[mycase]++;
            }
            else if (digits[i] < 0 && digits[i] % 2 == -1 && digits[j] < 0 && digits[j] % 2 == -1 || digits[j] < 0 && digits[j] % 2 == -1 && digits[i] < 0 && digits[i] % 2 == -1)
            {
                mycase = 4;
                casecnt[mycase]++;
            }
            else if (digits[i] < 0 && digits[i] % 2 == -1 && digits[j] >= 0 && digits[j] % 2 == 0 || digits[j] < 0 && digits[j] % 2 == -1 && digits[i] >= 0 && digits[i] % 2 == 0)
            {
                mycase = 5;
                casecnt[mycase]++;
            }
            else if (digits[i] < 0 && digits[i] % 2 == -1 && digits[j] >= 0 && digits[j] % 2 == 1 || digits[j] < 0 && digits[j] % 2 == -1 && digits[i] >= 0 && digits[i] % 2 == 1)
            {
                mycase = 6;
                casecnt[mycase]++;
            }
            else if (digits[i] >= 0 && digits[i] % 2 == 0 && digits[j] >= 0 && digits[j] % 2 == 0 || digits[j] >= 0 && digits[j] % 2 == 0 && digits[i] >= 0 && digits[i] % 2 == 0)
            {
                mycase = 7;
                casecnt[mycase]++;
            }
            else if (digits[i] >= 0 && digits[i] % 2 == 0 && digits[j] >= 0 && digits[j] % 2 == 1 || digits[j] >= 0 && digits[j] % 2 == 0 && digits[i] >= 0 && digits[i] % 2 == 1)
            {
                mycase = 8;
                casecnt[mycase]++;
            }
            else if (digits[i] >= 0 && digits[i] % 2 == 1 && digits[j] >= 0 && digits[j] % 2 == 1 || digits[j] >= 0 && digits[j] % 2 == 1 && digits[i] >= 0 && digits[i] % 2 == 1)
            {
                mycase = 9;
                casecnt[mycase]++;
            }
            for (int k = 0; k < noofdigits; k++)
            {
                if (digits[k] == sum)
                {
                    if (k != i && k != j && i != j)
                    {
                        noofhits +=2;
                        casehits[mycase] +=2;
                        //cout << digits[i] << " + " << digits[j] << " = " << digits[k] << endl;
                    }
                }
            }
        }
    }
    int cntcntl = 0;
    for (int i = 1; i <= 10; i++)
    {
        cout << "Case # " << i << "\t" << casecnt[i - 1] << "\tHits = " << casehits[i - 1] << endl;
        cntcntl += casecnt[i - 1];
    }
    cout << endl << "Total # of case counts = " << cntcntl << endl;
    //Printing result
    cout << endl << "Total # of hits = " << noofhits << endl;

    return 0;
}

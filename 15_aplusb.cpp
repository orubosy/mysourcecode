// aplusb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    bool do_printing = false;
    int noofdigits = 0;
    cin >> noofdigits;

    int digits[noofdigits];
    for (int i = 0; i < noofdigits; i++)
    {
        cin >> digits[i];
        //cout << digits[i] << " " << to_string(i);
    }
    sort((digits), digits + noofdigits);
    int maxi = digits[noofdigits -1];
    int mini = digits[0];

    //Finding the first positive number
    int firstpos = noofdigits - 1;
    for (int i = 0; i < noofdigits; i++)
    {
        if (digits[i] >= 0)
        {
            firstpos = i;
            break;
        }
    }

    // Starting the real evaluation
    int noofhits = 0;
    int sum = 0;

    for (int i = 0; i < noofdigits - 1; i++)
    {
        for (int j = i + 1; j < noofdigits; j++)
        {
            sum = digits[i] + digits[j];
            if(sum < mini || sum > maxi)
            {
                 continue;
            }
            if (i < firstpos && j < firstpos) // Two negative number
            {
                //cout << "Negs\t" << digits[i] << " + " << digits[j] << endl;
                for (int k = 0; k < i; k++)
                {
                    if (digits[k] == sum)
                    {
                        if(k==i || k==j) continue;                        
                        noofhits += 2;
                    }
                    else
                    {
                        if (digits[k] > sum)
                        {
                            break;
                        }
                    }
                }
            }
            else if (i >= firstpos && j >= firstpos) // Two positive numbers
            {
                //cout << "Pos\t" << digits[i] << " + " << digits[j] << endl;
                for (int k = firstpos; k < noofdigits; k++)
                {
                    if (digits[k] == sum)
                    {        
                        if(k==i || k==j) continue;                                     
                        noofhits += 2;
                    }
                    else
                    {
                        if (digits[k] > sum)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                // One positive and one negative
                //cout << "Mixed\t" << digits[i] << " + " << digits[j] << endl;
                for (int k = 0; k < j; k++)
                {
                    if (digits[k] == sum)
                    {
                        if(k==i) continue; 
                        noofhits += 2;
                    }
                    else
                    {
                        if (digits[k] > sum)
                        {
                            break;
                        }
                    }

                }
            }
        }
    }

    //Printing result
    //cout << endl << "Total # of hits = " << noofhits << endl;
    cout << noofhits << endl;

    return 0;
}

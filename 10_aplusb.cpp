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
    int noofevennegs = 0;
    int noofoddnegs = 0;
    int noofevenposs = 0;
    int noofoddposs = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        cin >> digits[i];
        if (digits[i] < 0)
        {
            if (digits[i] % 2 == 0)
            {
                noofevennegs++;
            }
            else
            {
                noofoddnegs++;
            }
        }
        else
        {
            if (digits[i] % 2 == 0)
            {
                noofevenposs++;
            }
            else
            {
                noofoddposs++;
            }
        }
    }
    int evennegs[noofevennegs];
    int evenposs[noofevenposs];
    int oddnegs[noofoddnegs];
    int oddposs[noofoddposs];
    int idx = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        if (digits[i] < 0)
        {
            if (digits[i] % 2 == 0)
            {
                evennegs[idx++] = digits[i];
            }
        }
    }
    idx = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        if (digits[i] < 0)
        {
            if (digits[i] % 2 == -1)
            {
                oddnegs[idx++] = digits[i];
            }
        }
    }
    idx = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        if (digits[i] >= 0)
        {
            if (digits[i] % 2 == 0)
            {
                evenposs[idx++] = digits[i];
            }
        }
    }
    idx = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        if (digits[i] >= 0)
        {
            if (digits[i] % 2 == 1)
            {
                oddposs[idx++] = digits[i];
            }
        }
    }

    sort((evenposs), evenposs + noofevenposs);
    sort((evennegs), evennegs + noofevennegs);
    sort((oddnegs), oddnegs + noofoddnegs);
    sort((oddposs), oddposs + noofoddposs);

    // Starting the real evaluation
    int noofhits = 0;
    int casehits[10];
    for (int i = 0; i < 10; i++)
    {
        casehits[i] = 0;
    }
    int sum = 0;
    int maxi = max(evenposs[noofevenposs - 1], oddposs[noofoddposs - 1]);
    int mini = min(evennegs[0], oddnegs[0]);

    for (int i = 0; i < noofdigits; i++)
    {
        for (int j = i + 1; j < noofdigits; j++)
        {
            sum = digits[i] + digits[j];
            if (digits[i] < 0 && digits[i] % 2 == 0 && digits[j] < 0 && digits[j] % 2 == 0 || digits[j] < 0 && digits[j] % 2 == 0 && digits[i] < 0 && digits[i] % 2 == 0)
            {
                // Case: 1 Two even negative number
                if (sum < mini)
                {
                    continue;
                }
                for (int k = 0; k < i; k++)
                {
                    if (evennegs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[0] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                    else
                    {
                        if (evennegs[k] > sum)
                        {
                            break;
                        }
                    }
                }
                break;
            }

            if (digits[i] < 0 && digits[i] % 2 == 0 && digits[j] < 0 && digits[j] % 2 == -1 || digits[j] < 0 && digits[j] % 2 == 0 && digits[i] < 0 && digits[i] % 2 == -1)
            {
                // Case : 2 One even neg and one odd neg
                if (sum < mini)
                {
                    continue;
                }
                for (int k = 0; k < noofoddnegs; k++)
                {
                    if (oddnegs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[1] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }

                    else
                    {
                        if (oddnegs[k] > sum)
                        {
                            break;
                        }
                    }
                }
                break;
            }

            if (digits[i] < 0 && digits[i] % 2 == 0 && digits[j] >= 0 && digits[j] % 2 == 0 || digits[j] < 0 && digits[j] % 2 == 0 && digits[i] >= 0 && digits[i] % 2 == 0)
            { // Case : 3 One even neg and one even pos
                for (int k = 0; k < noofevennegs; k++)
                {
                    if (evennegs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[2] += 2;

                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                }
                for (int k = 0; k < noofevenposs; k++)
                {
                    if (evenposs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[2] += 2;

                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                }
                break;
            }

            if (digits[i] < 0 && digits[i] % 2 == 0 && digits[j] >= 0 && digits[j] % 2 == 1 || digits[j] < 0 && digits[j] % 2 == 0 && digits[i] >= 0 && digits[i] % 2 == 1)
            { // Case : 4 One even neg and one odd pos
                for (int k = 0; k < noofoddnegs; k++)
                {
                    if (oddnegs[k] == sum)
                    {
                        noofhits++;
                        casehits[3] += 2;

                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                }

                for (int k = 0; k < noofoddposs; k++)
                {
                    if (oddposs[k] == sum)
                    {
                        noofhits++;
                        casehits[3] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                    else
                    {
                        if (oddposs[k] > sum)
                        {
                            break;
                        }
                    }
                }
                break;
            }

            if (digits[i] < 0 && digits[i] % 2 == -1 && digits[j] < 0 && digits[j] % 2 == -1 || digits[j] < 0 && digits[j] % 2 == -1 && digits[i] < 0 && digits[i] % 2 == -1)
            { // Case : 5 Two odd negative numbers
                if (sum < mini)
                {
                    break;
                }
                for (int k = 0; k < i; k++)
                {
                    if (evennegs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[4] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                    else
                    {
                        if (evennegs[k] > sum)
                        {
                            break;
                        }
                    }
                }
                break;
            }

            if (digits[i] < 0 && digits[i] % 2 == -1 && digits[j] >= 0 && digits[j] % 2 == 0 || digits[j] < 0 && digits[j] % 2 == -1 && digits[i] >= 0 && digits[i] % 2 == 0)
            { // Case : 6 One odd neg and one even pos
                for (int k = 0; k < noofoddnegs; k++)
                {
                    if (oddnegs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[5] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                    else
                    {
                        if (oddnegs[k] > sum)
                        {
                            break;
                        }
                    }
                }

                for (int k = 0; k < noofoddposs; k++)
                {
                    if (oddposs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[5] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                    else
                    {
                        if (oddposs[k] > sum)
                        {
                            break;
                        }
                    }
                }
                break;
            }

            if (digits[i] < 0 && digits[i] % 2 == -1 && digits[j] >= 0 && digits[j] % 2 == 1 || digits[j] < 0 && digits[j] % 2 == -1 && digits[i] >= 0 && digits[i] % 2 == 1)
            { // Case : 7 One odd neg and one odd pos
                for (int k = 0; k < noofevennegs; k++)
                {
                    if (evennegs[k] == sum)
                    {
                        noofhits += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                }

                for (int k = 0; k < noofevenposs; k++)
                {
                    if (evenposs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[6] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                    else
                    {
                        if (evenposs[k] > sum)
                        {
                            break;
                        }
                    }
                }
                break;
            }

            if (digits[i] >= 0 && digits[i] % 2 == 0 && digits[j] >= 0 && digits[j] % 2 == 0 || digits[j] >= 0 && digits[j] % 2 == 0 && digits[i] >= 0 && digits[i] % 2 == 0)
            { // Case : 8 Two even positive numbers
                if (sum > maxi)
                {
                    break;
                }
                for (int k = 0; k < noofevenposs; k++)
                {
                    if (evenposs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[7] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                    else
                    {
                        if (evenposs[k] > sum)
                        {
                            break;
                        }
                    }
                }
                break;
            }

            if (digits[i] >= 0 && digits[i] % 2 == 0 && digits[j] >= 0 && digits[j] % 2 == 1 || digits[j] >= 0 && digits[j] % 2 == 0 && digits[i] >= 0 && digits[i] % 2 == 1)
            { // Case : 9 One even positive and one odd positive number
                for (int k = 0; k < noofevennegs; k++)
                {
                    if (oddposs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[8] += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                    else
                    {
                        if (oddposs[k] > sum)
                        {
                            break;
                        }
                    }
                }
                break;
            }

            if (digits[i] >= 0 && digits[i] % 2 == 1 && digits[j] >= 0 && digits[j] % 2 == 1 || digits[j] >= 0 && digits[j] % 2 == 1 && digits[i] >= 0 && digits[i] % 2 == 1)
            { // Case : 10 Two odd positive numbers
                for (int k = 0; k < noofevenposs; k++)
                {
                    if (sum > maxi)
                        continue;
                    if (evenposs[k] == sum)
                    {
                        noofhits += 2;
                        casehits[9] += 2;
                        //cout << oddposs[i] << " + " << oddposs[j] << " = " << evenposs[k] << endl;
                    }
                }
                break;
            }
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        cout << "Case # " << i << "\t" << casehits[i - 1] << endl;
        if (i == 5)
            cout << endl;
    }
    //Printing result
    //cout << endl << "Total # of hits = " << noofhits << endl;
    cout << endl
         << noofhits << endl;

    return 0;
}

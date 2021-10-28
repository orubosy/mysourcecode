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
    int sum = 0;
    int maxi = max(evenposs[noofevenposs - 1], oddposs[noofoddposs - 1]);
    int mini = min(evennegs[0], oddnegs[0]);
    /*
    // Case: 1 Two even negative number
    for (int i = 0; i < noofevennegs - 1; i++)
    {
        for (int j = i + 1; j < noofevennegs; j++)
        {
            sum = evennegs[i] + evennegs[j];
            if (sum < mini)
            {
                continue;
            }
            for (int k = 0; k < i; k++)
            {
                if (evennegs[k] == sum)
                {
                    noofhits += 2;
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
        }
    }

    cout << noofhits << endl;


    // Case : 2 One even neg and one odd neg
    for (int i = 0; i < noofevennegs; i++)
    {
        for (int j = 0; j < noofoddnegs; j++)
        {
            sum = evennegs[i] + oddnegs[j];
            if (sum < mini)
            {
                continue;
            }
            for (int k = 0; k < noofoddnegs; k++)
            {
                if (oddnegs[k] == sum)
                {
                    if (k == i || k == j)
                        continue;
                    noofhits +=2;
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
        }
    }
    cout << noofhits << endl;
*/

    // Case : 3 One even neg and one even pos
    
        for (int i = 0; i < noofevennegs; i++)
        {
            for (int j = 0; j < noofevenposs; j++)
            {
                sum = evennegs[i] + evenposs[j];
                for (int k = 0; k < noofevennegs; k++)
                {
                    if (evennegs[k] == sum)
                    {
                        if (k != i && k != j && i != j)
                            noofhits += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                }
                for (int k = 0; k < noofevenposs; k++)
                {
                    if (evenposs[k] == sum)
                    {
                        if (k != i && k != j && i != j)
                            noofhits += 2;
                        //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                    }
                }
            }
        }
    

    cout << noofhits << endl;

    /*
    // Case : 4 One even neg and one odd pos
    for (int i = 0; i < noofevennegs; i++)
    {
        for (int j = 0; j < noofoddposs; j++)
        {
            sum = evennegs[i] + oddposs[j];
            for (int k = 0; k < noofoddnegs; k++)
            {
                if (oddnegs[k] == sum)
                {
                    if (k == i || k == j)
                        continue;
                    noofhits++;
                    //if (do_printing) cout << i << " " << j << " " << k << "\t" << poss[i] << " + " << poss[j] << " = " << poss[k] << endl;
                }
            }

            for (int k = 0; k < noofoddposs; k++)
            {
                if (oddposs[k] == sum)
                {
                    if (k == i || k == j)
                        continue;
                    noofhits++;
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
        }
    }
    cout << noofhits << endl;

    // Case : 5 Two odd negative numbers
    for (int i = 0; i < noofoddnegs - 2; i++)
    {
        for (int j = i + 1; j < noofoddnegs - 1; j++)
        {
            sum = oddnegs[i] + oddnegs[j];
            if (sum < mini)
            {
                break;
            }
            for (int k = 0; k < i; k++)
            {
                if (evennegs[k] == sum)
                {
                    noofhits += 2;
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
        }
    }
    cout << noofhits << endl
         << endl;

    // Case : 6 One odd neg and one even pos
    for (int i = 0; i < noofoddnegs; i++)
    {
        for (int j = 0; j < noofevenposs; j++)
        {
            sum = oddnegs[i] + evenposs[j];
            for (int k = 0; k < noofoddnegs; k++)
            {
                if (oddnegs[k] == sum)
                {
                    if (k == i || k == j)
                        continue;
                    noofhits += 2;
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
                    if (k == i || k == j)
                        continue;
                    noofhits += 2;
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
        }
    }
    cout << noofhits << endl;

    // Case : 7 One odd neg and one odd pos
    for (int i = 0; i < noofoddnegs; i++)
    {
        for (int j = 0; j < noofoddposs; j++)
        {
            sum = oddnegs[i] + oddposs[j];
            for (int k = 0; k < noofevennegs; k++)
            {
                if (evennegs[k] == sum)
                {
                    if (k == i || k == j)
                        continue;
                    noofhits += 2;
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

            for (int k = 0; k < noofevenposs; k++)
            {
                if (evenposs[k] == sum)
                {
                    if (k == i || k == j)
                        continue;
                    noofhits += 2;
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
        }
    }
    cout << noofhits << endl;

    // Case : 8 Two even positive numbers
    for (int i = 0; i < noofevenposs - 2; i++)
    {
        for (int j = i + 1; j < noofevenposs - 1; j++)
        {
            sum = evenposs[i] + evenposs[j];
            if (sum > maxi)
            {
                break;
            }
            for (int k = j + 1; k < noofevenposs; k++)
            {
                if (evenposs[k] == sum)
                {
                    noofhits += 2;
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
        }
    }
    cout << noofhits << endl;

    // Case : 9 One even positive and one odd positive number
    for (int i = 0; i < noofevennegs - 2; i++)
    {
        for (int j = i + 1; j < noofoddposs - 1; j++)
        {
            sum = evennegs[i] + oddposs[j];
            for (int k = 0; k < noofevennegs; k++)
            {
                if (oddposs[k] == sum)
                {
                    noofhits += 2;
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
        }
    }
    cout << noofhits << endl;

    // Case : 10 Two odd positive numbers
    for (int i = 0; i < noofoddposs - 1; i++)
    {
        for (int j = i + 1; j < noofoddposs; j++)
        {
            sum = oddposs[i] + oddposs[j];
            for (int k = j + 1; k < noofevenposs; k++)
            {
                if (evenposs[k] == sum)
                {
                    noofhits += 2;
                    cout << oddposs[i] << " + " << oddposs[j] << " = " << evenposs[k] << endl;
                }
            }
        }
    }
*/
    //Printing result
    //cout << endl << "Total # of hits = " << noofhits << endl;
    cout << noofhits << endl;

    return 0;
}

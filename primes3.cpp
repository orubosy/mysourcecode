
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    cout << "Ange högsta primtalet > ";
    string stopp_txt = "";
    cin >> stopp_txt;
    long stopp = stol(stopp_txt);

    std::vector<long> primes;
    std::cout << 2 << " " << 3 << " ";
    primes.push_back(3);
    for(long i=5; i < stopp; i+=2)
    {
        bool prime=true;
        for(long j=0;j<primes.size() && primes[j]*primes[j] <= i;j++)
        {
            if(i % primes[j] == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime) 
        {
            primes.push_back(i);
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
    return 0;
}

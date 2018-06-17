#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
        if(n == 1)
                return false;
        bool flag = true;
        int root = sqrt(n);
        for(int i=2;i<=root;i++)
        {
                if(n % i == 0)
                {
                        flag = false;
                        break;
                }
        }
        return flag;
}

void PrimeFactors(int n)
{
	int limit = n/2;
        for(int i=2;i<=limit;i++)
	{
		if(isPrime(i))
		{
			int count = 0;
			while(n % i == 0)
			{
				n = n/i;
				count++;
			}

			if(count > 0)
				cout << i << "(" << count << ")"<<endl;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	PrimeFactors(n);
	return 0;
}

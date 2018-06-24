#include <iostream>
#include <string>

using namespace std;

void reverse(string &str, int low, int high)
{
	while(low < high)
	{
		char temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		low ++;
		high --;
	}
}

int BasetoDecimal(string str, int base)
{
	int decimal = 0, temp;
	for(int i=0;str[i];i++)
	{
		if(str[i] >= 'A' && str[i] <= 'F')
			temp = str[i] - 'A' + 10;
		else
			temp = str[i] - '0';

		decimal = base * decimal + temp;
	}

	return decimal;
}

string DecimaltoBase(int decimal, int base)
{
	string baseb1 = "";

	while(decimal > 0)
	{
		int remainder = decimal % base;
		decimal /= base;

		if(remainder > 9)
		{
			baseb1 += char((remainder-10)+'A');
		}
		else
			baseb1 += char(remainder + '0');
	}

	reverse(baseb1, 0 ,baseb1.size()-1);
	return baseb1;
}

int main()
{
	int b1, b2;
	cout << "Enter which base to which base";
	cin >> b1 >> b2;

	cout << "Enter the number in base " << b1 << " : ";
	string str;
	cin >> str;

	int decimal = BasetoDecimal(str, b1);
	cout << decimal << endl;
	string baseb1 = DecimaltoBase(decimal, b2);
	cout << baseb1 << endl;
	return 0;
}

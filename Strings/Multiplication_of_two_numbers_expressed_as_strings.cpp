/*
	--- Question Statement ---

	Given two numbers represented as a string, return multiplication of the
	numbers as a string. The numbers can be arbitrarily large and non-negative.
	Leading zeroes are not accepted.
*/

#include <iostream>

using namespace std;

string addition(string str1, string str2)
{
	int size1 = str1.size();
	int size2 = str2.size();

	for(int i=size1;i<size2;i++)
		str1 = '0'+str1;

	for(int i=size2;i<size1;i++)
		str2 = '0'+str2;

	string result = "";

	int length = str1.size(), carry = 0, sum;
	for(int i=length-1;i>=0;i--)
	{
		sum = (str1[i]-'0') + (str2[i]-'0') + carry;
		if(sum > 9)
		{
		    sum = sum % 10;
			carry = 1;
		}
		else
			carry = 0;

		result = char(sum+'0') + result;
	}

	return result;
}

string multiply(string str1, string str2)
{
	int size1 = str1.size();
	int size2 = str2.size();

	string tempresult = "", result = "0", place ="0";
	int temp, carry = 0;

	for(int i=size1-1;i>=0;i--)
	{
	    carry = 0;
		for(int j=size2-1;j>=0;j--)
		{
			temp = (int)(str1[i]-'0') * (int)(str2[j]-'0') + carry;
			if(temp > 9)
			{
			    carry = temp/10;
				temp = temp % 10;
			}
			else
				carry = 0;

			tempresult = char(temp+'0') + tempresult;
		}

        if(carry != 0)
            tempresult = char(carry+'0') + tempresult;

		if(i != size1-1)
		{
            tempresult += place;
            place += '0';
		}

		result = addition(tempresult, result);
		tempresult = "";
	}

	return result;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	cout << multiply(str1, str2) << endl;
	return 0;
}

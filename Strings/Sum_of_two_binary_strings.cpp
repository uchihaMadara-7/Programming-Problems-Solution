/*
	--- Question Statement ---

	Given two binary strings. Add the two binary strings and the result is also
	a binary strings.
	Example : a=111 b=001 output: 1000

*/

#include <iostream>

using namespace std;

string add_binary(string str1, string str2)
{
	int size1 = str1.size();
	int size2 = str2.size();

	for(int i=size1;i<size2;i++)
        str1 = "0"+str1;

    for(int i=size2;i<size1;i++)
        str2 = "0"+str2;

    cout << str1 <<" " << str2 << endl;
    int high = str1.size();

	string result = "";
	int carry = 0;
	while(high--)
	{
		int sum = (str1[high]-'0') + (str2[high]-'0') + carry;
		if(sum == 2)
		{
			result = '0' + result;
			carry = 1;
		}
		else if(sum == 3)
		{
			result = '1' + result;
			carry = 1;
		}
		else
		{
			result = char(sum + '0') + result;
			carry = 0;
		}

		cout << result << endl;
	}

	if(carry == 1)
        return "1"+result;
	return result;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	cout << add_binary(str1, str2);
	return 0;
}

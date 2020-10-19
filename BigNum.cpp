#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

BigNum::BigNum(string n1, string n2)
{
    num1 = n1;
    num2 = n2;
}

BigNum::~BigNum(){};

string BigNum::Add()
{
    if (num1.length() > num2.length())
    {
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }

    reverse(num1.rbegin(), num1.rend());
    reverse(num2.rbegin(), num2.rend());

    string result;

    int carry = 0;
    int value;

    int difference = num2.length() - num1.length();

    for (int i = 0; i < difference; i++)
    {
        num1 += '0';
    }

    for (int i = 0; i < num2.length(); i++)
    {
        value = (num1[i] - '0') + (num2[i] - '0') + carry;
        char val = (char)value;

        if (value > 9)
        {
            carry = 1;
            value = value % 10;
        }
        else
            carry = 0;
        value += '0';
        val = value;
        result += val;
    }
    if (carry == 1)
        result += '1';

    reverse(result.rbegin(), result.rend());

    return result;
}

string BigNum::Subtract()
{
    if (num1.length() > num2.length())
    {
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }

    reverse(num1.rbegin(), num1.rend());
    reverse(num2.rbegin(), num2.rend());

    string result;
    int carry = 0;

    int difference = num2.length() - num1.length();

    int value;
    int j = 1;

    for (int i = 0; i < num1.length(); i++)
    {
        value = (num2[i] - '0') - (num1[i] - '0') - carry;
        char val = (char)value;
        if (value < 0)
        {
            carry = 1;
            value += 10;
        }
        else
        {
            carry = 0;
        }
        value += '0';
        val = value;
        result += val;
    }

    for (int i = num1.length(); i < num2.length(); i++)
    {
        value = (num2[i] - '0') - carry;
        char val = (char)value;
        if (value < 0)
        {
            carry = 1;
            value += 10;
        }
        else
        {
            carry = 0;
        }
        value += '0';
        val = value;
        result += val;
    }
    reverse(result.rbegin(), result.rend());
    return result;
}

string BigNum::Multiply()
{
    if (num1.length() > num2.length())
    {
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }

    string result;
    vector<string> add;
    int carry = 0;
    int value;

    reverse(num1.rbegin(), num1.rend());
    reverse(num2.rbegin(), num2.rend());

    for (int i = 0; i < num1.length(); i++)
    {
        for (int j = 0; j < num2.length(); j++)
        {
            value = (num1[i] - '0') * (num2[j] - '0') + carry;

            char val = (char)value;

            if (value > 9)
            {
                carry = (value - value % 10) / 10;
                value = value % 10;
            }
            else
                carry = 0;
            value += '0';
            val = value;
            result += val;
        }
        if (carry > 0)
        {
            result += (carry + '0');
            carry = 0;
        }
        reverse(result.rbegin(), result.rend());
        add.push_back(result);
        result = "";
        result += string(i + 1, '0');
    }

    result = "";
    for (int i = 0; i < add.size(); i++)
    {
        BigNum a(add[i], result);
        result = a.Add();
    }

    return result;
}

string BigNum::Divide()
{

    

}
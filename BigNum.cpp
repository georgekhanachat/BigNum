#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

string BigNum::Add(string num1, string num2)
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
            value += '0';
            val = value;
            result += val;
        }
        else
        {
            carry = 0;
            value += '0';
            val = value;
            result += val;
        }
    }
    if (carry == 1)
        result += '1';

    reverse(result.rbegin(), result.rend());

    return result;
}

string BigNum::Multiply(string num1, string num2)
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
                value += '0';
                val = value;
                result += val;
            }
            else
            {
                carry = 0;
                value += '0';
                val = value;
                result += val;
            }
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
        result = Add(add[i], result);
    }

    return result;
}


string BigNum::Divide(string num1, string num2)
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

    do 
    {


    } while (!num2.empty());

    
}
#include <string>

using namespace std;

class BigNum {
    private:
        string num1;
        string num2;
    public:
        string Add(string num1, string num2);
        string Multiply(string num1, string num2);
        string Divide(string num1, string num2);
};

#include <string>

using namespace std;

class BigNum {
    private:
        string num1;
        string num2;
    public:
        string Add();
        string Multiply();
        string Divide();
        string Subtract();
        BigNum (string num1, string num2);
        ~BigNum ();
};

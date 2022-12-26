#include <iostream>

class Payment
{
    public:
        float amount;
        bool rest;
        std::string moneyName;
        std::string hashCode;

        Payment(bool rest)
        {
            this->rest = rest;
            amount = 12.1;
            moneyName = "blabla";
            hashCode = "14530111";
            std::cout << "yap" << std::endl;
        }
        Payment()
        {
            amount = 12.1;
            moneyName = "blabla";
            hashCode = "14530111";
            std::cout << "yap" << std::endl;
        }
        void pay()
        {
            std::cout << "ödeme alındı." << std::endl;
            std::cout << rest << std::endl;
        }

};

int main()
{
    {
        Payment pay(999);
        pay.pay();
    }
}
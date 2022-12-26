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
        virtual void pay()
        {
            std::cout << "ödeme alındı. Default" << std::endl;
        };

        void update()
        {
            std::cout << "Güncellendi. Default" << std::endl;
        }

};

class CreditCard : public Payment
{
    public:
        void pay()
        {
           std::cout << "ödeme alındı. Credit Card" << std::endl;
        }
        void update()
        {
            std::cout << "Güncellendi. Credit Card" << std::endl;
        }

};

class Cash : public Payment
{
        public:
        void pay()
        {
           std::cout << "ödeme alındı. Cash" << std::endl;
        }
        void update()
        {
            std::cout << "Güncellendi. Cash" << std::endl;
        }
};

void pay(Payment *payx)
{
    payx->pay();
}

int main()
{
    CreditCard creditCard;
    Cash cash;

    pay(&creditCard);
    pay(&cash);

    creditCard.update();
}
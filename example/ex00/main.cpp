#include <iostream>

int printf_text3(std::string text)
{
    std::cout << text << std::endl;
    return (1);
}

int printf_text2(int num1, int num2)
{
    std::cout << num1 << num2;
    return (num1 + num2);
}

void print_text()
{
    unsigned char abc;
    unsigned char abc1;
    // bool x = true;
    // auto l = "test";
    int8_t a;
    int8_t b;
    int res;

    a = 48;
    b = 12;
    abc = 'a';
    abc1 = 'b';
    std::cout << abc + abc1 << '\n';
    std::cout << a << '\n';
    // std::cout << l << '\n';
    res = static_cast<int>(a);
    std::cout << res << '\n';
}

int main()
{
    print_text();
    int res = printf_text2(1, 3);
    std::cout << res;
    int res1 = printf_text3("enes");
    std::cout << res1;
}
#pragma once

#include <iostream>
#include <assert.h>

namespace Facade
{

//--------------------------------------------------
class SubSystem1
{
public:

    SubSystem1(){}
    ~SubSystem1(){}

    int GetPrice() const { return 1000; }
};

//--------------------------------------------------
class SubSystem2
{
public:

    SubSystem2() {}
    ~SubSystem2() {}

    int GetPrice() const { return 2000; }
};

//--------------------------------------------------
class SubSystem3
{
public:

    SubSystem3() : totalPrice(0) {}
    ~SubSystem3() {}

    void AddPrice(const int price)
    {
        totalPrice += price;
    }

    int GetTotalPrice() const
    {
        return totalPrice;
    }

private:
    int totalPrice;
};
//--------------------------------------------------
// サブシステムの仲介を担う
class Facade
{
public:

    Facade() {}
    ~Facade() {}

    void BuySubSystem1()
    {
        int price = sub1.GetPrice();
        sub3.AddPrice(price);
    }

    void BuySubSystem2()
    {
        int price = sub2.GetPrice();
        sub3.AddPrice(price);
    }

    void ShowTotalPrice() const
    {
        std::cout << sub3.GetTotalPrice() << std::endl;
    }

private:

    SubSystem1 sub1;
    SubSystem2 sub2;
    SubSystem3 sub3;
};


//--------------------------------------------------
// 実装例
void ExecExample()
{
    Facade facade;

    facade.BuySubSystem1(); // 1000
    facade.BuySubSystem1(); // 2000

    facade.BuySubSystem2(); // 4000
    facade.BuySubSystem2(); // 6000
    facade.BuySubSystem2(); // 8000

    facade.ShowTotalPrice();
}

} // namespace Facade

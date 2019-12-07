#pragma once

#include <iostream>
#include <assert.h>

namespace CoR
{

enum
{
    CHAIN_HIT_CLASS = 3
};

//--------------------------------------------------
// CoR ( Chain of Responsibility ) の基底クラス
class Base
{
public:

    Base() : m_pNext(nullptr) {}
    virtual ~Base() {}

    // 次の処理クラスを設定
    Base* SetNext(Base* pNext)
    {
        assert(pNext != nullptr);
        this->m_pNext = pNext;
        return this->m_pNext;
    }

    // 処理可能なら処理
    int Request()
    {
        if (CanExec_() == true)
        {
            const int value = Exec_();
            return value;
        }
        else
        {
            if (m_pNext == nullptr)
            {
                std::cout << "全処理クラスで処理できなかった" << std::endl;
            }
            else
            {
                const int value = this->m_pNext->Request();
                return value;
            }
        }
        return -1;
    }

private:

    virtual int Exec_() const = 0;
    virtual bool CanExec_() const = 0;

private:

    Base* m_pNext;
};


//--------------------------------------------------
// CoR の派生クラス1
class Chain1 final : public Base
{
public:

    Chain1() {}
    virtual ~Chain1() {}

private:

    int Exec_() const override
    {
        return 1;
    }

    bool CanExec_() const override
    {
        return CHAIN_HIT_CLASS == 1 ? true : false;
    }
};

//--------------------------------------------------
// CoR の派生クラス2
class Chain2 final : public Base
{
public:

    Chain2() {}
    virtual ~Chain2() {}

private:

    int Exec_() const override
    {
        return 2;
    }

    bool CanExec_() const override
    {
        return CHAIN_HIT_CLASS == 2 ? true : false;
    }
};

//--------------------------------------------------
// CoR の派生クラス3
class Chain3 final : public Base
{
public:

    Chain3() {}
    virtual ~Chain3() {}

private:

    int Exec_() const override
    {
        return 3;
    }

    bool CanExec_() const override
    {
        return CHAIN_HIT_CLASS == 3 ? true : false;
    }
};

//--------------------------------------------------
// 実装例
void ExecExample()
{
    Chain1* chain1 = new Chain1();
    Chain2* chain2 = new Chain2();
    Chain3* chain3 = new Chain3();

    // 構築
    chain1->SetNext(chain2)->SetNext(chain3);

    // 実行
    int value = chain1->Request();

    // 結果
    std::cout << "result = " << value << std::endl;

    delete chain3;
    delete chain2;
    delete chain1;
}

} // namespace CoR

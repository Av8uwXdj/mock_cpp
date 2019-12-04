#include <iostream>
#include <assert.h>

namespace
{
    enum
    {
        CHAIN_HIT_CLASS = 2
    };
}

//--------------------------------------------------
// Chain of Responsibility の基底クラス
class Base
{
public:

    Base() : pNext(nullptr) {}
    virtual ~Base() {}

    // 次の処理クラスを設定
    Base* SetNext(Base* pNext)
    {
        assert(pNext != nullptr);
        this->pNext = pNext;
        return this->pNext;
    }

    // 処理可能なら処理
    int Request()
    {
        if (_CanExec() == true)
        {
            int value = _Exec();
            return value;
        }
        else
        {
            if (pNext == nullptr)
            {
                std::cout << "全処理クラスで処理できなかった" << std::endl;
            }
            else
            {
                int value = this->pNext->Request();
                return value;
            }
        }
        return -1;
    }

private:

    virtual int _Exec() = 0;
    virtual bool _CanExec() = 0;

private:

    Base* pNext;
};


//--------------------------------------------------
// Chain of Responsibility の派生クラス1
class Chain1 : public Base
{
public:

    Chain1() {}
    virtual ~Chain1() {}

private:

    int _Exec()
    {
        return 1;
    }

    bool _CanExec()
    {
        if (CHAIN_HIT_CLASS == 1)
        {
            return true;
        }
        return false;
    }
};

//--------------------------------------------------
// Chain of Responsibility の派生クラス2
class Chain2 : public Base
{
public:

    Chain2() {}
    virtual ~Chain2() {}

private:

    int _Exec()
    {
        return 2;
    }

    bool _CanExec()
    {
        if (CHAIN_HIT_CLASS == 2)
        {
            return true;
        }
        return false;
    }
};

//--------------------------------------------------
// Chain of Responsibility の派生クラス3
class Chain3 : public Base
{
public:

    Chain3() {}
    virtual ~Chain3() {}

private:

    int _Exec()
    {
        return 3;
    }

    bool _CanExec()
    {
        if (CHAIN_HIT_CLASS == 3)
        {
            return true;
        }
        return false;
    }
};

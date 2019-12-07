#pragma once

#include <list>
#include <iostream>
#include <assert.h>

namespace Observer
{

//--------------------------------------------------
// 通知される側の規定クラス
class ObserverBase
{
public:

    ObserverBase() {}
    virtual ~ObserverBase() {}

    // 通知された時のコールバック
    virtual void OnChangeSubject() = 0;
};

//--------------------------------------------------
// 通知する側の規定クラス
class SubjectBase
{
public:

    SubjectBase() : m_pObserverList{ nullptr } {}
    virtual ~SubjectBase() {}

    // 変更する
    void ChangeSubject()
    {
        bool isChange = Change_();
        if (isChange == true)
        {
            OnChangeSubject_();
        }
    }

    // 通知する対象を設定する
    void AddObserver(ObserverBase* pObserverBase)
    {
        assert(pObserverBase != nullptr);
        m_pObserverList.push_back(pObserverBase);
    }

private:

    // 変更時のコールバック
    void OnChangeSubject_()
    {
        for (ObserverBase* pObserver : m_pObserverList)
        {
            if (pObserver != nullptr)
            {
                pObserver->OnChangeSubject();
            }
        }
    }

    virtual bool Change_() = 0;

private:

    std::list<ObserverBase*> m_pObserverList;
};

//--------------------------------------------------
// Subject1 と Subject2 を監視する
class Observer1 : public ObserverBase
{
public:

    Observer1() : ObserverBase() {}
    virtual ~Observer1() {}

    virtual void OnChangeSubject()
    {
        std::cout << "observer1" << std::endl;
    }
};

//--------------------------------------------------
// Subject2 と Subject3 を監視する
class Observer2 : public ObserverBase
{
public:

    Observer2() : ObserverBase() {}
    virtual ~Observer2() {}

    virtual void OnChangeSubject()
    {
        std::cout << "observer2" << std::endl;
    }
};

//--------------------------------------------------
class Subject1 : public SubjectBase
{
public:

    Subject1() : SubjectBase() {}
    virtual ~Subject1() {}

private:

    virtual bool Change_()
    {
        std::cout << "change subject1" << std::endl;
        return true;
    }
};

//--------------------------------------------------
class Subject2 : public SubjectBase
{
public:

    Subject2() : SubjectBase() {}
    virtual ~Subject2() {}

private:

    virtual bool Change_()
    {
        std::cout << "change subject2" << std::endl;
        return true;
    }
};

//--------------------------------------------------
class Subject3 : public SubjectBase
{
public:

    Subject3() : SubjectBase() {}
    virtual ~Subject3() {}

private:

    virtual bool Change_()
    {
        std::cout << "change subject3" << std::endl;
        return true;
    }
};

//--------------------------------------------------
// 実装例
void ExecExample()
{
    Subject1 sub1;
    Subject2 sub2;
    Subject3 sub3;

    Observer1* obs1 = new Observer1();
    Observer2* obs2 = new Observer2();

    // 監視者設定
    sub1.AddObserver(obs1);
    sub2.AddObserver(obs1);
    sub2.AddObserver(obs2);
    sub3.AddObserver(obs2);

    // 変更
    sub1.ChangeSubject();
    sub2.ChangeSubject();
    sub3.ChangeSubject();

    delete obs2;
    delete obs1;
}

} // namespace Observer

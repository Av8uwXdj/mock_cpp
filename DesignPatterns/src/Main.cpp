#include "CoR.cpp"

int main()
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

    delete chain2;
    delete chain1;
    return 0;
}
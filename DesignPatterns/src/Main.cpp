#include "CoR.cpp"

int main()
{
    Chain1* chain1 = new Chain1();
    Chain2* chain2 = new Chain2();
    Chain3* chain3 = new Chain3();

    // \’z
    chain1->SetNext(chain2)->SetNext(chain3);

    // ŽÀs
    int value = chain1->Request();

    // Œ‹‰Ê
    std::cout << "result = " << value << std::endl;

    delete chain2;
    delete chain1;
    return 0;
}
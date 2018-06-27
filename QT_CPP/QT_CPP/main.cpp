#include <QCoreApplication>
#include <iostream>
#include "mysharedptr.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MySharedPtr<int> foo1(new int{1});
    std::cout<<foo1.getRefCnt()<<std::endl;

    auto foo2 = foo1;
    std::cout<<foo2.getRefCnt()<<std::endl;

    foo2 = foo1;
    std::cout<<foo2.getRefCnt()<<std::endl;

    MySharedPtr<int> foo3(new int{2});
    foo3 = foo1;

    std::cout<<foo2.getRefCnt()<<std::endl;
    std::cout<< *foo2 <<std::endl;

    return a.exec();
}

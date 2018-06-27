#ifndef MYSHAREDPTR_H
#define MYSHAREDPTR_H
#include <iostream>
#include <sstream> //for std::stringstream
#include <string>  //for std::string

//Class template for my smart pointer
template <typename T>
class MySharedPtr{
public:
    MySharedPtr(T* obj_){
        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;
        std::cout<<ss.str()<<" ";
        std::cout<<"Default constructor."<<std::endl;

        pRefCnt=new unsigned int{1};
        pObj = obj_;
    }
    //Copy constructor: previously uninitialized.
    MySharedPtr(MySharedPtr<T> &ptr_){
        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;
        std::cout<<ss.str()<<" ";
        std::cout<<"Copy constructor."<<std::endl;

        pRefCnt = ptr_.pRefCnt;
        ++(*pRefCnt);
        pObj = ptr_.pObj;
    }
    //Assignment operator: replacement
    //The assignment operator reuturns an lvalue reference to avoid overhead in chain assignments,
    //such that objA = objB = objC works.
    MySharedPtr<T> & operator = (MySharedPtr<T> &ptr_){
        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;
        std::cout<<ss.str()<<" ";
        std::cout<<"Assignment constructor."<<std::endl;

        if(this == &ptr_) return *this;

        if(*pRefCnt>0) remove();

        pRefCnt = ptr_.pRefCnt;
        ++(*pRefCnt);
        pObj = ptr_.pObj;

        return *this;
    }
    ~MySharedPtr(){
        remove();
    }
    std::string getRefCnt(){
        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;
        ss << " reference counts: ";
        ss << *pRefCnt;
        return ss.str();
    }
    //Dereference
    //Prefix operator because there are not input parameters.
    T& operator * (){
        return *pObj;
    }
    //Mmeber access operator
    //Prefix operator
    //"drill-down behavior"???
    T* operator -> (){
        return pObj;
    }
private:
    T *pObj = nullptr;
    unsigned int *pRefCnt=nullptr;

    void remove(){
        --(*pRefCnt);
        if(*pRefCnt==0){
            const void * address = static_cast<const void*>(this);
            std::stringstream ss;
            ss << address;
            std::cout<<ss.str()<<" ";
            std::cout<<"Reference count is zero. Delete."<<std::endl;
            delete pRefCnt;
            delete pObj;
            pRefCnt = nullptr;
            pObj = nullptr;
        }
    }
};

#endif // MYSHAREDPTR_H

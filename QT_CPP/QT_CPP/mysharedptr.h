#ifndef MYSHAREDPTR_H
#define MYSHAREDPTR_H

//Class template for my smart pointer
template <typename T>
class MySharedPtr{
public:
    MySharedPtr(const T& obj_){
        ref_cnt = 1;
        pObj = new T(obj);
    }
    ~MySharedPtr(){
        --ref_cnt;
        if(!ref_cnt){
            delete pObj;
        }
    }
private:
    T *pObj;
    int ref_cnt;
};

#endif // MYSHAREDPTR_H

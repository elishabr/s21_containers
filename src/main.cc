#include <iostream>


struct Help{
    explicit Help(Expression *ptr = 0): ptrHelp_(ptr){
        if(ptrHelp_ != 0) counter_ = 1;
        else counter_ =0;
    }
    ~Help(){
        if(ptrHelp_ != 0) --counter_;
        if(counter_ == 0) delete ptrHelp_;
    }
    Expression *ptrHelp_;
    int counter_;
};

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0){
        if(ptr != 0) ptr_ = new Help(ptr);
        else ptr_ = 0;
    }
    ~SharedPtr(){
        delete ptr_;
        ptr_ =0;
    }
    SharedPtr(const SharedPtr &other){
        if(other.ptr_ != 0 && other.ptr_->ptrHelp_ != 0) ++(other.ptr_->counter_);
        ptr_ = other.ptr_;
    }
    SharedPtr& operator=(const SharedPtr &other){
        if(ptr_ != 0 && ptr_->ptrHelp_ != 0) --(ptr_->counter_);
        if(other.ptr_ != 0 && other.ptr_->ptrHelp_ != 0) ++(other.ptr_->counter_);
        delete ptr_;
        ptr_ = other.ptr_;
        return *this;
    }
    Expression* get() const{
        return ptr_->ptrHelp_;
    }
    void reset(Expression *ptr = 0){
       delete ptr_;
       if(ptr_ != 0)ptr_->ptrHelp_ = ptr;
    }
    Expression& operator*() const{
        return *(ptr_->ptrHelp_);
    }
    Expression* operator->() const{
        return ptr_->ptrHelp_;
    }
    private:
    Help *ptr_;
};

int main(){
    Expression* s=new Expression;
    SharedPtr ptr(s);
    *ptr = 2;
    std::cout << *ptr;
    SharedPtr ptr1(0);
    ptr1 = ptr;
    std::cout << *ptr1;
    return 0;
}
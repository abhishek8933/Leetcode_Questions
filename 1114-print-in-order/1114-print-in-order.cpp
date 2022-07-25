class Foo {
public:
    mutex m;
    condition_variable cv;
    int turn=0;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn =1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        
        // printSecond() outputs "second". Do not change or remove this line.
        while(turn!=1){
            cv.wait(lock);
        }
        printSecond();
        turn=2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
         unique_lock<mutex> lock(m);
        
        // printThird() outputs "third". Do not change or remove this line.
        while(turn!=2){
            cv.wait(lock);
        }
        printThird();
    }
};
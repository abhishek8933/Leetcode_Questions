class FooBar {
private:
    int n;

public:
    mutex m;
    condition_variable cv;
    int turn =1;
    // mutex m;
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock,[this]{return turn;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn=0;
            cv.notify_one();
        }
        
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
           cv.wait(lock,[this]{return !turn;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn=1;
            cv.notify_one();
        }
    }
};
class Singletonv1{
    private:
        static Singletonv1* instance;

        Singletonv1(){};
        ~Singletonv1(){};
        Singletonv1(const Singletonv1&);
        Singletonv1& operator=(const Singletonv1&);
        class Deletor {
	    public:
		    ~Deletor() {
			    if(Singletonv1::instance != nullptr)
				    delete Singletonv1::instance;
		    }
	    };
        static Deletor deletor;
	
    public:
        static Singletonv1* getinstance(){
            if(instance == nullptr){
                instance == new Singletonv1();
            }
            return instance;
        }
};
Singletonv1* Singletonv1::instance = nullptr;

class Singletonv2{
    private:
        Singletonv2(){};
        ~Singletonv2(){};
        Singletonv2(const Singletonv2&);
        Singletonv2& operator=(const Singletonv2&);

    public:
        static Singletonv2& getInstance(){
            static Singletonv2 instance;
            return instance;
        }
};
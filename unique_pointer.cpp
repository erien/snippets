#include <iostream>

// structure of sample object
struct Foo {
    Foo() { std::cout << "Foo constructor" << std::endl; }
    Foo(const Foo&) { std::cout << "Foo copy constructor" << std::endl; }
    Foo(Foo&&) { std::cout << "Foo move constructor" << std::endl; }
    ~Foo() { std::cout << "~Foo destructor" << std::endl; }
};

// structure of non-standard deleter
struct D {
    D() {};
    D(const D&) { std::cout << "D copy constructor" << std::endl; }
    D(D&) { std::cout << "D non-const copy constructor" << std::endl; }
    D(D&&) { std::cout << "D move constructor" << std::endl; }
    void operator()(Foo* p) const {
        std::cout << "D is deleting a Foo" << std::endl;
        delete p;
    };
};

int main()
{
    std::cout << "Example constructor" << std::endl;

    D d;
    {  // deleter type is a reference
        std::unique_ptr<Foo, D&> up3ref(new Foo, d); // up4ref holds a reference to d
    }
    std::cout << "-------------------" << std::endl;
    
    std::cout << "Example constructor" << std::endl;
    {
        std::unique_ptr<Foo> up5a(new Foo);
        std::unique_ptr<Foo> up5b(std::move(up5a)); // ownership transfer
    }
    std::cout << "-------------------" << std::endl;
    
    std::cout << "Example constructor" << std::endl;
    {
        std::unique_ptr<Foo, D&> up6a(new Foo, d); // D is a reference
        std::unique_ptr<Foo, D&> up6b(std::move(up6a)); // if deleter is not a reference, it will be copied
    }
}
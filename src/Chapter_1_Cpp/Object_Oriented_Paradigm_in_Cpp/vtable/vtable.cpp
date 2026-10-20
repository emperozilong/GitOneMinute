// vtable.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal speaks" << std::endl;
    }
    virtual void eat() {
        std::cout << "Animal eats" << std::endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks" << std::endl;
    }
    // 不重写eat()函数
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Cat meows" << std::endl;
    }
    void eat() override {
        std::cout << "Cat eats fish" << std::endl;
    }
};

int main()
{
    //多态：父类接口指针，指向了子类实现
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->speak();  // 输出: Dog barks
    animal2->speak();  // 输出: Cat meows
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include <iostream>
#include <string>

class __MyFunctor_lambda
{
public:
    // 2. 构造函数：初始化捕获来的变量
    __MyFunctor_lambda(int base, std::string& name)
        : _base(base), _name(name) // 注意：name_直接绑定到外部的name
    {
    }

// 3. 重载 operator()
// 因为Lambda使用了 'mutable'，所以这个函数不是 const 的！
// 返回类型也与Lambda声明一致
auto operator()(int multiplier) -> std::string {
        _base *= multiplier; // 修改的是成员变量 base_，不影响外部的base
        _name += " World";   // 修改的是绑定的外部 name
        return _name + " : " + std::to_string(_base);
    }

private:
    // 1. 捕获列表的变量成为成员变量
    int _base;          // 按值捕获 -> 普通成员
    std::string& _name; // 按引用捕获 -> 成员引用
};

int main() {
    int base = 100;
    std::string name = "Hello";

    //// 一个捕获了 base（值）和 name（引用）的Lambda
    //auto myLambda = [base, &name](int multiplier) mutable -> std::string {
    //    base *= multiplier; // 修改按值捕获的base的副本
    //    name += " World";   // 修改按引用捕获的name
    //    return name + " : " + std::to_string(base);
    //    };
    __MyFunctor_lambda myLambda(base, name);

    auto result = myLambda(2);
    std::cout << "Result: " << result << std::endl;
    std::cout << "External name: " << name << std::endl; // 外部name被修改了
    std::cout << "External base: " << base << std::endl; // 外部base未被修改

    return 0;
}
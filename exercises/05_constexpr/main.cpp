#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    const auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
/*
 * constexpr 知识点解析：
 * 
 * 1. constexpr 关键字
 *    - constexpr 用于声明可以在编译时求值的函数或变量
 *    - 编译时求值可以提高程序性能，因为计算结果直接嵌入到生成的代码中
 *    - constexpr 函数必须满足一系列要求，如只能包含一个 return 语句（C++14前）
 * 
 * 2. 编译时计算的限制
 *    - 编译器对 constexpr 的计算步骤有上限限制
 *    - 复杂的递归（如高阶斐波那契数）会超出这个限制
 *    - 错误信息 "constexpr evaluation hit maximum step limit" 表明超出了编译时计算的步骤限制
 * 
 * 3. 解决方案
 *    - 移除 constexpr，让计算在运行时进行
 *    - 对于斐波那契数列，可以使用更高效的算法（如矩阵快速幂）来减少计算步骤
 *    - 在 C++20 中，可以使用 consteval 强制函数只能在编译期执行
 * 
 * 4. constexpr vs const
 *    - const 仅表示变量不可修改
 *    - constexpr 不仅表示不可修改，还表示可以在编译时求值
 *    - constexpr 变量必须用常量表达式初始化
 * 
 * 5. 本例中的修改
 *    - 将 "constexpr auto ANS = fibonacci(ANS_N)" 改为 "const auto ANS = fibonacci(ANS_N)"
 *    - 这样 ANS 的计算会在运行时进行，而不是编译时
 *    - 虽然可以编译通过，但运行时计算 fibonacci(90) 会非常耗时，因为使用了低效的递归算法
 * 
 * 参考链接：
 * - C++ constexpr 说明: https://zh.cppreference.com/w/cpp/language/constexpr
 * - C++14 中的 constexpr 改进: https://en.cppreference.com/w/cpp/language/constexpr
 * - C++20 中的 consteval: https://en.cppreference.com/w/cpp/language/consteval
 */
#include "../include/Calculator.hpp"
#include <iostream>
#include <string>

int main() {
    Calculator calc;
    double num1, num2;
    char op;

    std::cout << "=== 简易计算器 ===" << std::endl;
    std::cout << "请输入运算式（例如：3 + 5）：";
    std::cin >> num1 >> op >> num2;

    try {
        double result;
        switch (op) {
            case '+': result = calc.add(num1, num2); break;
            case '-': result = calc.subtract(num1, num2); break;
            case '*': result = calc.multiply(num1, num2); break;
            case '/': result = calc.divide(num1, num2); break;
            default: throw std::invalid_argument("无效的运算符！");
        }
        std::cout << "结果：" << num1 << " " << op << " " << num2 << " = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "错误：" << e.what() << std::endl;
        return 1;
    }

    return 0;
}
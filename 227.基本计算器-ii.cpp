/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    bool isOperator(char c) {
            return (c == '+' || c == '-' || c == '*' || c == '/');// 判断字符是否为操作符
    }
    // 执行算术运算
    int performOperation(int operand1, int operand2, char op) {
        switch (op) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                return operand1 / operand2;
            default:
                return 0;
        }
    }
    // 获取操作符的优先级
    int getPrecedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else if (op == '*' || op == '/') {
            return 2;
        }
        return 0;  // 默认优先级为0
    }
    int calculate(string s) {
        // 计算表达式的值
        stack<int> operands;
        stack<char> operators;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                // 处理多位数字
                int num = 0;
                while (isdigit(c)) {
                    num = num * 10 + (c - '0');
                    c = s[++i];
                }
                operands.push(num);
            }
            if (isOperator(c)) {
                // 弹出优先级大于等于当前操作符的栈顶操作符，并进行运算
                while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                    int operand2 = operands.top();
                    operands.pop();

                    int operand1 = operands.top();
                    operands.pop();

                    char op = operators.top();
                    operators.pop();

                    int result = performOperation(operand1, operand2, op);
                    operands.push(result);
                }
                operators.push(c);
            }

            if (c == '(') {
                operators.push(c);
            }

            if (c == ')') {
                // 弹出栈顶操作符直到遇到左括号，并进行运算
                while (!operators.empty() && operators.top() != '(') {
                    int operand2 = operands.top();
                    operands.pop();

                    int operand1 = operands.top();
                    operands.pop();

                    char op = operators.top();
                    operators.pop();

                    int result = performOperation(operand1, operand2, op);
                    operands.push(result);
                }
                if (!operators.empty() && operators.top() == '(') {
                    operators.pop();  // 弹出左括号
                }
            }
        }

        // 执行剩余的运算
        while (!operators.empty()) {
            int operand2 = operands.top();
            operands.pop();

            int operand1 = operands.top();
            operands.pop();

            char op = operators.top();
            operators.pop();

            int result = performOperation(operand1, operand2, op);
            operands.push(result);
        }

        return operands.top();
        
    }

};
// @lc code=end


//
//  main.cpp
//  Shunting Yard Algorithm
//
//  Created by Deven Mithal on 7/1/19.
//  Copyright © 2019 Deven Mithal. All rights reserved.
//
// Shunting-yard algorithm implementation for addition, subtraction,
// division and multiplication.
// Exponentiation will be added later, so for the moment all operators under consideration
// are left-associative.

#include <iostream>
#include <stack>
#include <string>
#include <queue>

int rank(char op){
    if(op == '*' || op == '/'){
        return 1;
    } else if (op == '-' || op == '+'){
        return 0;
    } else {
        std::cerr << "Invalid Operator" << std::endl;
        return -1;
    }
}

int precedence(char firstOp, char secondOp){
    return rank(firstOp) - rank(secondOp);
}

void accumulate_number(float& current, char additional){
    current *= 10;
    current += (additional - '0');
}

float shunting_yard(std::string expression){
    std::stack<char> expression_stack;
    std::queue<char> output_queue;
    const std::string digits[] = {"0" , "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    //float current = 0;
    
    for(int i = 0; i < expression.length(); ++i ){
        if(expression[i] - 48 >= 0 && expression[i] - 48 <= 9){
            while(expression[i] - 48 >= 0 && expression[i] - 48 <= 9){
                output_queue.push(expression[i]);
            }
        } else if( (!expression_stack.empty()) && (precedence(expression[i], expression_stack.top()) > 0) ){
            expression_stack.push(expression[i]);
        }
    }
    
    // completing all the cases
    
    return 1;
}

void shunting_yard_wrapper(){
    std::string expressions[5] = {
        "5-4-3+2*7/7",
        "5-(4*2)+3*2/6+(3-2)",
        "2*(9/3*3+1)/2/2",
        "(17/(15+2)-3)/2*2",
        "2-3-4+(69/13)+((6-2)-3)*(6-(2-3))*(6-2-3)"
    };
    
    float results[5];
    results[0] = 5 - 4 - 3 + 2 * 7 / 7;
    results[1] = 5 - (4 * 2) + 3 * 2 / 6 + (3 - 2);
    results[2] = 2 * (9 / 3 * 3 + 1) / 2 / 2;
    results[3] = ( 17 / ( 15 + 2 ) - 3 ) / 2 * 2;
    results[4] = 2 - 3 - 4 + (69 / 13) + ((6 - 2) - 3) * (6 - (2 - 3)) * (6 - 2 - 3);
    
    for(std::string expression : expressions){
        shunting_yard(expression);
    }
}

int main(int argc, const char * argv[]) {
    shunting_yard_wrapper();
    std::cout << "Success" << std::endl;
}

/*
else if(expression[i] == '*' ||
        expression[i] == '/' ||
        expression[i] == '-' ||
        expression[i] == '+' ||
        expression[i] == '('){
    expression_stack.push(expression[i]);
    }
 */

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
    } else if(op == '('){
        return -1;
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

std::string queue_to_string(std::queue<char>& output_queue){
    std::string output_string = "";
    while(!output_queue.empty()){
        output_string += output_queue.front();
        output_queue.pop();
    }
    
    return output_string;
}

std::string infix_to_postfix(std::string expression){
    std::stack<char> expression_stack;
    std::queue<char> output_queue;
    const std::string digits[] = {"0" , "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    //float current = 0;
    
    for(int i = 0; i < expression.length(); ){
        if(expression[i] == '('){
            expression_stack.push(expression[i]);
            ++i; // std::cout << i << std::endl;
            
        } else if(expression[i] == ')'){
            
            while(expression_stack.top() != '('){
                output_queue.push(expression_stack.top());
                expression_stack.pop();
                // std::cout << i << std::endl;
            }
            
            expression_stack.pop();
            ++i;
            
        } else if(expression[i] - '0' >= 0 && expression[i] - '0' <= 9){
            
            while(expression[i] - '0' >= 0 && expression[i] - '0' <= 9){
                output_queue.push(expression[i]);
                ++i; // std::cout << i << std::endl;
            }
            
        } else if( ((!expression_stack.empty()) && (precedence(expression[i], expression_stack.top()) > 0)) || (expression_stack.empty()) ){
            //std::cout << expression[i] << std::endl;
            expression_stack.push(expression[i]);
            ++i; // std::cout << i << std::endl;
            
        } else if ( (!expression_stack.empty()) && (precedence(expression[i], expression_stack.top()) <= 0) ){
            
            while( (!expression_stack.empty()) && (precedence(expression[i], expression_stack.top()) <= 0) ){
                
                output_queue.push(expression_stack.top());
                expression_stack.pop();
                
            }
            
            expression_stack.push(expression[i]);
            ++i;
            //std::cout << i << std::endl;
            
        } else {
            std::cerr << "Invalid operator" << std::endl;
        }
    }
    
    while(!expression_stack.empty()){
        output_queue.push(expression_stack.top());
        expression_stack.pop();
    }
    
    // completing all the cases
    std::string output_string = queue_to_string(output_queue);
    return output_string;
}

float evaluate_binary_expression(float x, char op, float y){
    switch(op){
        case '+': return x + y;
            break;
        case '-': return x - y;
            break;
        case '/': return x / y;
            break;
        case '*': return x * y;
            break;
        default: throw -1;
            break;
    }
}


// for now, only evaluates expressions with single digit numbers
float postfix_eval(std::string expression){
    std::stack<float> num_stack;
    
    for(int i = 0; i < expression.length(); ){
        
        if(expression[i] - '0' >= 0 && expression[i] - '0' <= 9){
            
            while(expression[i] - '0' >= 0 && expression[i] - '0' <= 9){
                num_stack.push(expression[i] - '0');
                ++i; // std::cout << i << std::endl;
            }
            
        } else {
            
            float x = num_stack.top(); num_stack.pop();
            float y = num_stack.top(); num_stack.pop();
            num_stack.push(evaluate_binary_expression(x, expression[i], y));
            ++i;
            
        }
    }
    
    return num_stack.top();
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
    
    // Here
    
    //for(int i = 0; i < 5; i++){
    for(int i = 1; i < 2; ++i){
        std::string postfix = infix_to_postfix(expressions[i]);
        
        std::cout << postfix << std::endl;
        
        float value = postfix_eval(postfix);
        std::cout << "Value for expression " << i << " is " << (value == results[i]) << std::endl;
        std:: cout << value << " and actually " << results[i] << std::endl;
        
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

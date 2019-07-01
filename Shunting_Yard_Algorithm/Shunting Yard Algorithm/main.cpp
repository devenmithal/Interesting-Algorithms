//
//  main.cpp
//  Shunting Yard Algorithm
//
//  Created by Deven Mithal on 7/1/19.
//  Copyright © 2019 Deven Mithal. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void accumulate_number(float& current, char additional){
    current *= 10;
    current += (additional - '0');
}

float shunting_yard(string expression){
    stack<char> expression_stack;
    string digits[] = {"0" , "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    float current = 0;
    
    for(int i = 0; i < expression.length(); ++i ){
        if(expression[i] - 48 >= 0 && expression[i] - 48 <= 9){
            while(expression[i] - 48 >= 0 && expression[i] - 48 <= 9){
                accumulate_number(current, expression[i++]);
            }
        } else if(expression[i] == '*' ||
                  expression[i] == '/' ||
                  expression[i] == '-' ||
                  expression[i] == '+' ||
                  expression[i] == '('){
            expression_stack.push(expression[i]);
        }
    }
    
    
    
    return 1;
}

void shunting_yard_wrapper(){
    string expressions[5] = { "5-4-3+2*7/7",
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
    
    for(string expression : expressions){
        shunting_yard(expression);
    }
}

int main(int argc, const char * argv[]) {
    shunting_yard_wrapper();
}


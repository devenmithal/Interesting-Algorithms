//
//  main.cpp
//  Shunting Yard Algorithm
//
//  Created by Deven Mithal on 7/1/19.
//  Copyright © 2019 Deven Mithal. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

float shunting_yard(string expression){
    stack<string> expression_stack;
    
    
    
    
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


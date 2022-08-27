#include <iostream>
#include <stack>

std::stack<char> st;

int main(){
    
    return 0;
}

void P(int val){
    st.push(val);
}

void p(){
    st.pop();
}

void d(){
    st.push(st.top());
}

void plus(){
    int val1 = st.top();
    st.pop();
    int val2 = st.top();
    st.pop();
    st.push(val1 + val2);
}

void minus(){
    int val1 = st.top();
    st.pop();
    int val2 = st.top();
    st.pop();
    st.push(val2 - val1);
}

void r(char val[]){

}

void R(){
    int val;
    std::cin >> val;
    st.push(val);
}

void w(){
    
}

void W(){
    std::cout << st.top();
    st.pop();
}

void Z(){

}
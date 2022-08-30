#include <iostream>
#include <stack>
#include <string>

std::stack<int> st;

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

void r(){
    std::string str;
    std::cout << "Veuillez entrer un string: ";
    std::cin >> str;
    for (size_t i = str.length(); i > 0; i--)
    {
        st.push(str[i]);
    }
    st.push(str.length());
    std::cout << "Valeur ajoutée au stack" << std::endl;
}

void R(){
    int val;
    std::cout << "Veuillez entrer un nombre: ";
    std::cin >> val;
    std::cout << "Valeur ajoutée au stack" << std::endl;
    st.push(val);
}

void w(){
    int val = st.top();
    st.pop();
    for (size_t i = 0; i < val; i++)
    {
        char lettre = st.top();
        std::cout << lettre;
        st.pop();
    }
}

void W(){
    std::cout << st.top();
    st.pop();
}

void z(){
    int val1 = std::rand();
    int val2 = std::rand();
    st.push(val1);
    st.push(val2);
}

int main(){
    std::string str;
    std::cout << "Veuillez entrer votre commande: ";
    std::cin >> str;
    std::cout << "Calcul en cours..." << std::endl;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]) && str[i] != 'P')
        {
            switch (str[i])
            {
                case 'p':
                    p();
                    break;
                case 'd':
                    d();
                    break;
                case 'r':
                    r();
                    break;
                case 'R':
                    R();
                    break;
                case 'w':
                    w();
                    break;
                case 'W':
                    W();
                    break;
                case 'z':
                    z();
                    break;
                default:
                    break;
            }
        }
        else if(str[i] == 'P')
        {
            std::string toadd;
            i++;
            while(!isalpha(str[i]))
            {
                toadd += str[i];
                i++;
            }
            P(stoi(toadd));
            i--;
        }
        else
        {
            if (str[i] == '+')
            {
                plus();
            }
            else if (str[i] == '-')
            {
                minus();
            }
            else
            {
                std::cout << "Probleme dans la formule!!! " << str[i] << std::endl;
                break;
            }
        }
    }
    std::cout << "Fini!" << std::endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    std::string palavra = "carro";
    std::string intro;
    bool status = true;
    int len = palavra.length();

    for (int i = 0; i<len; i++){
        intro += "-";
    }
    std::cout << "          " << len << "  " <<intro << "\n";

    while (status == true){
        std::string guess;
        while (len != guess.length()){
            std::cout << "tentativa -->";
            std::cin >> guess;
        }
        std::string result;
        std::string copy = palavra;

        for (int i = 0; i<len; i++){
            if (guess[i] == copy[i]){
                result += "o";
                copy[i] = '#';
            }
            else{
                result += "-";
            }
        }
        for (int i = 0; i<len; i++){
            if (copy.find(guess[i]) != std::string::npos && result[i] != 'o'){
                copy[copy.find(guess[i])] = '#';
                result[i] = '*';
            }
        }
        std::cout << "             " << result << "\n\n";
        if (result.find("*") == std::string::npos && result.find("-") == std::string::npos){
            status = false;
        }
    }
    std::cout << "vitoria!! \n";
    return 0;
}

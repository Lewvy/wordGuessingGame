#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <random>
using namespace std;
int main(){
    srand(time(NULL));
    vector<string>storage{"ALIVE","SEDAN","GRIMY","PIXIE","OPERA","LEMON","BELIE",
    "SLEEK","LAYER","ABUSE","APPLE","BLOOD","BRAIN","BREAD","BREAK","BUYER","CHAIN",
    "CHESS","CHECK","CHIEF","CHEST","CAUSE","HORSE","HOUSE","MONEY","MONTH"};
    int index = rand() % storage.size();
    char word[6];
    for (int i = 0; i!= 5; i++ ){
        word[i] = storage[index][i];
    }
    int flag = 0,space = 0;
    // cout << word << endl;
    cout << "Enter a 5 letter word: ";
    char guess[6];
    for (int tries = 0; tries != 5; tries++){
        cin >> guess;
        for (int i = 0; i != sizeof(guess)/sizeof(guess[0]);i++){
            if (guess[i] >= 'a' && guess[i] <= 'z')
                guess [i] -= 32;
        }
        for (int i = 0; i <= 4; i++){
            for (int j = 0; j != 5; j++)
                if (guess[j] != word[j]){
                    flag = 1;
                }
                if (flag == 0){
                    cout << "YOU GUESSED THE CORRECT WORD" << endl;
                    return 0;
                }
            for (int j = 0; j <= 4; j++){
                if (guess[i] == word[j] && i == j){
                    cout << guess[i];
                }
                else if (guess[i] == word[j] && i != j){
                    char wrong_place = guess[i]+32;
                    cout << wrong_place;
                    break;
                }
                else
                    space = 1;
            }if (space == 1){
                cout << " ";
            }
            flag = 0;
            space = 0;
        }
            cout << endl;
           
    }
    
    cout << "THE CORRECT WORD WAS " << word << endl;
    return 0;    
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void draw_board(char* spaces);
void player_move(char* spaces, char player);
void computer_move(char* spaces, char computer);
bool check_winner(char* spaces, char player, char computer);
bool check_tie(char* spaces);

int main() {
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    draw_board(spaces);

    while(running) {
        player_move(spaces, player);
        draw_board(spaces);
        if(check_winner(spaces, player, computer)){
            running = false;
            break;
        }
        computer_move(spaces, computer);
        draw_board(spaces);
    }

    return EXIT_SUCCESS;
}

void draw_board(char* spaces) {

    cout << "   |   |    " <<  endl;
    cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << endl;
    cout << "___|___|___" << endl;
    cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " <<  endl;
    cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << endl;
    cout << "   |   |   " <<  endl;

}

void player_move(char *spaces, char player) {
    int number;
    do {
        cout << "Enter a spot to place a marker [0-0] : ";
        cin >> number;
        number -= 1;
        if(spaces[number] == ' ') {
            spaces[number] = player;
            draw_board(spaces);
        }
    }while(number < 0 || number > 8);
}

void computer_move(char *spaces, char computer) {
    srand(time(0));
    while(true) {
        int number = rand() % 9;
        if(spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}







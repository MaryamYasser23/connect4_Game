#include <iostream>
#include <cstdlib>  // for randome()
#include <ctime>        // for time()
#include <conio.h>     //  _kbhit()     _getch()
#include <windows.h>   // for PlaySound(...)

#define el "\n"
using namespace std;
const int ROWS = 8;
const int COLS = 8;
const char EMPTY = ' ';
const char PLAYER1_SYMBOL = 'X';
const char PLAYER2_SYMBOL = 'O';
const char COMPUTER_SYMBOL = 'O';

void welcome() {
    PlaySound(TEXT("C:\\Users\\ymari\\Desktop\\6CODERS\\sounds\\welcome.wav"), NULL, SND_ASYNC);
    cout << "\033[0;35m";// Purple
    cout << "\033[47m"; // White Background
    cout << "  ======================================================================================  " << el;
    cout << "||                                                                                      ||" << el;
    cout << "||                               WELCOME TO THE GAME OF                                 ||" << el;
    cout << "||                                                                             44       ||" << el;
    cout << "||      ####     ##     ## ##   ##  ## ##   ##   #####    ####  #########    44444      ||" << el;
    cout << "||    ##      ##   ##   ##  ##  ##  ##  ##  ##   ##     ##         ##        44444      ||" << el;
    cout << "||   ##      ##     ##  ##   ## ##  ##   ## ##   ##### ##          ##      444  444     ||" << el;
    cout << "||    ##      ##   ##   ##    ####  ##    ####   ##     ##         ##     44444444444   ||" << el;
    cout << "||      ####     ##     ##      ##  ##      ##   #####    ####     ##           44      ||" << el;
    cout << "||                                                                              44      ||" << el;
    cout << "||                             Press any key to continue                                ||" << el;
    cout << "||                                                                                      ||" << el;
    cout << "  ======================================================================================  " << el;
    cout << "\033[0m";//Text Reset
    cout << "\033[40m";//Background Reset
    system("pause");
}

int choice_mode() {
    int c;
    cout << "Are you 2 player ? Or you want play with Ai ? ENTER(1/2)" << el;
    cin >> c;
    while (c != 1 && c != 2) {
        cout << "Invalid. Please try again." << el;
        cin >> c;
    }
    return c;
}
int difculty_mode() {
    int c;
    cout << "Easey mode->1 'or' Hard mode->2 ? ENTER(1/2)" << el;
    cout << "\033[0;31m"; //RED
    cout << "On hard level you are allowed to play within 5 seconds"<< el;
    cout << "\033[0m";//Text Reset
    cin >> c;
    while (c != 1 && c != 2) {
        cout << "Invalid. Please try again." << el;
        cin >> c;
    }
    return c;
}
// ESRAA
void first_board(char board[ROWS][COLS]) { // only one call

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            board[row][col] = EMPTY;
        }
    }
}
// ESRAA
void print_board(const char board[ROWS][COLS]) { 
    system("cls");  // from CMD
    // clear screen after call function.
    cout << "\033[1;37m";//white
    cout << "\033[44m";//Blue Background
    
    cout << " 1 2 3 4 5 6 7 8 " << el;
    for (int row = 0; row < ROWS; ++row) {
        cout << "|";
        for (int col = 0; col < COLS; ++col) {
            if (board[row][col] == PLAYER1_SYMBOL){
                cout << "\033[1;91m"; //Bold High Intensity RED
                cout << "\033[44m";//Blue Background
            }
            else if (board[row][col] == PLAYER2_SYMBOL) {  
                cout << "\033[1;93m"; //Bold High Intensity Yellow
                cout << "\033[44m";//Blue Background
            }
            cout << board[row][col];
            cout << "\033[0;37m";//Blue
            cout << "\033[44m";//Blue Background
                cout << "|";
        }
        cout << el;
    }
    cout << "=================" << el;
    cout << "\033[0m";//Text Reset
}
// HANEEN
int player_turn1(char board[ROWS][COLS]) // easy mode
{
    cout << "Enter column number (1-8): ";
    while (1) {
        int x;     cin >> x;
        if ((x > 8) || (x < 1) || (board[0][x-1] != EMPTY)) {
            cout << "Invalid place, please enter a new column : " ;
        }
        else
            return x-1;
    }
}
// HANEEN
int player_turn2(char board[ROWS][COLS]) { // Hard mode
    cout << "Enter column number (1-8): ";
    time_t start = time(NULL); //start the clock
    int x = 0;
    while (true)
    {
        //check if the specified time limit has been exceeded
        if ((time(NULL) - start) >= 5)
        {
            // aktr mn 5 sec ->random
            srand(time(0));
            while (1)
            {
                int random = rand() % 8;
                if (board[0][random] == EMPTY)
                    return random;
            }
        }

        if (_kbhit()) // return true if Press any key and save it value as ASCI code 
        {
            x = _getch(); // value saved by _kbhit()

            // ascii code 1->49  2->50.....
            //cout << x - 48;
            if (((x - 48) > 8) || ((x - 48) < 1) || (board[0][x - 49] != EMPTY)) {
                cout << "Invalid place, please enter a new column : ";
            }
            else
                return x - 49;
            
        }
    }

}
// HANEEN
int pc_turn1(char board[ROWS][COLS])
{
    srand(time(0));
    while (1)
    {
        int random = rand() % 8;
        if (board[0][random] == EMPTY)
            return random;
    }
}
// FARAH
void drop_piece(char board[ROWS][COLS], int col, char symbol)
{
    for (int row = ROWS - 1; row >= 0; --row)
    {
        if (board[row][col] == EMPTY)
        {
            board[row][col] = symbol;
            break;
        }
    }
}
// MAI && NORHAN
bool check_win(const char board[ROWS][COLS], char symbol) {
    // check rows
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS - 3; ++col) {
            if (board[row][col] == symbol &&
                board[row][col + 1] == symbol &&
                board[row][col + 2] == symbol &&
                board[row][col + 3] == symbol) {
                return true;
            }
        }
    }

    // check columns
    for (int row = 0; row < ROWS - 3; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (board[row][col] == symbol &&
                board[row + 1][col] == symbol &&
                board[row + 2][col] == symbol &&
                board[row + 3][col] == symbol) {
                return true;
            }
        }
    }

    // check diagonal (top-left to bottom-right)
    for (int row = 0; row < ROWS - 3; ++row) {
        for (int col = 0; col < COLS - 3; ++col) {
            if (board[row][col] == symbol &&
                board[row + 1][col + 1] == symbol &&
                board[row + 2][col + 2] == symbol &&
                board[row + 3][col + 3] == symbol) {
                return true;
            }
        }
    }

    // check diagonal (top-right to bottom-left)
    for (int row = 0; row < ROWS - 3; ++row) {
        for (int col = 3; col < COLS; ++col) {
            if (board[row][col] == symbol &&
                board[row + 1][col - 1] == symbol &&
                board[row + 2][col - 2] == symbol &&
                board[row + 3][col - 3] == symbol) {
                return true;
            }
        }
    }
     return false;
}

// FARAH
bool check_draw(char board[ROWS][COLS]) {

    for (int col = 0; col < COLS; ++col) {
        if (board[0][col] == EMPTY) {
            return false;
        }
    }

    return true;
}

int restart(char board[ROWS][COLS]) {
    int restart;
    cout << "would you like to play again? ENTER(1->Yes/2->No)" << el;
    cin >> restart;
    while (restart != 1 && restart != 2) {
        cout << "Invalid. Please try again." << el;
        cin >> restart;
    }
    if (restart == 1)
    system("cls");
    if (restart == 2)
    {
        cout << "OH! We are waiting for you to come back again to play" << el;
         PlaySound(TEXT("sounds\\final.wav"), NULL, SND_ASYNC);
        system("pause");
    }
 
    return restart;
}

int main() {
    int again = 0;
    do {     
    char board[ROWS][COLS];
    char current_player = PLAYER1_SYMBOL;
    welcome();
    PlaySound(TEXT("sounds\\all.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    first_board(board);
    int choice = choice_mode();
    int difculty = difculty_mode();
    print_board(board);
        while (true)
        {
            int col;
            if (current_player == PLAYER1_SYMBOL) {
                if (difculty==1)
                col = player_turn1(board);
                else 
                    col = player_turn2(board);
            }
            else {
                if (choice == 1) {
                    if (difculty == 1)
                    col = player_turn1(board);
                    else
                        col = player_turn2(board);
                }
                else
                    col = pc_turn1(board);
                
            }
            // PlaySound(TEXT("sounds\\drop.wav"), NULL, SND_ASYNC);
            drop_piece(board, col, current_player);
            print_board(board);

            if (check_win(board, current_player)) {
               PlaySound(TEXT("sounds\\win.wav"), NULL, SND_ASYNC);
                cout << "\033[0;32m"; // green
                cout << current_player << " wins!" << el;
                cout << "\033[0m";//Text Reset
                again = restart(board);
                break;
            }

            if (check_draw(board)) {
                PlaySound(TEXT("sounds\\lose.wav"), NULL, SND_ASYNC);
                cout << "Game ended in a tie." << el;
                again = restart(board);
                break;
            }
            current_player = (current_player == PLAYER1_SYMBOL) ? PLAYER2_SYMBOL : PLAYER1_SYMBOL;  
        }
    } while (again != 2) ;
        
    return 0;
}

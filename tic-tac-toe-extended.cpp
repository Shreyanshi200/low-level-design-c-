#include <bits/stdc++.h>
using namespace std;
#include <vector>
// The Board class manages the game state, checking for wins, and displaying the board.
class Board {
public:
    Board(int size) : board(size, std::vector<char>(size, ' ')) {}

    void display() const {
        std::cout << "\n";
        for (const auto&row:board) {
            for (const auto&cell:row) {
                std::cout << (cell == ' ' ? '.' : cell) << ' ';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int row, int col, char player) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = player;
        return true;
    }

    bool checkWin(char player) const {
        for(int i=0;i<size;i++){
            if(checkRow(player,i) || checkCol(player,i)){
                return true;
            }
        }
        return checkDiagonals(player);
    }

    bool isFull() const {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

private:
    int size;
    std::vector<std::vector<char>> board;

    bool checkRow(char Player,int row)const{
        for(int col=0;col<size;col++){
            if(board[row][col]!=Player){
                return false;
            }
        }
        return true;
    }

    bool checkCol(char player, int col)const{
        for (int row = 0; row < size; ++row) {
            if (board[row][col] != player) {
                return false;
            }
        }
        return true;
    }
    bool checkDiagonals(char player)const {
        bool diag1 = true, diag2 = true;
        for (int i = 0; i < size; ++i) {
            if (board[i][i] != player) {
                diag1 = false;
            }
            if (board[i][size - i - 1] != player) {
                diag2 = false;
            }
        }
        return diag1 || diag2;
    }

};

// The Player class will handle player-related operations. In this basic version, it simply keeps track of the player's symbol.
class Player {
public:
    Player(char symbol) : symbol(symbol) {}

    char getSymbol() const {
        return symbol;
    }

private:
    char symbol;
};
// The Game class manages the game flow, including taking turns and checking for a win or a draw.

class Game {
    private:
    bool makeMove() {
        int row, col;
        std::cout << "Player " << players[currentplayerIndex]->getSymbol() << ", enter your move (row and column): ";
        std::cin >> row >> col;
        if (board.makeMove(row, col, players[currentplayerIndex]->getSymbol())) {
            return true;
        } else {
            std::cout << "Invalid move. Try again.\n";
            return false;
        }
    }

    void switchPlayer() {
        currentplayerIndex =(currentplayerIndex+1)%players.size();
    }

    Board board;
    vector<unique_ptr<Player>>players;
    size_t currentplayerIndex;
public:
    Game(int size,const vector<char>&playersymb) : board(size),players(),currentplayerIndex(0){
        for(char symbol:playersymb){
            players.push_back(make_unique<Player>(symbol));
        }
    }

    void play() {
        while (true) {
            board.display();
            if (makeMove()) {
                if (board.checkWin(players[currentplayerIndex]->getSymbol())) {
                    board.display();
                    std::cout << "Player " << players[currentplayerIndex]->getSymbol() << " wins!\n";
                    break;
                }
                if (board.isFull()) {
                    board.display();
                    std::cout << "It's a draw!\n";
                    break;
                }
                switchPlayer();
            }
        }
    }


};

int main() {
    int size;
    int numplayers;
    cout<<"Enter the board size:";
    cin>>size;
    cout<<"Enter the number of players: ";
    cin>>numplayers;
    vector<char>playersymb(numplayers);
    for(int i=0;i<numplayers;i++){
        cout << "Enter symbol for player " << (i + 1) << ": ";
        cin>>playersymb[i];
    }
    Game game(size,playersymb);
    game.play();
    return 0;
}

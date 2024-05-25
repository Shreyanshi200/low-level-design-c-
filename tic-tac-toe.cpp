#include <iostream>
#include <vector>
// The Board class manages the game state, checking for wins, and displaying the board.
class Board {
public:
    Board() : board(3, std::vector<char>(3, ' ')) {}

    void display() const {
        std::cout << "\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << (board[i][j] == ' ' ? '.' : board[i][j]) << ' ';
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
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true;
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }
        return false;
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
    std::vector<std::vector<char>> board;
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
public:
    Game() : board(), player1('X'), player2('O'), currentPlayer(&player1) {}

    void play() {
        while (true) {
            board.display();
            if (makeMove()) {
                if (board.checkWin(currentPlayer->getSymbol())) {
                    board.display();
                    std::cout << "Player " << currentPlayer->getSymbol() << " wins!\n";
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

private:
    bool makeMove() {
        int row, col;
        std::cout << "Player " << currentPlayer->getSymbol() << ", enter your move (row and column): ";
        std::cin >> row >> col;
        if (board.makeMove(row, col, currentPlayer->getSymbol())) {
            return true;
        } else {
            std::cout << "Invalid move. Try again.\n";
            return false;
        }
    }

    void switchPlayer() {
        if (currentPlayer == &player1) {
            currentPlayer = &player2;
        } else {
            currentPlayer = &player1;
        }
    }

    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;
};

int main() {
    Game game;
    game.play();
    return 0;
}

#include <iostream>
using namespace std;

// Kh?i t?o b?ng c? 3x3
char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

// Hi?n th? b?ng c?
void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Ki?m tra xem ng??i ch?i ?ã th?ng hay ch?a
bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

int main() {
    char currentPlayer = 'X';
    int row, col;

    cout << "Chao mung ban den voi co caro\n";
    cout << "Vd: 1 2 cho cot giua .\n";

    while (true) {
        drawBoard();
        cout << "Luot cua nguoi choi " << currentPlayer << ": ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Toa do tao lao.\n";
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(currentPlayer)) {
            cout << "Nguoi choi " << currentPlayer << " win!\n";
            break;
        }

        // ??i l??t ng??i ch?i
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    drawBoard();
    cout << "Cho choi ket thuc xin chuc mung!\n";

    return 0;
}

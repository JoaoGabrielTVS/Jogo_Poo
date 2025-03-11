#ifndef JOGO_WAR_KEYBOARD_H
#define JOGO_WAR_KEYBOARD_H

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

namespace KEY {
    const char A = 'a';
    const char D = 'd';
    const char S = 's';
    const char W = 'w';
    const char ENTER = 13;
}

class KeyBoard {
public:
    static void setInputMode(bool enable = true) {
        struct termios t{};
        tcgetattr(STDIN_FILENO, &t);  // Obtém as configurações do terminal

        if (enable) {
            t.c_lflag &= ~ICANON;  // Desativa o modo canônico
            t.c_lflag &= ~ECHO;    // Desativa a exibição da tecla pressionada
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
        } else {
            t.c_lflag |= ICANON;  // Reativa o modo canônico
            t.c_lflag |= ECHO;    // Reativa a exibição da tecla
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
        }
    }

    static bool readInput(char &input) {
        return read(STDIN_FILENO, &input, 1) == 1;
    }
};

#endif //JOGO_WAR_KEYBOARD_H
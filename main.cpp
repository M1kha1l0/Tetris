#include <iostream>
#include <string>
#include <vector>

void set_cursor(std::ostream& os, int x, int y) {
    os << "\033[" << x << ";" << y << "H";
}

class screen {
    private:
        int main_field[10][20] = { 0 };
        int next_shape_field[5][5] = { 0 };
        int score = 0;

    public:
        void set_score(int cur_score) {
            this->score = cur_score;
        }

        void set_main_field(int **data) {
            for(int i = 0;i < 20;i++) {
                for (int j = 0;j < 10;j++) {
                    this->main_field[i][j] = data[i][j];
                }
            }
        }

        void set_next_shape_field(int **data) {
            for(int i = 0;i < 5;i++) {
                for (int j = 0;j < 5;j++) {
                    this->next_shape_field[i][j] = data[i][j];
                }
            }
        }

        void print(std::string message = "\n") {
            system("clear");

            std::cout << "\n"
                      << "   Next figure:\n"
                      << "  .___________.\n";
            for (int i = 0;i < 5;i++) {
                std::cout << "  |";
                for (int j = 0;j < 5;j++) {
                    if (this->next_shape_field[i][j] == 1) std::cout << "[]";
                    else std::cout << " .";
                }
                std::cout << " |\n";
            }
            std::cout << "  '-----------'\n\n"
                      << "    Score:\n"
                      << "    " << this->score;

            set_cursor(std::cout, 1, 21);
            std::cout << ".______________________.";
            for (int i = 0;i < 20;i++) {
                set_cursor(std::cout, i+2, 21);
                std::cout << "| ";
                for (int j = 0;j < 10;j++) {
                    if (this->main_field[i][j] == 1) std::cout << "[]";
                    else std::cout << " .";
                }
                std::cout << " |";
            }
            set_cursor(std::cout, 22, 21);
            std::cout << "'----------------------'\n";
            std::cout << message;
        }
};
/*
class figure {
    virtual void rotate();
};

class I_shape : public figure {
    private:
        int x1, x2;
        int y1, y2;

    public:
        void rotate() {

        }
};

class J_shape : public figure {
    private:
        int x1, x2;
        int y1, y2;

    public:
        void rotate() {
            
        }
};

class L_shape : public figure {
    private:
        int x1, x2;
        int y1, y2;

    public:
        void rotate() {

        }
};

class O_shape : public figure {
    private:
        int x1, x2;
        int y1, y2;

    public:
        void rotate() {
            
        }
};

class Z_shape : public figure {
    private:
        int x1, x2;
        int y1, y2;

    public:
        void rotate() {

        }
};

class T_shape : public figure {
    private:
        int x1, x2;
        int y1, y2;

    public:
        void rotate() {
            
        }
};

class S_shape : public figure {
    private:
        int x1, x2;
        int y1, y2;

    public:
        void rotate() {

        }
};

class I_shape : public figure {
    private:
        int x1, x2;
        int y1, y2;

    public:
        void rotate() {
            
        }
};
*/

int main() {
    screen scr;
    scr.print();
    return 0;
}
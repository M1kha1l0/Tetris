#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void set_cursor(std::ostream& os, int x, int y) {
    os << "\033[" << x << ";" << y << "H";
}

class Logger {
    public:
        void log(std::string message) {
            std::ofstream log("main_log.txt");
            log << message + "\n";
        }

        void log(int a, std::string message = "") {
            std::ofstream log("main_log.txt");
            log << a << " " + message + "\n";
        }

        void log(int a, int b, std::string message = "") {
            std::ofstream log("main_log.txt");
            log << a << " " << b << " " + message + "\n";
        }

        void log(int a, int b, int c, std::string message = "") {
            std::ofstream log("main_log.txt");
            log << a << " " << b << " " << c << " " + message + "\n";
        }

        void log(int a, int b, int c, int d, std::string message = "") {
            std::ofstream log("main_log.txt");
            log << a << " " << b << " " << c << " " << d << " " + message + "\n";
        }
        
        void log(int main_field[10][20], int next_shape_field[5][5]) {
            std::ofstream log("screen_log.txt");
            for(int i = 0;i < 10;i++) {
                for(int j = 0;j < 20;j++) {
                    log << main_field[i][j] << " ";
                }

                if (i < 5) {
                    log << " | ";
                    for (int j = 0;j < 5;j++) {
                        log << next_shape_field[i][j] << " ";
                    }
                }
            }
            log << "\n\n";
        }
};

class screen {
    private:
        int main_field[10][20] = { 0 };
        int next_shape_field[5][5] = { 0 };
        int score = 0;
        Logger L;

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
            L.log(this->main_field, this->next_shape_field);

            std::cout << "\n"
                      << "   Next shape:\n"
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

        void post_shape(shape s) {

        }
};

class shape {
    public:
        virtual void set(int x1, int y1, int x2, int y2);       /* set shape coord */
        virtual void get(int &x1, int &y1, int &x2, int &y2);   /* get shape coord */
        virtual void rotate();
        virtual void move_left();
        virtual void move_right();
        virtual void move_down();
    protected:
        Logger L;
};

class O_shape : public shape {
    private:
        int x1, x2;
        int y1, y2;
        bool is_horizontal = true;

    public:
        void set(int x1, int y1, int x2, int y2) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void get(int &x1, int &y1, int &x2, int &y2) {
            x1 = this->x1;
            y1 = this->y1;
            x2 = this->x2;
            y2 = this->y2;
        }

        void rotate() {
            
        }

        void move_left() {
            this->y1--;
            this->y2--;
        }

        void move_right() {
            this->y1++;
            this->y2++;
        }

        void move_down() {
            this->x1--;
            this->x2--;
        }
};

class I_shape : public shape {
    private:
        int x1, x2;
        int y1, y2;
        bool is_horizontal = false;

    public:
        void set(int x1, int y1, int x2, int y2) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void get(int &x1, int &y1, int &x2, int &y2) {
            x1 = this->x1;
            y1 = this->y1;
            x2 = this->x2;
            y2 = this->y2;
        }

        void rotate() {
            
        }

        void move_left() {
            this->y1--;
            this->y2--;
        }

        void move_right() {
            this->y1++;
            this->y2++;
        }

        void move_down() {
            this->x1--;
            this->x2--;
        }
};

class S_shape : public shape {
    private:
        int x1, x2;
        int y1, y2;
        bool is_horizontal = true;

    public:
        void set(int x1, int y1, int x2, int y2) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void get(int &x1, int &y1, int &x2, int &y2) {
            x1 = this->x1;
            y1 = this->y1;
            x2 = this->x2;
            y2 = this->y2;
        }

        void rotate() {
            
        }

        void move_left() {
            this->y1--;
            this->y2--;
        }

        void move_right() {
            this->y1++;
            this->y2++;
        }

        void move_down() {
            this->x1--;
            this->x2--;
        }
};

class Z_shape : public shape {
    private:
        int x1, x2;
        int y1, y2;
        bool is_horizontal = true;

    public:
        void set(int x1, int y1, int x2, int y2) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void get(int &x1, int &y1, int &x2, int &y2) {
            x1 = this->x1;
            y1 = this->y1;
            x2 = this->x2;
            y2 = this->y2;
        }

        void rotate() {
            
        }

        void move_left() {
            this->y1--;
            this->y2--;
        }

        void move_right() {
            this->y1++;
            this->y2++;
        }

        void move_down() {
            this->x1--;
            this->x2--;
        }
};

class L_shape : public shape {
    private:
        int x1, x2;
        int y1, y2;
        bool is_horizontal = false;

    public:
        void set(int x1, int y1, int x2, int y2) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void get(int &x1, int &y1, int &x2, int &y2) {
            x1 = this->x1;
            y1 = this->y1;
            x2 = this->x2;
            y2 = this->y2;
        }

        void rotate() {
            
        }

        void move_left() {
            this->y1--;
            this->y2--;
        }

        void move_right() {
            this->y1++;
            this->y2++;
        }

        void move_down() {
            this->x1--;
            this->x2--;
        }
};

class J_shape : public shape {
    private:
        int x1, x2;
        int y1, y2;
        bool is_horizontal = false;

    public:
        void set(int x1, int y1, int x2, int y2) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void get(int &x1, int &y1, int &x2, int &y2) {
            x1 = this->x1;
            y1 = this->y1;
            x2 = this->x2;
            y2 = this->y2;
        }

        void rotate() {
            
        }

        void move_left() {
            this->y1--;
            this->y2--;
        }

        void move_right() {
            this->y1++;
            this->y2++;
        }

        void move_down() {
            this->x1--;
            this->x2--;
        }
};

class T_shape : public shape {
    private:
        int x1, x2;
        int y1, y2;
        bool is_horizontal = true;

    public:
        void set(int x1, int y1, int x2, int y2) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void get(int &x1, int &y1, int &x2, int &y2) {
            x1 = this->x1;
            y1 = this->y1;
            x2 = this->x2;
            y2 = this->y2;
        }

        void rotate() {
            
        }

        void move_left() {
            this->y1--;
            this->y2--;
        }

        void move_right() {
            this->y1++;
            this->y2++;
        }

        void move_down() {
            this->x1--;
            this->x2--;
        }
};


int main() {
    screen scr;
    scr.print();
    return 0;
}
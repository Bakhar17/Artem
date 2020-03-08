#include <iostream>
#include <Windows.h>
#include <conio.h>

class Game
{
public:
	Game(size_t x, size_t y) : x_(x), y_(x){
		
	};
	void Print() {
		for (size_t i = 0; i < x_; i++){
			std::cout << "\n";
			for (size_t j = 0; j < y_; j++) {
				std::cout << "  ";
			}
		}
		std::cout << "5";
	}
	void Move() {
		char c = _getch();
		if (c == 'a'){
			y_ -= 1;
		}
		if (c == 'd') {
			y_ += 1;
		}
		if (c == 'w') {
			x_ -= 1;
		}
		if (c == 's') {
			x_ += 1;
		}

	}

private:
	size_t x_;
	size_t y_;
};


int main() {
	Game game(5, 5);
	bool is_running = true;
	while (is_running) {
		system("cls");
		game.Print();
		game.Move();
	}
}
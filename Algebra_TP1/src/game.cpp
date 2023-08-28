#include "game.h"

#include <iostream>

#include "level.h"
#include "program_manager.h"

using namespace std;

namespace Game {

	static void draw();

	void draw() {
		BeginDrawing();
			ClearBackground({ 0, 10, 0 });
			DrawText("[Q] para entrar en modo editor.", 10, 10, 20, RAYWHITE);
			DrawText("[ESC] para cerrar el programa.", 10, 40, 20, RAYWHITE);
			Level::draw();

			Level::checkCollisions(GetMousePosition()) ? DrawCircleV(GetMousePosition(), 20, GREEN) : DrawCircleV(GetMousePosition(), 20, RED);
		EndDrawing();
	}

	// Public
	void update() {
		if (IsKeyPressed(KEY_Q)) {
			Program::setState(Program::ProgramState::DRAW);
		}

		draw();
	}

	void init() {
		DisableCursor();
	}
}
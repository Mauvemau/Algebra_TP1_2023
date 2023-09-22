#include "game.h"

#include <iostream>

#include "level.h"
#include "program_manager.h"

using namespace std;

namespace Game {
	struct Player {
		Vector2 position;
		float speed;
		float size;
	};

	Player player;

	static void draw();
	static void handleControls();

	void draw() {
		BeginDrawing();
			ClearBackground({ 0, 10, 0 });
			DrawText("[WASD] para controlar al jugador.", 10, 10, 20, RAYWHITE);
			DrawText("[Q] para entrar en modo editor.", 10, 40, 20, RAYWHITE);
			DrawText("[ESC] para cerrar el programa.", 10, 70, 20, RAYWHITE);
			Level::draw();

			Level::checkCollisions(player.position) ? DrawCircleV(player.position, player.size, GREEN) : DrawCircleV(player.position, player.size, RED);
		EndDrawing();
	}

	void handleControls() {
		if (IsKeyPressed(KEY_Q)) {
			Program::setState(Program::ProgramState::DRAW);
		}
		// Player Controls
		if (IsKeyDown(KEY_W)) {
			player.position.y -= GetFrameTime() * player.speed;
		}
		if (IsKeyDown(KEY_A)) {
			player.position.x -= GetFrameTime() * player.speed;
		}
		if (IsKeyDown(KEY_S)) {
			player.position.y += GetFrameTime() * player.speed;
		}
		if (IsKeyDown(KEY_D)) {
			player.position.x += GetFrameTime() * player.speed;
		}
	}

	// Public
	void update() {
		handleControls();

		draw();
	}

	void init() {
		DisableCursor();
		player.position = { (GetScreenWidth() * .5f), (GetScreenHeight() * .5f) };
		player.speed = 250.0f;
		player.size = 10.0f;
	}
}
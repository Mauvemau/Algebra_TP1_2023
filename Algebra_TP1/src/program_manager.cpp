#include "program_manager.h"

#include "raylib.h"

#include "level_editor.h"
#include "game.h"

namespace Program {
	// Private
	static const int screenWidth = 1024;
	static const int screenHeight = 768;

	static bool programShouldClose;

	static ProgramState currentState;

	static void initState(ProgramState state);
	static void update();
	static void uninit();
	static void init();

	void initState(ProgramState state) {
		switch (state)
		{
		case ProgramState::DRAW:
			Editor::init();
			break;
		case ProgramState::PLAY:
			Game::init();
			break;
		default:
			break;
		}
	}

	void update() {
		while (!WindowShouldClose()) {
			switch (currentState)
			{
			case ProgramState::DRAW:
				Editor::update();
				break;
			case ProgramState::PLAY:
				Game::update();
				break;
			default:
				break;
			}
		}
	}

	void uninit() {
		CloseWindow();
	}

	void init() {
		programShouldClose = false;
		InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), TextFormat("Algebra TP1 (Campos - Molina Jalabert - Camacho - Salazar)"));
		SetTargetFPS(60);
		setState(ProgramState::DRAW);
	}

	// Public
	void setState(ProgramState state) {
		initState(state);
		currentState = state;
	}

	void close() {
		programShouldClose = true;
	}

	void start() {
		init();
		update();
		uninit();
	}
}
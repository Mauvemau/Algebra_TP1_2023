#include "program_manager.h"

#include "raylib.h"

namespace Program {
	// Private
	static const int screenWidth = 1024;
	static const int screenHeight = 768;

	static bool programShouldClose;

	static ProgramState currentState;

	static void inputController();
	static void updateDraw();
	static void updatePlay();
	static void initState(ProgramState state);
	static void update();
	static void uninit();
	static void init();

	void inputController() {
		bool switcher = static_cast<bool>(currentState);
		if (IsKeyPressed(KEY_Q)) {
			currentState = static_cast<ProgramState>(!switcher);
		}
	}

	void updateDraw() {
		inputController();
		BeginDrawing();
			ClearBackground(BLACK);
			DrawText("Drawing!", 420, 350, 40, BLUE);
		EndDrawing();
	}

	void updatePlay() {
		inputController();
		BeginDrawing();
			ClearBackground(BLACK);
			DrawText("Playing!", 420, 350, 40, GREEN);
		EndDrawing();
	}

	void initState(ProgramState state) {
		switch (state)
		{
		case ProgramState::DRAW:
			break;
		case ProgramState::PLAY:
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
				updateDraw();
				break;
			case ProgramState::PLAY:
				updatePlay();
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
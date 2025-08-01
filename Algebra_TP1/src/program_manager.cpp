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

	static void InitState(ProgramState state);
	static void Update();
	static void Uninit();
	static void Init();

	void InitState(ProgramState state) {
		switch (state)
		{
		case ProgramState::DRAW:
			Editor::Init();
			break;
		case ProgramState::PLAY:
			Game::Init();
			break;
		default:
			break;
		}
	}

	void Update() {
		while (!WindowShouldClose()) {
			switch (currentState)
			{
			case ProgramState::DRAW:
				Editor::Update();
				break;
			case ProgramState::PLAY:
				Game::Update();
				break;
			default:
				break;
			}
		}
	}

	void Uninit() {
		CloseWindow();
	}

	void Init() {
		programShouldClose = false;
		InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), TextFormat("Algebra TP1 (Campos - Molina Jalabert - Camacho - Salazar)"));
		SetTargetFPS(60);
		SetState(ProgramState::DRAW);
	}

	// Public
	void SetState(ProgramState state) {
		InitState(state);
		currentState = state;
	}

	void Close() {
		programShouldClose = true;
	}

	void Start() {
		Init();
		Update();
		Uninit();
	}
}
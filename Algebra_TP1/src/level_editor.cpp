#include "level_editor.h"

#include "raylib.h"
#include <vector>
#include <iostream>

#include "level.h"
#include "program_manager.h"

using namespace std;

namespace Editor {

    vector<Vector2> currentShape; // Almacenamiento de l�neas dibujadas

    static void Draw();
    static void HandleControls();

    void Draw() {
        BeginDrawing();
            ClearBackground(BLACK);
            Level::Draw();
            DrawText("[Click Derecho] para colocar un vertice.", 10, 10, 20, RAYWHITE);
            DrawText("[Click Izquierdo] para finalizar la forma.", 10, 40, 20, RAYWHITE);
            DrawText("[B] para borrar la forma actual.", 10, 70, 20, RAYWHITE);
            DrawText("[C] para borrar todo.", 10, 100, 20, RAYWHITE);
            DrawText("[Q] para entrar en modo juego.", 10, 130, 20, RAYWHITE);
            DrawText("[ESC] para cerrar el programa.", 10, 160, 20, RAYWHITE);
            
            for (unsigned int i = 0; i < currentShape.size(); i++)
            {
                if (currentShape.size() > 1  && i < currentShape.size() - 1) {
                    DrawLineV(currentShape[i], currentShape[i + 1], BLUE);
                }
            }
            if (currentShape.size() > 0) {
                DrawLineV(currentShape.back(), GetMousePosition(), GREEN);
            }
        EndDrawing();
    }

    void HandleControls() {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentShape.push_back(GetMousePosition());
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            if (currentShape.size() > 2) {
                Level::AddShape(currentShape);
                currentShape.clear();
            }
        }
        if (IsKeyPressed(KEY_B)) {
            currentShape.clear();
        }
        if (IsKeyPressed(KEY_C)) {
            Level::Wipe();
        }
        if (IsKeyPressed(KEY_Q)) {
            Program::SetState(Program::ProgramState::PLAY);
        }
    }

    // Public
    void Update() {
        HandleControls();

        Draw();
    }

    void Init() {
        currentShape.clear();
        EnableCursor();
    }
}
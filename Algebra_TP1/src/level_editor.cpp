#include "level_editor.h"

#include "raylib.h"
#include <vector>
#include <iostream>

#include "level.h"
#include "program_manager.h"

using namespace std;

namespace Editor {

    vector<Vector2> currentShape; // Almacenamiento de líneas dibujadas

    static void draw();
    static void handleControls();

    void draw() {
        BeginDrawing();
            ClearBackground(BLACK);
            Level::draw();
            DrawText("[Click Derecho] para colocar un vertice.", 10, 10, 20, RAYWHITE);
            DrawText("[Click Izquierdo] para finalizar la forma.", 10, 40, 20, RAYWHITE);
            DrawText("[B] para borrar la forma actual.", 10, 70, 20, RAYWHITE);
            DrawText("[C] para borrar todo.", 10, 100, 20, RAYWHITE);
            DrawText("[Q] para entrar en modo juego.", 10, 130, 20, RAYWHITE);
            
            for (int i = 0; i < currentShape.size(); i++)
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

    void handleControls() {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentShape.push_back(GetMousePosition());
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            Level::addShape(currentShape);
            currentShape.clear();
        }
        if (IsKeyPressed(KEY_B)) {
            currentShape.clear();
        }
        if (IsKeyPressed(KEY_C)) {
            Level::wipe();
        }
        if (IsKeyPressed(KEY_Q)) {
            Program::setState(Program::ProgramState::PLAY);
        }
    }

    // Public
    void update() {
        handleControls();

        draw();
    }

    void init() {
        currentShape.clear();
        EnableCursor();
    }
}
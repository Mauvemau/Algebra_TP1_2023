#include "raylib.h"
#include <vector>

void drawingLines()
{
   
    std::vector<Vector2> lines; // Almacenamiento de líneas dibujadas
    Vector2 startLinePoint = { -100, -100 };
    Vector2 endLinePoint = { -100, -100 };
    bool drawing = false;

    
        // Update
        //----------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            startLinePoint = GetMousePosition();
            endLinePoint = startLinePoint; // Reset the end point to the starting point
            drawing = true;
        }
        else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            endLinePoint = GetMousePosition();
        }
        else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            drawing = false;
            lines.push_back(startLinePoint); // Almacena el inicio de la línea
            lines.push_back(endLinePoint);   // Almacena el final de la línea
        }

        if (IsKeyPressed(KEY_B))
        {
            lines.clear(); // Borra todas las líneas cuando se presiona la tecla "B"
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Manten el mouse para dibujar, presiona la tecla b para borrar", 10, 10, 20, DARKGRAY);

        // Dibuja las líneas guardadas
        for (size_t i = 0; i < lines.size(); i += 2)
        {
            DrawLineV(lines[i], lines[i + 1], RED);
        }

        if (drawing)
        {
            DrawLineV(startLinePoint, endLinePoint, RED);
        }

}
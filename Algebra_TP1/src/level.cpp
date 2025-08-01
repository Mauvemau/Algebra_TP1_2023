#include "level.h"

#include <list>

#include "collision_manager.h"

namespace Level {
	vector<vector<Vector2>> shapes;

	static void DrawShape(vector<Vector2> shape);

	void DrawShape(vector<Vector2> shape) {
		for (int i = 0; i < static_cast<int>(shape.size()); i++)
		{
			if (i < static_cast<int>(shape.size()) - 1) {
				DrawLineV(shape[i], shape[i + 1], ORANGE);
			}
		}
		DrawLineV(shape.back(), shape.front(), ORANGE);
	}

	// Public
	bool CheckCollisions(Vector2 playerPosition) {
		bool colliding = false;
		for (int i = 0; i < static_cast<int>(shapes.size()); i++) {
			if (Collision::PointInPolygonWinding(playerPosition, shapes[i])) {
				colliding = true;
			}
		}
		return colliding;
	}

	void AddShape(vector<Vector2> shape) {
		shapes.push_back(shape);
	}

	void Wipe() {
		shapes.clear();
	}

	void Draw() {
		if (!shapes.empty()) {
			for (int i = 0; i < static_cast<int>(shapes.size()); i++) {
				DrawShape(shapes[i]);
			}
		}
	}
}

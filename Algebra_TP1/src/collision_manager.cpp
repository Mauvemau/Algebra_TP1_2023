#include "collision_manager.h"

namespace Collision {

    // Fuente: http://jeffreythompson.org/collision-detection/poly-point.php 
    bool pointPolygon(Vector2 point, vector<Vector2> poly) {
        bool collision = false;
        // go through each of the vertices, plus
        // the next vertex in the list
        int next = 0;
        for (int current = 0; current < poly.size(); current++) {
            // get next vertex in list
            // if we've hit the end, wrap around to 0
            next = current + 1;
            if (next == poly.size()) next = 0;

            // get the PVectors at our current position
            // this makes our if statement a little cleaner
            Vector2 vc = poly[current];    // c for "current"
            Vector2 vn = poly[next];       // n for "next"

            // compare position, flip 'collision' variable
            // back and forth
            if (((vc.y >= point.y && vn.y < point.y) || (vc.y < point.y && vn.y >= point.y)) &&
                (point.x < (vn.x - vc.x) * (point.y - vc.y) / (vn.y - vc.y) + vc.x)) {
                collision = !collision;
            }
        }
        return collision;
    }

}
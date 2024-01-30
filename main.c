#include "raylib.h"
#include "src/player.h"

#define WIDTH 1000
#define HEIGHT 1000
#define TITLE "VSLike"

int main() {
    Character Bob = {
        .size = CH_SIZE(1, 20, 40),
        .ha = CH_HA(100,10),
        .speed = 2.0
    };

    InitWindow(WIDTH, HEIGHT, TITLE);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            

            DrawText(debug_buf, WIDTH/3, HEIGHT/2, 14, BLACK);
        EndDrawing();
    }
    

    return 0;
}
#include "raylib.h"
#include <stdio.h>
#include "src/player.h"

#define WIDTH 500
#define HEIGHT 500
#define TITLE "Game"

char debug_buf[32];

int main() {
    printf("Hellope");
    InitWindow(WIDTH, HEIGHT, TITLE);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            int err = sprintf(debug_buf, "Health: %i\nArmor: %i\n", Player_Health, Player_Armor);
            if (err < 0) return 1;

            DrawText(debug_buf, WIDTH/3, HEIGHT/2, 14, BLACK);
        EndDrawing();
    }
    
}
#include "raylib.h"
#include "raymath.h"

int main(void){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight,  "Moviento 2D");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2};

    SetTargetFPS(60);

    float speed = 300.0f;
    Vector2 velocity = {0.0f, 0.0f};
    Vector2 direction = {0.0f, 0.0f};

    // Main game loop
    while (!WindowShouldClose()){ // Close with button or ESC key
        // Update
        direction = (Vector2){IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT), IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)};
        direction = Vector2Normalize(direction);

        velocity = (Vector2){direction.x * speed, direction.y * speed};

        ballPosition = (Vector2){ballPosition.x + velocity.x * GetFrameTime(), ballPosition.y + velocity.y * GetFrameTime()};


        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPosition, 50, MAROON);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
}

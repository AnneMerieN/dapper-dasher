#include <raylib.h>


int main() {
    
    // Window Dimensions
    const int windowWidth = 512;
    const int windowHeight = 380;

    // Call function that makes window pop-up
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Start a new frame
        BeginDrawing();
        ClearBackground(WHITE);

        // End the frame and present the new content
        EndDrawing(); 

    }
    
    CloseWindow();
}
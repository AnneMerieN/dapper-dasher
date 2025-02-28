#include <raylib.h>


int main() {
    
    // Window Dimensions
    const int windowWidth = 512;
    const int windowHeight = 380;

    // Call function that makes window pop-up
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    // Rectangle dimensions
    const int width = 50;
    const int height = 80;

    int posY = windowHeight - height; // Starts on the ground
    int velocity = 0; // Initial velocity (not moving)
    const int jumpForce = -15; // How high the jump goes (negative moves up)
    const int gravity = 1; // Gravity pulls the character back down
    bool isJumping = false; // Track whether the user is pressing the space key

    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        // Start a new frame
        BeginDrawing();
        ClearBackground(WHITE);

        // Perform ground check
        if(posY >= windowHeight - height) {
            // Rectangle is on the ground
            velocity = 0;
        } else {
            // Apply gravity
            velocity = velocity + gravity;
        }

        if(IsKeyPressed(KEY_SPACE)) {
            velocity = velocity - 10;
        }


        posY = posY + velocity;
        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        // End the frame and present the new content
        EndDrawing(); 

    }

    CloseWindow();
}
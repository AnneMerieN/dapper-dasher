/* UNDERSTANDING GAME MOVEMENT
    - velocity: speed and direction of movement
    - acceleration: change in velocity over time
    - gravity: constant acceleration pulling downward
*/

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

    int posY = windowHeight - height; // Rectangle starts at bottom of window
    int velocity = 0; // Initial velocity (not moving)
    const int jumpForce = -22; // Controls how high the jump is
    const int gravity = 1; // Makes the character fall
    bool isJumping = false; // Track whether the user is pressing the space key
    bool isInAir{};
    

    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        // Start a new frame
        BeginDrawing();
        ClearBackground(WHITE);

        // Perform ground check (Checks if rectangle has reached or is below the ground level)
        if(posY >= windowHeight - height) {
            // Rectangle is on the ground
            velocity = 0;
            isInAir = false;
        } else {
            // Only apply gravity when rectangle is in the air
            velocity = velocity + gravity;
            isInAir = true;
        }

        // Rectangle jumps when space is pressed (Subtracting from velocity moves the character up)
        if(IsKeyPressed(KEY_SPACE) && !isInAir) {
            velocity = velocity + jumpForce;
        }


        posY = posY + velocity;
        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        // End the frame and present the new content
        EndDrawing(); 

    }

    CloseWindow();
}
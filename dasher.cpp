/* UNDERSTANDING GAME MOVEMENT
    - velocity: speed and direction of movement
    - acceleration: change in velocity over time
    - gravity: constant acceleration pulling downward
    - delta time: represents the time elapsed between two frames
        - using delta time normalizes movement, so it remains the same regardless of frame rate
*/

#include <raylib.h>


int main() {
    
    // Window Dimensions
    const int windowWidth = 512;
    const int windowHeight = 380;

    // Call function that makes window pop-up
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    int velocity = 0; // Initial velocity (not moving)
    const int jumpForce = -600; // Controls how high the jump is
    const int gravity = 1000; // Makes the character fall
    bool isInAir{};

    Texture2D scarfy = LoadTexture("textures/scarfy.png"); // load texture
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    

    // Animation frame
    int frame = 0;
    // Amount of time before we update the animation frame
    const float updateTime(1.0/12.0);
    float runningTime = 0;

    SetTargetFPS(60); // sets target FPS, doesn't guarantee this value

    while(!WindowShouldClose()) {

        // Calculate delta time
        const float dT(GetFrameTime());

        // Start a new frame
        BeginDrawing();
        ClearBackground(WHITE);

        // Perform ground check (Checks if rectangle has reached or is below the ground level)
        if(scarfyPos.y >= windowHeight - scarfyRec.height) {
            // Rectangle is on the ground
            velocity = 0;
            isInAir = false;
        } else {
            // Only apply gravity when rectangle is in the air
            velocity = velocity + (gravity * dT);
            isInAir = true;
        }

        // Rectangle jumps when space is pressed (Subtracting from velocity moves the character up)
        if(IsKeyPressed(KEY_SPACE) && !isInAir) {
            velocity = velocity + jumpForce;
        }


        scarfyPos.y = scarfyPos.y + (velocity * dT);

        // Update running time
        runningTime = runningTime + dT;
        if (runningTime >= updateTime) {
            runningTime = 0;

            // Update animation frame
            scarfyRec.x = frame * scarfyRec.width;
            frame++;

            if (frame > 5) {
                frame = 0;
            }
        }

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        // End the frame and present the new content
        EndDrawing(); 

    }
    UnloadTexture(scarfy);
    CloseWindow();
}
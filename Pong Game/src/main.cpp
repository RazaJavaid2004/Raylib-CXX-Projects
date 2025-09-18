#include "ball.h"
#include "paddle.h"
#include "line.h"
#include "score.h"
#include <cmath>

int cpu_score = 0;
int player_score = 0;

int main() {
    // game state variables
    const int winScore = 10;
    bool gameOver = false;
    const char* winnerText = nullptr;

    // screen variables
    const int screenWidth = 1280;
    const int screenHeight = 800;

    // ball variables
    const float INITIAL_BALL_SPEED = 1.0f;
    float currentBallSpeed = INITIAL_BALL_SPEED;
    const float ballSpeedIncrement = 0.1f;
    const int radius = 20;
    
    Vector2 position = {screenWidth / 2, screenHeight / 2};
    Vector2 speed = {INITIAL_BALL_SPEED, INITIAL_BALL_SPEED};
    Color ballColor = WHITE;

    // paddle variables
    const int PADDLE_WIDTH = 25;
    const int PADDLE_HEIGHT = 120;
    const int PADDLE_SPEED = 2;
    Color paddleColor = WHITE;    

    // left paddle (AI) variables
    const int cpuPaddleX = 10;
    const int cpuPaddleY = screenHeight / 2 - PADDLE_HEIGHT / 2;

    // right paddle (Player) variables
    const int playerPaddleX = screenWidth - PADDLE_WIDTH - 10;
    const int playerPaddleY = screenHeight / 2 - PADDLE_HEIGHT / 2;

    // line variables;
    const int startX = screenWidth / 2;
    const int startY = 0;
    const int endX = startX;
    const int endY = screenHeight;
    Color lineColor = WHITE;

    // Score variables
    const int FONT_SIZE = 80;
    const Color scoreColor = WHITE;
    const int SCORE_Y = 20;
    const int PLAYER_SCORE_X = 3 * screenWidth / 4 - 20;
    const int CPU_SCORE_X = screenWidth / 4 - 20;
    

    // initialize window;
    InitWindow(screenWidth, screenHeight, "1973 Pong Game");

    // game objects
    Line line(startX, startY, endX, endY, lineColor);
    Ball ball(position, speed, radius, ballColor);
    CPUPaddle ai(cpuPaddleX, cpuPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, 0, PADDLE_SPEED, paddleColor);
    Paddle player(playerPaddleX, playerPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, 0, PADDLE_SPEED, paddleColor);
    Score playerScore(TextFormat("%i", player_score), PLAYER_SCORE_X, SCORE_Y, FONT_SIZE, scoreColor);
    Score aiScore(TextFormat("%i", cpu_score), CPU_SCORE_X, SCORE_Y, FONT_SIZE, scoreColor);

    while(!WindowShouldClose()) {
        // event handling;
        if (!gameOver) {
            // Player paddle collision with angle variation
            if(CheckCollisionCircleRec(Vector2{ball.getPositionX(), ball.getPositionY()}, ball.getRadius(), player.getRect())) {
                // Calculate relative intersection point with paddle
                float relativeIntersectY = (player.getRect().y + player.getRect().height/2) - ball.getPositionY();
                // Normalize intersection point to [-1, 1]
                float normalizedIntersectY = relativeIntersectY / (player.getRect().height/2);
                // Calculate bounce angle (up to 75 degrees)
                float bounceAngle = normalizedIntersectY * (5.0f * PI / 12.0f); // 75 degrees in radians
                
                // Calculate current ball speed and increase it
                float ballSpeed = sqrt(ball.getSpeedX() * ball.getSpeedX() + ball.getSpeedY() * ball.getSpeedY());
                ballSpeed += ballSpeedIncrement;  // Gradually increase speed
                
                // Set new ball velocity with increased speed
                ball.setSpeedX(-ballSpeed * cos(bounceAngle));
                ball.setSpeedY(-ballSpeed * sin(bounceAngle));
                
                // Move ball outside paddle to prevent multiple collisions
                ball.setPosition(player.getRect().x - ball.getRadius() - 1, ball.getPositionY());
            }
            
            // AI paddle collision with angle variation
            if(CheckCollisionCircleRec(Vector2{ball.getPositionX(), ball.getPositionY()}, ball.getRadius(), ai.getRect())) {
                float relativeIntersectY = (ai.getRect().y + ai.getRect().height/2) - ball.getPositionY();
                float normalizedIntersectY = relativeIntersectY / (ai.getRect().height/2);
                float bounceAngle = normalizedIntersectY * (5.0f * PI / 12.0f);
                
                // Calculate current ball speed and increase it
                float ballSpeed = sqrt(ball.getSpeedX() * ball.getSpeedX() + ball.getSpeedY() * ball.getSpeedY());
                ballSpeed += ballSpeedIncrement;  // Gradually increase speed
                
                // Set new ball velocity with increased speed
                ball.setSpeedX(ballSpeed * cos(bounceAngle));
                ball.setSpeedY(-ballSpeed * sin(bounceAngle));
                
                // Move ball outside paddle to prevent multiple collisions
                ball.setPosition(ai.getRect().x + ai.getRect().width + ball.getRadius() + 1, ball.getPositionY());
            }

            // scoring logic
            if (ball.getPositionX() < 0) {
                // Player scores
                player_score++;
                if (player_score >= winScore) {
                    gameOver = true;
                    winnerText = "PLAYER WINS!";
                } else {
                    // Reset ball to center with random direction, keeping current speed
                    ball.setPosition(screenWidth / 2, screenHeight / 2);
                    float dir = (GetRandomValue(0, 1) == 0) ? 1.0f : -1.0f;
                    ball.setSpeedX(currentBallSpeed * dir);
                    ball.setSpeedY(currentBallSpeed * ((GetRandomValue(0, 1) == 0) ? 1.0f : -1.0f));
                }
            }
            if (ball.getPositionX() > screenWidth) {
                // CPU scores
                cpu_score++;
                if (cpu_score >= winScore) {
                    gameOver = true;
                    winnerText = "CPU WINS!";
                } else {
                    // Reset ball to center with random direction, keeping current speed
                    ball.setPosition(screenWidth / 2, screenHeight / 2);
                    float dir = (GetRandomValue(0, 1) == 0) ? -1.0f : 1.0f;
                    ball.setSpeedX(currentBallSpeed * dir);
                    ball.setSpeedY(currentBallSpeed * ((GetRandomValue(0, 1) == 0) ? 1.0f : -1.0f));
                }
            }

            // update positions only if game is not over
            ball.update();
            ai.update(ball);
            player.update();
        }

        // update score display
        playerScore.setText(TextFormat("%i", player_score));
        aiScore.setText(TextFormat("%i", cpu_score));

    // draw objects;
    BeginDrawing();

    ClearBackground(BLACK);
    line.draw();
    ball.draw();
    ai.draw();
    player.draw();
    playerScore.draw();
    aiScore.draw();
    

    // Winner message (if game is over)
    if (gameOver && winnerText != nullptr) {
        const char* pressSpaceText = "Press SPACE to play again";
        int winnerFontSize = 100;
        int promptFontSize = 30;
        
        // Calculate text dimensions for centering
        int winnerTextWidth = MeasureText(winnerText, winnerFontSize);
        int promptTextWidth = MeasureText(pressSpaceText, promptFontSize);
        
        // Draw winner text with shadow
        DrawText(winnerText, 
                (screenWidth - winnerTextWidth) / 2 + 4, 
                screenHeight / 2 - 50 + 4, 
                winnerFontSize, 
                BLACK);  // shadow
        DrawText(winnerText, 
                (screenWidth - winnerTextWidth) / 2, 
                screenHeight / 2 - 50, 
                winnerFontSize, 
                GOLD);   // actual text
        
        // Draw "Press SPACE" prompt
        DrawText(pressSpaceText,
                (screenWidth - promptTextWidth) / 2,
                screenHeight / 2 + 50,
                promptFontSize,
                WHITE);
        
        // Check for space press to restart
        if (IsKeyPressed(KEY_SPACE)) {
            // Reset game state
            gameOver = false;
            winnerText = nullptr;
            player_score = 0;
            cpu_score = 0;
            // Reset ball to center
            ball.setPosition(screenWidth / 2, screenHeight / 2);
            float dir = (GetRandomValue(0, 1) == 0) ? 1.0f : -1.0f;
            ball.setSpeedX(0.5f * dir);
            ball.setSpeedY(0.5f * ((GetRandomValue(0, 1) == 0) ? 1.0f : -1.0f));
        }
    }

    EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
#include<stdio.h>
#include "include\raylib.h"

int main(){


float ballX, ballY, ballX_speed, ballY_speed , ballRadius , X_speed , Y_speed;
float rect1_X, rect1_Y , rect1X_speed , rect1Y_speed , rect1_width , rect1_height;
float rect2_X, rect2_Y , rect2X_speed , rect2Y_speed , rect2_width , rect2_height;


InitWindow(800,600,"bounce ball");

ballX = GetScreenWidth()/2 , ballY = GetScreenHeight()/2 , ballRadius = 7;
ballX_speed = 200;
ballY_speed = 200;


rect1_width = 10 , rect1_height = 75;
rect1_X = 50 , rect1_Y = GetScreenHeight()/2 - rect1_height/2;
rect1Y_speed = 7;


rect2_width = 10 , rect2_height = 75;
rect2_X = GetScreenWidth() - 50 - rect2_width , rect2_Y = GetScreenHeight()/2 - rect2_height/2;
rect2Y_speed = 7;

int game_run = 1;
int game_start = 0;
int score = 0;

SetWindowState(FLAG_VSYNC_HINT);

while (!WindowShouldClose()){

    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();


    if (game_run == 1){

    DrawCircle(ballX,ballY,ballRadius,BLUE);
    DrawRectangle(rect1_X,rect1_Y,rect1_width,rect1_height,WHITE);
    DrawRectangle(rect2_X,rect2_Y,rect2_width,rect2_height,WHITE);

    if (game_start == 0)
    DrawText("Press SPACE to start",GetScreenWidth()/2 - 130,GetScreenHeight()/2 + 20 ,25, YELLOW);

    if(IsKeyPressed(KEY_SPACE))
        game_start = 1;
          
    if(game_start == 1){  



    ballX = ballX + ballX_speed*GetFrameTime();
    ballY = ballY + ballY_speed*GetFrameTime();

    rect1Y_speed = 8;
    rect2Y_speed = 8;

    if (ballX > GetScreenWidth()){
        ballX = GetScreenWidth();
        ballX_speed *= -1;
    }

    if (ballX < 0 ){
        ballX = 0;
        ballX_speed *= -1;
    }

    if (ballY > GetScreenHeight()){
        ballY = GetScreenHeight();
        ballY_speed *= -1;
    }

    if (ballY < 0 ){
        ballY = 0;
        ballY_speed *= -1;
    }
    


    if(IsKeyDown(KEY_W) && (rect1_Y > 10)){
        rect1_Y = rect1_Y - rect1Y_speed;
    }
    

    if (IsKeyDown(KEY_S) && (rect1_Y < GetScreenHeight() - rect1_height - 10)){
        rect1_Y = rect1_Y + rect1Y_speed;
    }

    if(IsKeyDown(KEY_DOWN) && (rect2_Y < GetScreenHeight() - rect2_height - 10) ){
        rect2_Y = rect2_Y + rect2Y_speed;
    }

    if (IsKeyDown(KEY_UP) && (rect2_Y > 10)){
        rect2_Y = rect2_Y - rect2Y_speed;
    }

    if (CheckCollisionCircleRec((Vector2){ballX,ballY},ballRadius,(Rectangle){rect1_X,rect1_Y,rect1_width,rect1_height})){
        ballX_speed *= -1.09;
        ballY_speed *= 1.09;
    }

    
    if (CheckCollisionCircleRec((Vector2){ballX,ballY},ballRadius,(Rectangle){rect2_X,rect2_Y,rect2_width,rect2_height})){
        ballX_speed *= -1.09;
        ballY_speed *= 1.09;
    }
    }
    }

    if (ballX <= 0 || ballX >= GetScreenWidth()){
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),BLACK);        
        DrawText("GAME OVER" , GetScreenWidth()/2 - 200 , GetScreenHeight()/2 - 65 , 70, WHITE);
        DrawText("Press ENTER to play again",GetScreenWidth()/2 - 200,GetScreenHeight()/2 + 20 ,30, YELLOW);
        game_run = 0;

        if (IsKeyPressed(KEY_ENTER)){
            game_run = 1;
            game_start = 0;

            ballX = GetScreenWidth()/2 , ballY = GetScreenHeight()/2 , ballRadius = 7;
            ballX_speed = 200;
            ballY_speed = 200;


            rect1_width = 10 , rect1_height = 75;
            rect1_X = 50 , rect1_Y = GetScreenHeight()/2 - rect1_height/2;
            rect1Y_speed = 7;


            rect2_width = 10 , rect2_height = 75;
            rect2_X = GetScreenWidth() - 50 - rect2_width , rect2_Y = GetScreenHeight()/2 - rect2_height/2;
            rect2Y_speed = 7;

        }
    }

}


CloseWindow();

return 0;


}

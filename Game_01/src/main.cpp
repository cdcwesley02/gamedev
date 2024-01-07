//------------------------------------------------------------------------------------------
// Inclusão de bibliotecas
//------------------------------------------------------------------------------------------
#include "raylib.h"

#include <string>

using namespace std;




//------------------------------------------------------------------------------------------
// Tipos e estruturas de dados
//------------------------------------------------------------------------------------------
typedef enum GameScreen {LOGO = 0, TITLE, GAMEPLAY, ENDING, OPTION, LOAD } GameScreen;


//------------------------------------------------------------------------------------------
// Entrada ⁡⁣⁢⁡⁢⁢⁢main⁡⁡⁡
//------------------------------------------------------------------------------------------
int main(void)
{
    // Inicializacao
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game 0");

    GameScreen currentScreen = LOGO;

    // TODO: Inicialize todos os dados e variaveis necessarios aqui

    int fps_counter =0;                                                  // Contador de FPS        

    SetTargetFPS(60);                                                    // Definir o FPS
    //--------------------------------------------------------------------------------------

    // LOOP DO GAME
    while (!WindowShouldClose())
    {
        // Atualizacao
        //----------------------------------------------------------------------------------
        // TODO: Atualize suas variaveis aqui
        //----------------------------------------------------------------------------------
        switch (currentScreen)
        {
            case LOGO:
            {

                // TODO: Atualize as variaveis da tela LOGO aqui

                fps_counter++;                                             // Incremento do FPS   

                if (fps_counter >= 120)
                {
                    currentScreen = TITLE;
                }

            } break;

            case TITLE:
            {

                // TODO: Atualize as variaveis da tela TITLE aqui
                string selected_option = "iniciar";

            } break;

            case GAMEPLAY:
            {
                
                // TODO: Atualize as variaveis da tela GAMEPLAY aqui

            } break;

            case ENDING:
            {

                // TODO: Atualize as variaveis da tela ENDING aqui

            } break;

            case OPTION:
            {

                // TODO: Atualize as variaveis da tela OPTION aqui

            } break;

            case LOAD:
            {

                // TODO: Atualize as variaveis da tela LOAD aqui
            }
            
            default:  break;
        }

        // Desenho
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch (currentScreen)
            {
                case LOGO:
                {
                    DrawText("LOGO", 200, 200, 40, MAROON);
                    DrawText("Aguarde...", 200, 240, 20, MAROON);

                } break;

                case TITLE:
                {

                    // TODO: Definir as variaveis da tela Titulo aqui
                    

                    DrawRectangle(0, 0, screenWidth, screenHeight, BEIGE);
                    DrawText("TELA DO TITULO", 200, 200, 40, MAROON);

                    // Desenho dos botoes
                    DrawRectangle(200, 280, 200, 20, LIGHTGRAY);
                    DrawRectangle(200, 320, 200, 20, LIGHTGRAY);
                    DrawRectangle(200, 360, 200, 20, LIGHTGRAY);
                    DrawRectangle(200, 400, 200, 20, LIGHTGRAY);
                    
                } break;

                case GAMEPLAY:
                {

                } break;

                case ENDING:
                {

                } break;

                case OPTION:
                {
                    
                } break;

                case LOAD:
                {
                    
                } break;
                
                default: break;
            }

            

        EndDrawing();
    }

    // Encerramento
    //--------------------------------------------------------------------------------------

    // TODO: Encerrar todos os dados aqui (texturas, fonts, audios)!

    //--------------------------------------------------------------------------------------    
    CloseWindow();  // Fecha a janela e OpenGL context, limpeza de recursos
    //--------------------------------------------------------------------------------------

    return 0;
}
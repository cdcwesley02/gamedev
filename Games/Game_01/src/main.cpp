//------------------------------------------------------------------------------------------
// Inclusão de bibliotecas
//------------------------------------------------------------------------------------------
#include "menus.h"
#include "./scenes/Scene_Base.h"
#include "raylib.h"
#include <thread>
#include <chrono>

#include <string>

using namespace std;



//------------------------------------------------------------------------------------------
// Entrada ⁡⁣⁢⁡⁢⁢⁢main⁡⁡⁡
//------------------------------------------------------------------------------------------
int main(void)
{
    // Inicializacao
    //--------------------------------------------------------------------------------------
    
    startGame();
    
    GameScreen currentScreen = LOGO;
    // TODO: Inicialize todos os dados e variaveis necessarios aqui

    int fps_counter =0;                                                  // Contador de FPS        
    
    


   // SetTargetFPS(60);                                                    // Definir o FPS
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
                    currentScreen = LOAD;
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
                    drawLogo();
                    checkFPS();
                } break;

                case TITLE:
                {

                    drawTitle();
                    checkFPS();
                } break;

                case GAMEPLAY:
                {
                    drawGameplay();
                } break;

                case ENDING:
                {
                    drawEnding();
                } break;

                case OPTION:
                {

                    drawOptions();
                } break;

                case LOAD:
                {

                    drawLoad();
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
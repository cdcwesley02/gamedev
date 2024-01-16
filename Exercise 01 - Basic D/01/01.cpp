// ----------------------------------------------------------------------------------------------
// INCLUSÃO DE BIBLIOTECAS
// ----------------------------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

// ----------------------------------------------------------------------------------------------
// PLAYER DATA STORAGE
// ----------------------------------------------------------------------------------------------
#include "library.h"

// ----------------------------------------------------------------------------------------------
// DEFINIÇÃO DE OBJETOS GLOBAIS
// ----------------------------------------------------------------------------------------------
Player player;
Enemy Enemy_Base;
Enemy enemy;

// ----------------------------------------------------------------------------------------------
// DEFINIÇÃO DE VARIÁVEIS GLOBAIS
// ----------------------------------------------------------------------------------------------
int choice;                                      // Gives player choice to battle
bool battle;                                     // If battle is running
bool battle_end;                                 // If player or enemy dies
bool game_is_running = false;                    // Se a gameplay esta rodando
bool player_lv_up = false;                       //
int dmg = 0;                                     // Damage calculator
int turn_counter = 0;                            // Turn counter

// ----------------------------------------------------------------------------------------------
// DEFINIÇÃO DE FUNÇÕES GLOBAIS
// ----------------------------------------------------------------------------------------------
void create_enemy()
{
    Enemy_Base.name = "OPONENTE";
    Enemy_Base.hp   = 10;
    Enemy_Base.atk  = 5 ;   
    Enemy_Base.def  = 1 ;
    Enemy_Base.spd  = 3 ;
}

void create_slime()
{
    enemy.name = "Slime";
    enemy.hp = Enemy_Base.hp;
    enemy.atk = Enemy_Base.atk;
    enemy.def = Enemy_Base.def;
    enemy.spd = Enemy_Base.spd;
    enemy.xp_give = 5;
}

void create_player()
{
    player.name = "JACK";
    player.gender = "Masculino";

    player.lv = 1;
    player.xp = 0;
    player.max_xp = 10;
    
    
    cout << "Escolha uma das classes: \n (1) Archer - (2) Warrior - (3) Wizard\n\n Sua escolha ";
    cin >> player.select_job;

    if (player.select_job == 1)
    {
        player.job = "Archer";
        Archer job;
        player.lives = job.lives;   player.hp = job.hp;   player.atk = job.atk;   player.def = job.def;
        player.spd = job.spd;       player.max_hp = job.hp;
    }

    if (player.select_job == 2)
    {
        player.job = "Warrior";
        Warrior job;
        player.lives = job.lives;   player.hp = job.hp;   player.atk = job.atk;   player.def = job.def;
        player.spd = job.spd;       player.max_hp = job.hp;
    }

    if (player.select_job == 3)
    {
        player.job = "Wizard";
        Wizard job;
        player.lives = job.lives;   player.hp = job.hp;   player.atk = job.atk;   player.def = job.def;
        player.spd = job.spd;       player.max_hp = job.hp;
    }
}

void save_player()
{
    PLAYER_NAME     = player.name;
    PLAYER_GENDER   = player.gender;
    PLAYER_JOB      = player.job;
    PLAYER_HP       = player.hp;
    PLAYER_ATK      = player.atk;
    PLAYER_DEF      = player.def;
    PLAYER_SPD      = player.spd;
    PLAYER_XP       = player.xp;
    PLAYER_LV       = player.lv;
    PLAYER_MAX_XP   = player.max_xp;
}

void reset_player(string mode)
{
    if (mode == "full")
    {
        player.name     = PLAYER_NAME;
        player.gender   = PLAYER_GENDER;
        player.job      = PLAYER_JOB;
        player.hp       = PLAYER_HP;
        player.atk      = PLAYER_ATK;
        player.def      = PLAYER_DEF;
        player.spd      = PLAYER_SPD;
        player.xp       = PLAYER_XP;
        player.lv       = PLAYER_LV;
    }
    else if (mode == "status")
    {
        player.hp   = PLAYER_HP;
        player.atk  = PLAYER_ATK;
        player.def  = PLAYER_DEF;
        player.spd  = PLAYER_SPD;
    }
}

void add_xp()
{
    player.xp = player.xp + enemy.xp_give;
}

void lv_up()
{
    if (player.xp >= player.max_xp)    
    {   
        player.max_xp *=2;
        player.lv++;
        player.atk++;
        player.def++;
        player.spd++;
        player.max_hp += 5;
        player.hp = player.max_hp;
    }
}

// ----------------------------------------------------------------------------------------------
// DEFINIÇÃO DO FUNCIONAMENTO DO GAME
// ----------------------------------------------------------------------------------------------
int start_game()
{
    // Inicio do jogo
    cout << "\n GAME STARTED \n" << endl;

    // Criando o jogador
    create_player();
    save_player();

    // Mostrar status do jogador
    player.show_status();



    return 0;
}

// ----------------------------------------------------------------------------------------------
// MODULO DE BATALHA
// ----------------------------------------------------------------------------------------------

void dmg_calculator()
{
    if (dmg < 0)
        {
            dmg = dmg * -1;
        }
    else
        {
            dmg = 1;
        }
}

void end_battle()
{
    if (enemy.hp <= 0 or player.hp <= 0)
    {
        if (enemy.hp <= 0)
        {
            cout << enemy.name << " DERROTADO !" << endl;
            add_xp();
            lv_up();
        }
        else
        {
            cout << player.name << " MORREU !" << endl;
            player.lives = player.lives -1;
        }
        battle_end = true;
        battle = false;
    }
}

void run_battle()
{
    // Se o jogador decidir batalhar
    if (choice == 1)
    {   
        battle = true;                                      // Seta a batalha como verdadeira
        battle_end = false;                                 // Seta o fim da batalha
        turn_counter = 0;
        create_slime();                                        // Criação do inimigo

        // Estatisticas do personagem e do oponente
        cout << "\n A batalha começou \n" << endl;
        cout << "Vidas: " << player.lives << endl;
        cout << "        VOCE"                       << "   "     << enemy.name  << endl;
        cout << "HP:     " << player.hp;    cout     << "       " << enemy.hp    << endl;
        cout << "ATK:    " << player.atk;   cout     << "       " << enemy.atk   << endl;
        cout << "DEF:    " << player.def;   cout     << "       " << enemy.def   << endl;
        
        // Loop da batalha
        while (battle == true)
        {
            // Somar contador de turno e printar
            turn_counter = turn_counter + 1;
            cout << "# Turno " << turn_counter << endl;
            
            // Calcular dano que o inimigo recebe
            dmg = enemy.def - player.atk;
            dmg_calculator();
            enemy.hp = enemy.hp - dmg;
            cout << "    PLAYER DMG --> " << dmg << endl;
            
            // Condição para encerrar batalha
            end_battle();
            if (battle_end == true)
            {
                break;
            }

            // Calcular dano que o jogador recebe
            dmg = player.def - enemy.atk;
            dmg_calculator();
            player.hp = player.hp - dmg;
            cout << "    ENEMY DMG -->" << dmg << endl;
            
            // Condição para encerrar batalha
            end_battle();
            if (battle_end == true)
            {
                break;
            }
        }
    }
    
    // Se o jogador decidir fugir
    else 
    {
        cout << "\n Voce fugiu !\n" << endl;
    }
}

int start_battle()
{
    if (player.hp > 0)
    {
        // Cria a base do inimigo
        create_enemy();

        // Mostra com quem o player se encontrou
        cout << "\n Você se deparou com um " << Enemy_Base.name << "!" << endl;
        cout << "Sua escolha (1)Batalhar (2)Fugir: ";
        cin >> choice;

        // Roda o sistema de batalha
        run_battle();    

        // Mostra os status do player
        cout << "Current Status:" << endl;
        player.show_status();
    }
    else
    {
        reset_player("status");
    }
    return 0;
}

// ----------------------------------------------------------------------------------------------
// FUNCIONAMENTO DO PROGRAMA
// ----------------------------------------------------------------------------------------------
int main()
{
    // INICIALIZAÇÃO
    start_game();
    game_is_running = true;;

    // LOOP DO GAMEPLAY
    while (game_is_running)
    {
        start_battle();
        if (player.lives <= 0 and player.hp <= 0)
        {
            game_is_running = false;
        }
        else
        {
            game_is_running = true;
        }
    }
    
}
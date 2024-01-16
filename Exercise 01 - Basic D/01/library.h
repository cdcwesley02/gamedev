#include <iostream>
#include <string>
using namespace std;


// ------------------------------------------------------------------------------
// PLAYER DATABASE
// ------------------------------------------------------------------------------
int PLAYER_LIVES, PLAYER_HP, PLAYER_ATK, PLAYER_DEF, PLAYER_SPD, PLAYER_XP, PLAYER_LV;
int PLAYER_MAX_XP, PLAYER_MAX_HP;
string PLAYER_NAME, PLAYER_JOB, PLAYER_GENDER;

void SHOW_PLAYER()
{
    cout << "\n DATA :: Dados Salvos\n"     << endl;
    cout << "NOME:   " << PLAYER_NAME       << endl;
    cout << "CLASSE: " << PLAYER_JOB        << endl;
    cout << "SEXO:   " << PLAYER_GENDER     << endl;
    cout << "VIDAS: " << PLAYER_LIVES       << endl;
    cout << "HP:    " << PLAYER_HP          << endl;
    cout << "ATK:   " << PLAYER_ATK         << endl;
    cout << "DEF:   " << PLAYER_DEF         << endl;
    cout << "SPD:   " << PLAYER_SPD         << endl;
    cout << "EXP:   " << PLAYER_XP          << endl;
    cout << "LV:    " << PLAYER_LV          << endl;
}

class Player
{
    public:
    int lives, max_hp, hp, atk, def, spd, xp, lv, max_xp, select_job;
    string name, job, gender;

    void show_status()
    {
        cout << endl;
        cout << "Nome:   "  << name         << endl;
        cout << "Classe: "  << job          << endl;
        cout << "Sexo:   "  << gender       << endl;
        cout << "Vidas:  "  << lives        << endl;
        cout << "MAX HP: "  << max_hp       << endl;
        cout << "HP:     "  << hp           << endl;
        cout << "ATK:    "  << atk          << endl;
        cout << "DEF:    "  << def          << endl;
        cout << "SPD:    "  << spd          << endl;
        cout << "MAX XP  "  << max_xp       << endl;
        cout << "EXP:    "  << xp           << endl;
        cout << "LV:     "  << lv           << endl;
    }

};

// ------------------------------------------------------------------------------
// CLASSES
// ------------------------------------------------------------------------------
class Warrior
{
    public:
    int lives = 3, hp = 10, atk = 5, def = 3, spd = 2;
};

class Wizard
{
    public:
    int lives = 3, hp = 5, atk = 3, def = 0, spd = 1;
};

class Archer
{
    public:
    int lives = 3, hp = 15, atk = 7, def = 1, spd = 5;
};

// ------------------------------------------------------------------------------
// ENEMY
// ------------------------------------------------------------------------------
class Enemy
{
    public:
    string name;
    int hp, atk, def, spd, xp_give;

};

class Slime : Enemy
{
    public:
    string name = "SLIME";
    int hp = 20, atk = 1, def = 1, spd = 3;

};


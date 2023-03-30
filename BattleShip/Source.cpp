#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

void main_menu();
void locate_ships();
//Including Header Files
#include "MainVariables.h"
#include "ColorFunctions.h"
#include "Animations.h"
#include "SelectLanguageFunction.h"
#include "DisplayAttackClean.h"
#include "LocatingShipsFunctions.h"
#include "Menus.h"

int main() {
	srand(time(0));
	battle_ship();
	loading_animation();
	main_menu();
	return 0;
}
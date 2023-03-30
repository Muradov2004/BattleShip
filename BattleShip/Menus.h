#pragma once

void start() {
	system("cls");
	fillplayer_arr();
	fillbot_arr();
	fillfree_arr();
	locate_bot_ships();
	manual_auto_locate();
}

int color_m = 124;
int color_n = 7;
void exit_game() {
	system("cls");
	if (language == 'e')
	{
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("Are You Sure?", 7);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(187) << "\t" << char(201) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(186);
		print_color("YES", color_m);
		cout << char(186);
		cout << "\t";
		cout << char(186);
		print_color("NO", color_n);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(188) << "\t" << char(200) << char(205) << char(205) << char(188);
	}
	else if (language == 'a')
	{
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("Cixmagina Eminsen?", 7);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(187) << "\t  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(186);
		print_color("Beli", color_m);
		cout << char(186);
		cout << "\t  ";
		cout << char(186);
		print_color("Xeyr", color_n);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(188) << "\t  " << char(200) << char(205) << char(205) << char(205) << char(205) << char(188);
	}
	string k = "";
	int number = _getch();
	if (number == 224)
	{
		number = _getch();
		if (number == 75) k = "left";
		else if (number == 77) k = "right";

	}
	else if (number == 13) k = "enter";
	else if (number == 98 || number == 66) main_menu();
	if (k == "left" || k == "right")
	{
		int temp = color_m;
		color_m = color_n;
		color_n = temp;
		exit_game();
	}
	else if (k == "enter") {
		if (color_m == 124) exit(0);
		else if (color_n == 124) main_menu();
	}
	else exit_game();

}

int color_a = 124;
int color_b = 7;
int color_c = 7;
int color_f = 7;
void main_menu() {
	system("cls");
	if (language == 'e')
	{
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("Start Game", color_a);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("About Game", color_b);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("Exit  Game", color_c);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color(" Language ", color_f);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
	}
	else if (language == 'a')
	{
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(186);
		print_color("Oyuna Basla", color_a);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("Oyun Haqqinda", color_b);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("Oyundan Cixis", color_c);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(186);
		print_color("Dil Secmek", color_f);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
	}
	string k = "";
	int number = _getch();
	if (number == 224)
	{
		number = _getch();
		if (number == 72) k = "up";
		else if (number == 80) k = "down";
	}
	else if (number == 13) k = "enter";
	if (k == "up")
	{
		int temp = color_a;
		color_a = color_b;
		color_b = color_c;
		color_c = color_f;
		color_f = temp;
		main_menu();
	}
	else if (k == "down")
	{
		int temp = color_f;
		color_f = color_c;
		color_c = color_b;
		color_b = color_a;
		color_a = temp;
		main_menu();
	}
	else if (k == "enter") {
		if (color_a == 124)	start();
		else if (color_b == 124) about();
		else if (color_c == 124) exit_game();
		else if (color_f == 124) select_language();
	}
	else main_menu();
}
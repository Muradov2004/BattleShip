#pragma once

int color_g = 124;
int color_h = 7;
void select_language() {
	system("cls");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\b\b";
	cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
	cout << endl;
	cout << "\t\t\t\t\t\t\t\b\b";
	cout << char(186);
	print_color("English", color_g);
	cout << char(186);
	cout << endl;
	cout << "\t\t\t\t\t\t\t\b\b";
	cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
	cout << endl;
	cout << "\t\t\t\t\t\t\t\b\b\b";
	cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
	cout << endl;
	cout << "\t\t\t\t\t\t\t\b\b\b";
	cout << char(186);
	print_color("Azerbaycan", color_h);
	cout << char(186);
	cout << endl;
	cout << "\t\t\t\t\t\t\t\b\b\b";
	cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
	string k = "";
	int number = _getch();
	if (number == 224)
	{
		number = _getch();
		if (number == 72) k = "up";
		else if (number == 80) k = "down";

	}
	else if (number == 13) k = "enter";
	else if (number == 98 || number == 66) main_menu();
	if (k == "up" || k == "down")
	{
		int temp = color_g;
		color_g = color_h;
		color_h = temp;
		select_language();
	}
	else if (k == "enter") {
		if (color_g == 124) language = 'e';
		else if (color_h == 124) language = 'a';
		main_menu();
	}
	else select_language();

}

#pragma once

void fillplayer_arr() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			player_arr[i][j] = ' ';
		}
	}
}

void fillbot_arr() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			bot_arr[i][j] = ' ';
		}
	}
}

void fillfree_arr() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			free_arr[i][j] = ' ';
		}
	}
}

void point_deleter() {
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (player_arr[i][j] == char(250)) player_arr[i][j] = ' ';
		}
	}
}

void check_win() {
	if (ship1 + ship2 + ship3 + ship4 == 0)
	{
		int num = 20;
		while (num > 0) {
			system("cls");
			switch (num % 7)
			{
			case 1:
				system("Color 1");
				break;
			case 2:
				system("Color 2");
				break;
			case 3:
				system("Color 3");
				break;
			case 4:
				system("Color 4");
				break;
			case 5:
				system("Color 5");
				break;
			case 6:
				system("Color 6");
				break;
			}
			lose();
			num--;
			Sleep(100);
		}
		exit(0);
	}
	else if (bot_ship1 + bot_ship2 + bot_ship3 + bot_ship4 == 0)
	{
		int num = 20;
		while (num > 0) {
			system("cls");
			switch (num % 7)
			{
			case 1:
				system("Color 1");
				break;
			case 2:
				system("Color 2");
				break;
			case 3:
				system("Color 3");
				break;
			case 4:
				system("Color 4");
				break;
			case 5:
				system("Color 5");
				break;
			case 6:
				system("Color 6");
				break;
			}
			win();
			num--;
			Sleep(100);
		}
		exit(0);
	}
}

void attack_display() {
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 0) cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << "\t\t" << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186);
		for (size_t j = 0; j < 10; j++)
		{
			if (player_arr[i][j] == '0')
			{
				if (j == 0) print_color(" 0 ", 2);
				else print_color("0 ", 2);
			}
			else if (player_arr[i][j] == 'X')
			{
				if (j == 0) print_color(" X ", 4);
				else print_color("X ", 4);
			}
			else
			{
				if (j == 0) cout << ' ';
				cout << player_arr[i][j] << ' ';
			}
		}
		cout << char(186) << "\t\t";
		cout << char(186);
		for (size_t j = 0; j < 10; j++)
		{
			if (free_arr[i][j] == '@')
			{
				if (j == 0) print_color(" @ ", 11);
				else print_color("@ ", 11);
			}
			else if (free_arr[i][j] == 'X')
			{
				if (j == 0) print_color(" X ", 4);
				else print_color("X ", 4);
			}
			else
			{
				if (j == 0) cout << ' ';
				cout << free_arr[i][j] << ' ';
			}
		}
		cout << char(186) << endl;
		if (i == 9) {
			cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << "\t\t" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
			if (language == 'e') cout << "REMAINING SHIPS : " << (ship1 + ship2 + ship3 + ship4) << "\t\tREMAINING SHIPS : " << (bot_ship1 + bot_ship2 + bot_ship3 + bot_ship4) << endl;
			else if (language == 'a') cout << "Qalan Gemiler : " << (ship1 + ship2 + ship3 + ship4) << "\t\tQalan Gemiler : " << (bot_ship1 + bot_ship2 + bot_ship3 + bot_ship4) << endl;
		}
	}
}

void attack();
void attack_bot();

void attack_turn(bool player) {
	check_win();
	if (player)	attack();
	else attack_bot();
}

void find_destroyed_ship() {
	for (size_t x = 0; x < 10; x++)
	{
		for (size_t y = 0; y < 10; y++)
		{
			if (free_arr[x][y] == 'X')
			{
				if (x == ship21x && y == ship21y)
				{
					if (ship21 == 'v' && free_arr[x][y + 1] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x][y + 1] = char(254);
						bot_ship2--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x][y + 2] = free_arr[x + 1][y + 2] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 1][y] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x - 1][y + 2] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 1][y] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = char(250);
						attack_turn(1);
					}
					else if (ship21 == 'h' && free_arr[x + 1][y] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x + 1][y] = char(254);
						bot_ship2--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x - 1][y] = free_arr[x + 2][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 2][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 2][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 2][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						attack_turn(1);
					}
				}
				else if (x == ship22x && y == ship22y)
				{
					if (ship22 == 'v' && free_arr[x][y + 1] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x][y + 1] = char(254);
						bot_ship2--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x][y + 2] = free_arr[x + 1][y + 2] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 1][y] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x - 1][y + 2] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 1][y] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = char(250);
						attack_turn(1);
					}
					else if (ship22 == 'h' && free_arr[x + 1][y] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x + 1][y] = char(254);
						bot_ship2--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x - 1][y] = free_arr[x + 2][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 2][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 2][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 2][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						attack_turn(1);
					}
				}
				else if (x == ship23x && y == ship23y)
				{
					if (ship23 == 'v' && free_arr[x][y + 1] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x][y + 1] = char(254);
						bot_ship2--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x][y + 2] = free_arr[x + 1][y + 2] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 1][y] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x - 1][y + 2] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 1][y] = free_arr[x][y + 2] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = char(250);
						attack_turn(1);
					}
					else if (ship23 == 'h' && free_arr[x + 1][y] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x + 1][y] = char(254);
						bot_ship2--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x - 1][y] = free_arr[x + 2][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 2][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 2][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 2][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = char(250);
						attack_turn(1);
					}
				}
				else if (x == ship31x && y == ship31y)
				{
					if (ship31 == 'v' && free_arr[x][y + 1] == 'X' && free_arr[x][y + 2] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x][y + 1] = char(254);
						free_arr[x][y + 2] = char(254);
						bot_ship3--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = free_arr[x - 1][y + 3] = free_arr[x][y + 3] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 1][y] = free_arr[x][y + 3] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = free_arr[x - 1][y + 3] = free_arr[x][y + 3] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 1][y] = free_arr[x][y + 3] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = char(250);
						attack_turn(1);
					}
					else if (ship31 == 'h' && free_arr[x + 1][y] == 'X' && free_arr[x + 2][y] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x + 1][y] = char(254);
						free_arr[x + 2][y] = char(254);
						bot_ship3--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 3][y - 1] = free_arr[x - 1][y] = free_arr[x + 3][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 3][y - 1] = free_arr[x + 3][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 3][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 3][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = char(250);
						attack_turn(1);
					}
				}
				else if (x == ship32x && y == ship32y)
				{
					if (ship32 == 'v' && free_arr[x][y + 1] == 'X' && free_arr[x][y + 2] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x][y + 1] = char(254);
						free_arr[x][y + 2] = char(254);
						bot_ship3--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = free_arr[x - 1][y + 3] = free_arr[x][y + 3] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 1][y] = free_arr[x][y + 3] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = free_arr[x - 1][y + 3] = free_arr[x][y + 3] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 1][y] = free_arr[x][y + 3] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = char(250);
						attack_turn(1);
					}
					else if (ship32 == 'h' && free_arr[x + 1][y] == 'X' && free_arr[x + 2][y] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x + 1][y] = char(254);
						free_arr[x + 2][y] = char(254);
						bot_ship3--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 3][y - 1] = free_arr[x - 1][y] = free_arr[x + 3][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 3][y - 1] = free_arr[x + 3][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 3][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 3][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = char(250);
						attack_turn(1);
					}
				}
				else if (x == ship41x && y == ship41y)
				{
					if (ship41 == 'v' && free_arr[x][y + 1] == 'X' && free_arr[x][y + 2] == 'X' && free_arr[x][y + 3] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x][y + 1] = char(254);
						free_arr[x][y + 2] = char(254);
						free_arr[x][y + 3] = char(254);
						bot_ship4--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = free_arr[x - 1][y + 3] = free_arr[x][y + 4] = free_arr[x - 1][y + 4] = free_arr[x + 1][y + 4] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 1][y] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = free_arr[x][y + 4] = free_arr[x + 1][y + 4] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x + 1][y + 1] = free_arr[x - 1][y + 2] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = free_arr[x - 1][y + 3] = free_arr[x][y + 4] = free_arr[x - 1][y + 4] = free_arr[x + 1][y + 4] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 1][y] = free_arr[x + 1][y + 1] = free_arr[x + 1][y + 2] = free_arr[x + 1][y + 3] = free_arr[x][y + 4] = free_arr[x + 1][y + 4] = char(250);
						attack_turn(1);
					}
					else if (ship41 == 'h' && free_arr[x + 1][y] == 'X' && free_arr[x + 2][y] == 'X' && free_arr[x + 3][y] == 'X')
					{
						free_arr[x][y] = char(254);
						free_arr[x + 1][y] = char(254);
						free_arr[x + 2][y] = char(254);
						free_arr[x + 3][y] = char(254);
						bot_ship4--;
						if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 3][y - 1] = free_arr[x + 4][y - 1] = free_arr[x - 1][y] = free_arr[x + 4][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = free_arr[x + 4][y + 1] = char(250);
						else if (x == 0 && y > 0) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 2][y - 1] = free_arr[x + 3][y - 1] = free_arr[x + 4][y - 1] = free_arr[x + 4][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = free_arr[x + 4][y + 1] = char(250);
						else if (x > 0 && y == 0) free_arr[x - 1][y] = free_arr[x + 4][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = free_arr[x + 4][y + 1] = char(250);
						else if (x == 0 && y == 0) free_arr[x + 4][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = free_arr[x + 2][y + 1] = free_arr[x + 3][y + 1] = free_arr[x + 4][y + 1] = char(250);
						attack_turn(1);
					}
				}
			}
		}
	}
}

void attack() {
	int x = 0, y = 0;
	while (true)
	{
		x = rand() % 10;
		y = rand() % 10;
		if (free_arr[x][y] == ' ') {
			free_arr[x][y] = char(64);
			system("cls");
			attack_display();
			break;
		}
	}
	while (true)
	{
		int number;
		number = _getch();
		if (number == 224)
		{
			number = _getch();
			if (number == 72) {
				free_arr[x][y] = char(32);
				int a = x, b = y;
				while (free_arr[x - 1][y] != ' ' && x > 0) x--;
				if ((x - 1) >= 0)x--;
				else x += 9;
				if (free_arr[x][y] != ' ') while (free_arr[x][y] != ' ') x--;
				if (a == x && b == y)
				{
					while (true)
					{
						x = rand() % 10;
						y = rand() % 10;
						if (free_arr[x][y] == ' ') break;
					}
				}
				free_arr[x][y] = char(64);
			}
			else if (number == 80) {
				free_arr[x][y] = char(32);
				int a = x, b = y;
				while (free_arr[x + 1][y] != ' ' && x < 9) x++;
				if ((x + 1) <= 9)x++;
				else x -= 9;
				if (free_arr[x][y] != ' ') while (free_arr[x][y] != ' ') x++;
				if (a == x && b == y)
				{
					while (true)
					{
						x = rand() % 10;
						y = rand() % 10;
						if (free_arr[x][y] == ' ') break;
					}
				}
				free_arr[x][y] = char(64);
			}
			else if (number == 75) {
				free_arr[x][y] = char(32);
				int a = x, b = y;
				while (free_arr[x][y - 1] != ' ' && y > 0) y--;
				if ((y - 1) >= 0)y--;
				else y += 9;
				if (free_arr[x][y] != ' ') while (free_arr[x][y] != ' ') y--;
				if (a == x && b == y)
				{
					while (true)
					{
						x = rand() % 10;
						y = rand() % 10;
						if (free_arr[x][y] == ' ') break;
					}
				}
				free_arr[x][y] = char(64);
			}
			else if (number == 77) {
				free_arr[x][y] = char(32);
				int a = x, b = y;
				while (free_arr[x][y + 1] != ' ' && y < 9) y++;
				if ((y + 1) <= 9) y++;
				else y -= 9;
				if (free_arr[x][y] != ' ') while (free_arr[x][y] != ' ') y++;
				if (a == x && b == y)
				{
					while (true)
					{
						x = rand() % 10;
						y = rand() % 10;
						if (free_arr[x][y] == ' ') break;
					}
				}
				free_arr[x][y] = char(64);
			}
		}
		else if (number == 13)
		{
			if (bot_arr[x][y] == '0')
			{
				if ((x == ship11x && y == ship11y) || (x == ship12x && y == ship12y) || (x == ship13x && y == ship13y) || (x == ship14x && y == ship14y))
				{
					bot_ship1--;
					free_arr[x][y] = char(254);
					if (x > 0 && y > 0) free_arr[x - 1][y - 1] = free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = char(250);
					else if (x == 0 && y > 0 && y < 9) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 1][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = char(250);
					else if (x > 0 && x < 9 && y == 0) free_arr[x - 1][y] = free_arr[x + 1][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = char(250);
					else if (x == 0 && y == 0) free_arr[x + 1][y] = free_arr[x][y + 1] = free_arr[x + 1][y + 1] = char(250);
					else if (x == 0 && y == 9) free_arr[x][y - 1] = free_arr[x + 1][y - 1] = free_arr[x + 1][y] = char(250);
					else if (x == 9 && y == 0) free_arr[x - 1][y] = free_arr[x - 1][y + 1] = free_arr[x][y + 1] = char(250);
				}
				else free_arr[x][y] = 'X';
				find_destroyed_ship();
				attack_turn(1);
			}
			else free_arr[x][y] = char(250);
			attack_turn(0);
		}
		system("cls");
		attack_display();
	}
}

void find_destroyed_player_ship() {
	for (size_t x = 0; x < 10; x++)
	{
		for (size_t y = 0; y < 10; y++)
		{
			if (player_arr[x][y] == 'X')
			{
				if (x == player_ship21x && y == player_ship21y)
				{
					if (player_ship21 == 'v' && player_arr[x][y + 1] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x][y + 1] = char(254);
						ship2--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x][y + 2] = player_arr[x + 1][y + 2] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x - 1][y + 2] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
						attack_turn(0);
					}
					else if (player_ship21 == 'h' && player_arr[x + 1][y] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x + 1][y] = char(254);
						ship2--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						attack_turn(0);
					}
				}
				else if (x == player_ship22x && y == player_ship22y)
				{
					if (player_ship22 == 'v' && player_arr[x][y + 1] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x][y + 1] = char(254);
						ship2--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x][y + 2] = player_arr[x + 1][y + 2] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x - 1][y + 2] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
						attack_turn(0);
					}
					else if (player_ship22 == 'h' && player_arr[x + 1][y] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x + 1][y] = char(254);
						ship2--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						attack_turn(0);
					}
				}
				else if (x == player_ship23x && y == player_ship23y)
				{
					if (player_ship23 == 'v' && player_arr[x][y + 1] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x][y + 1] = char(254);
						ship2--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x][y + 2] = player_arr[x + 1][y + 2] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x - 1][y + 2] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
						attack_turn(0);
					}
					else if (player_ship23 == 'h' && player_arr[x + 1][y] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x + 1][y] = char(254);
						ship2--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
						attack_turn(0);
					}
				}
				else if (x == player_ship31x && y == player_ship31y)
				{
					if (player_ship31 == 'v' && player_arr[x][y + 1] == 'X' && player_arr[x][y + 2] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x][y + 1] = char(254);
						player_arr[x][y + 2] = char(254);
						ship3--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 3] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 3] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 3] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x][y + 3] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = char(250);
						attack_turn(0);
					}
					else if (player_ship31 == 'h' && player_arr[x + 1][y] == 'X' && player_arr[x + 2][y] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x + 1][y] = char(254);
						player_arr[x + 2][y] = char(254);
						ship3--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x - 1][y] = player_arr[x + 3][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 3][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 3][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 3][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
						attack_turn(0);
					}
				}
				else if (x == player_ship32x && y == player_ship32y)
				{
					if (player_ship32 == 'v' && player_arr[x][y + 1] == 'X' && player_arr[x][y + 2] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x][y + 1] = char(254);
						player_arr[x][y + 2] = char(254);
						ship3--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 3] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 3] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 3] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x][y + 3] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = char(250);
						attack_turn(0);
					}
					else if (player_ship32 == 'h' && player_arr[x + 1][y] == 'X' && player_arr[x + 2][y] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x + 1][y] = char(254);
						player_arr[x + 2][y] = char(254);
						ship3--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x - 1][y] = player_arr[x + 3][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 3][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 3][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 3][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
						attack_turn(0);
					}
				}

				else if (x == player_ship41x && y == player_ship41y)
				{
					if (player_ship41 == 'v' && player_arr[x][y + 1] == 'X' && player_arr[x][y + 2] == 'X' && player_arr[x][y + 3] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x][y + 1] = char(254);
						player_arr[x][y + 2] = char(254);
						player_arr[x][y + 3] = char(254);
						ship4--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 4] = player_arr[x - 1][y + 4] = player_arr[x + 1][y + 4] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x][y + 4] = player_arr[x + 1][y + 4] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 4] = player_arr[x - 1][y + 4] = player_arr[x + 1][y + 4] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x][y + 4] = player_arr[x + 1][y + 4] = char(250);
						attack_turn(0);
					}
					else if (player_ship41 == 'h' && player_arr[x + 1][y] == 'X' && player_arr[x + 2][y] == 'X' && player_arr[x + 3][y] == 'X')
					{
						player_arr[x][y] = char(254);
						player_arr[x + 1][y] = char(254);
						player_arr[x + 2][y] = char(254);
						player_arr[x + 3][y] = char(254);
						ship4--;
						if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 4][y - 1] = player_arr[x - 1][y] = player_arr[x + 4][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
						else if (x == 0 && y > 0) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 4][y - 1] = player_arr[x + 4][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
						else if (x > 0 && y == 0) player_arr[x - 1][y] = player_arr[x + 4][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
						else if (x == 0 && y == 0) player_arr[x + 4][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
						attack_turn(0);
					}
				}
			}
		}
	}
}

void attack_bot() {
	//for (size_t x = 0; x < 10; x++)
	//{
	//	for (size_t y = 0; y < 10; y++)
	//	{
	//		if (player_arr[x][y] == 'X')
	//		{
	//			int num = rand() % 4;
	//			if (num == 0 && player_arr[x + 1][y] == char(250))
	//			{
	//				num = 1 + rand() % 3;
	//				if (num == 1 && player_arr[x - 1][y] == char(250))
	//				{
	//					num = 2 + rand() % 2;
	//					if (num == 2 && player_arr[x][y + 1] == char(250)) num = 3;
	//					else num = 2;
	//					if (num == 3 && player_arr[x][y - 1] == char(250)) num = 2;
	//					else num = 3;
	//				}
	//				else num = 1;
	//				if (num == 2 && player_arr[x][y + 1] == char(250))
	//				{
	//					while (num != 1 && num != 3) num = rand() % 4;
	//					if (num == 1 && player_arr[x - 1][y] == char(250)) num = 3;
	//					else num = 1;
	//					if (num == 3 && player_arr[x][y - 1] == char(250)) num = 1;
	//					else num = 3;
	//				}
	//				else num = 2;
	//				if (num == 3 && player_arr[x][y - 1] == char(250))
	//				{
	//					num = 1 + rand() % 2;
	//					if (num == 2 && player_arr[x][y + 1] == char(250)) num = 1;
	//					else num = 2;
	//					if (num == 1 && player_arr[x - 1][y] == char(250)) num = 2;
	//					else num = 1;
	//				}
	//				else num = 3;
	//			}
	//			else if (num == 1 && player_arr[x - 1][y] == char(250))
	//			{
	//				while (num == 1) num = rand() % 4;
	//				if (num == 0 && player_arr[x + 1][y] == char(250))
	//				{
	//					while (num == 1 || num == 0) num = rand() % 4;
	//					if (num == 2 && player_arr[x][y + 1] == char(250)) num = 3;
	//					else num = 2;
	//					if (num == 3 && player_arr[x][y - 1] == char(250)) num = 2;
	//					else num = 3;
	//				}
	//				else num = 0;
	//				if (num == 2 && player_arr[x][y + 1] == char(250))
	//				{
	//					while (num != 0 && num != 3) num = rand() % 4;
	//					if (num == 0 && player_arr[x + 1][y] == char(250)) num = 3;
	//					else num = 0;
	//					if (num == 3 && player_arr[x][y - 1] == char(250)) num = 0;
	//					else num = 3;
	//				}
	//				else num = 2;
	//				if (num == 3 && player_arr[x][y - 1] == char(250))
	//				{
	//					while (num == 3 || num == 1) num = rand() % 4;
	//					if (num == 2 && player_arr[x][y + 1] == char(250)) num = 0;
	//					else num = 2;
	//					if (num == 0 && player_arr[x + 1][y] == char(250)) num = 2;
	//					else num = 0;
	//				}
	//				else num = 3;
	//			}
	//			else if (num == 2 && player_arr[x][y + 1] == char(250))
	//			{
	//				while (num == 2) num = rand() % 4;
	//				if (num == 0 && player_arr[x + 1][y] == char(250))
	//				{
	//					while (num == 2 || num == 0) num = rand() % 4;
	//					if (num == 1 && player_arr[x - 1][y] == char(250)) num = 3;
	//					else num = 1;
	//					if (num == 3 && player_arr[x][y - 1] == char(250)) num = 1;
	//					else num = 3;
	//				}
	//				else num = 0;
	//				if (num == 1 && player_arr[x - 1][y] == char(250))
	//				{
	//					while (num != 0 && num != 3) num = rand() % 4;
	//					if (num == 0 && player_arr[x + 1][y] == char(250)) num = 3;
	//					else num = 0;
	//					if (num == 3 && player_arr[x][y - 1] == char(250)) num = 0;
	//					else num = 3;
	//				}
	//				else num = 1;
	//				if (num == 3 && player_arr[x][y - 1] == char(250))
	//				{
	//					while (num == 1 || num == 0) num = rand() % 4;
	//					if (num == 1 && player_arr[x - 1][y] == char(250)) num = 0;
	//					else num = 1;
	//					if (num == 0 && player_arr[x + 1][y] == char(250)) num = 1;
	//					else num = 0;
	//				}
	//				else num = 3;
	//			}
	//			else if (num == 3 && player_arr[x][y - 1] == char(250))
	//			{
	//				while (num == 3) num = rand() % 4;
	//				if (num == 0 && player_arr[x + 1][y] == char(250))
	//				{
	//					while (num == 3 || num == 0) num = rand() % 4;
	//					if (num == 1 && player_arr[x - 1][y] == char(250)) num = 2;
	//					else num = 1;
	//					if (num == 2 && player_arr[x][y + 1] == char(250)) num = 1;
	//					else num = 2;
	//				}
	//				else num = 0;
	//				if (num == 1 && player_arr[x - 1][y] == char(250))
	//				{
	//					while (num != 0 && num != 2) num = rand() % 4;
	//					if (num == 0 && player_arr[x + 1][y] == char(250)) num = 2;
	//					else num = 0;
	//					if (num == 2 && player_arr[x][y + 1] == char(250)) num = 0;
	//					else num = 2;
	//				}
	//				else num = 1;
	//				if (num == 2 && player_arr[x][y + 1] == char(250))
	//				{
	//					while (num == 1 || num == 0) num = rand() % 4;
	//					if (num == 1 && player_arr[x - 1][y] == char(250)) num = 0;
	//					else num = 1;
	//					if (num == 0 && player_arr[x + 1][y] == char(250)) num = 1;
	//					else num = 0;
	//				}
	//				else num = 2;
	//			}
	//			switch (num)
	//			{
	//			case 0:
	//				if (player_arr[x + 1][y] == ' ')
	//				{
	//					player_arr[x + 1][y] = char(250);
	//					attack_turn(1);
	//					break;
	//				}
	//				else if (player_arr[x + 1][y] == '0')
	//				{
	//					player_arr[x + 1][y] = 'X';
	//					find_destroyed_player_ship();
	//					if (player_arr[x][y] == 'X')
	//					{
	//						player_arr[x + 2][y] = 'X';
	//						find_destroyed_player_ship();
	//						if (player_arr[x][y] == 'X')
	//						{
	//							player_arr[x + 2][y] = 'X';
	//							find_destroyed_player_ship();
	//						}
	//					}
	//				}
	//				break;
	//			case 1:
	//				if (player_arr[x - 1][y] == ' ')
	//				{
	//					player_arr[x - 1][y] = char(250);
	//					attack_turn(1);
	//					break;
	//				}
	//				else if (player_arr[x - 1][y] == '0')
	//				{
	//					player_arr[x - 1][y] = 'X';
	//					find_destroyed_player_ship();
	//					if (player_arr[x][y] == 'X')
	//					{
	//						player_arr[x - 2][y] = 'X';
	//						find_destroyed_player_ship();
	//						if (player_arr[x][y] == 'X')
	//						{
	//							player_arr[x - 2][y] = 'X';
	//							find_destroyed_player_ship();
	//						}
	//					}
	//				}
	//				break;
	//			case 2:
	//				if (player_arr[x][y + 1] == ' ')
	//				{
	//					player_arr[x][y + 1] = char(250);
	//					attack_turn(1);
	//					break;
	//				}
	//				else if (player_arr[x][y + 1] == '0')
	//				{
	//					player_arr[x][y + 1] = 'X';
	//					find_destroyed_player_ship();
	//					if (player_arr[x][y] == 'X')
	//					{
	//						player_arr[x][y + 2] = 'X';
	//						find_destroyed_player_ship();
	//						if (player_arr[x][y] == 'X')
	//						{
	//							player_arr[x][y + 2] = 'X';
	//							find_destroyed_player_ship();
	//						}
	//					}
	//				}
	//				break;
	//			case 3:
	//				player_arr[x][y - 1] = 'X';
	//				if (player_arr[x][y - 1] == ' ')
	//				{
	//					player_arr[x][y - 1] = char(250);
	//					attack_turn(1);
	//					break;
	//				}
	//				else if (player_arr[x][y - 1] == '0')
	//				{
	//					player_arr[x][y - 1] = 'X';
	//					find_destroyed_player_ship();
	//					if (player_arr[x][y] == 'X')
	//					{
	//						player_arr[x][y - 2] = 'X';
	//						find_destroyed_player_ship();
	//						if (player_arr[x][y] == 'X')
	//						{
	//							player_arr[x][y - 2] = 'X';
	//							find_destroyed_player_ship();
	//						}
	//					}
	//				}
	//				break;
	//			}
	//		}
	//	}
	//}
	int x = 0, y = 0;
	while (true)
	{
		x = rand() % 10;
		y = rand() % 10;
		if (player_arr[x][y] == ' ' || player_arr[x][y] == '0')
		{
			if (player_arr[x][y] == ' ')
			{
				player_arr[x][y] = char(250);
				attack_turn(1);
			}
			else if (player_arr[x][y] == '0')
			{
				if ((x == player_ship11x && y == player_ship11y) || (x == player_ship12x && y == player_ship12y) || (x == player_ship13x && y == player_ship13y) || (x == player_ship14x && y == player_ship14y))
				{
					ship1--;
					player_arr[x][y] = char(254);
					if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
					else if (x == 0 && y > 0 && y < 9) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
					else if (x > 0 && x < 9 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
					else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
					else if (x == 0 && y == 9) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = char(250);
					else if (x == 9 && y == 0) player_arr[x - 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = char(250);
					attack_turn(0);
				}
				else
				{
					player_arr[x][y] = 'X';
					find_destroyed_player_ship();
					attack_turn(0);
				}
				//else
				//{
				//	player_arr[x][y] = 'X';
				//	attack_turn(0);
				//	int num = rand() % 4;
				//	switch (num)
				//	{
				//	case 0:
				//		if (player_arr[x + 1][y] == ' ')
				//		{
				//			player_arr[x + 1][y] = char(250);
				//			attack_turn(1);
				//			break;
				//		}
				//		else if (player_arr[x + 1][y] == '0')
				//		{
				//			player_arr[x + 1][y] = 'X';
				//			find_destroyed_player_ship();
				//			if (player_arr[x][y] == 'X')
				//			{
				//				player_arr[x + 2][y] = 'X';
				//				find_destroyed_player_ship();
				//				if (player_arr[x][y] == 'X')
				//				{
				//					player_arr[x + 2][y] = 'X';
				//					find_destroyed_player_ship();
				//				}
				//			}
				//		}
				//		break;
				//	case 1:
				//		if (player_arr[x - 1][y] == ' ')
				//		{
				//			player_arr[x - 1][y] = char(250);
				//			attack_turn(1);
				//			break;
				//		}
				//		else if (player_arr[x - 1][y] == '0')
				//		{
				//			player_arr[x - 1][y] = 'X';
				//			find_destroyed_player_ship();
				//			if (player_arr[x][y] == 'X')
				//			{
				//				player_arr[x - 2][y] = 'X';
				//				find_destroyed_player_ship();
				//				if (player_arr[x][y] == 'X')
				//				{
				//					player_arr[x - 2][y] = 'X';
				//					find_destroyed_player_ship();
				//				}
				//			}
				//		}

				//		break;
				//	case 2:
				//		if (player_arr[x][y + 1] == ' ')
				//		{
				//			player_arr[x][y + 1] = char(250);
				//			attack_turn(1);
				//			break;
				//		}
				//		else if (player_arr[x][y + 1] == '0')
				//		{
				//			player_arr[x][y + 1] = 'X';
				//			find_destroyed_player_ship();
				//			if (player_arr[x][y] == 'X')
				//			{
				//				player_arr[x][y + 2] = 'X';
				//				find_destroyed_player_ship();
				//				if (player_arr[x][y] == 'X')
				//				{
				//					player_arr[x][y + 2] = 'X';
				//					find_destroyed_player_ship();
				//				}
				//			}
				//		}
				//		break;
				//	case 3:
				//		player_arr[x][y - 1] = 'X';
				//		if (player_arr[x][y - 1] == ' ')
				//		{
				//			player_arr[x][y - 1] = char(250);
				//			attack_turn(1);
				//			break;
				//		}
				//		else if (player_arr[x][y - 1] == '0')
				//		{
				//			player_arr[x][y - 1] = 'X';
				//			find_destroyed_player_ship();
				//			if (player_arr[x][y] == 'X')
				//			{
				//				player_arr[x][y - 2] = 'X';
				//				find_destroyed_player_ship();
				//				if (player_arr[x][y] == 'X')
				//				{
				//					player_arr[x][y - 2] = 'X';
				//					find_destroyed_player_ship();
				//				}
				//			}
				//		}
				//		break;
				//	}
				//}
			}
		}
	}
}

void locate_display() {
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 0) cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << char(186);
		for (size_t j = 0; j < 10; j++)
		{
			if (player_arr[i][j] == '0')
			{
				if (j == 0 && player_arr[i][j + 1] != '0') print_color(" 0 ", 2);
				else if (player_arr[i][j + 1] == '0') print_color(" 0", 2);
				else print_color(" 0 ", 2);
			}
			else
			{
				if (j == 0) cout << ' ';
				if (player_arr[i][j + 1] == '0') cout << player_arr[i][j];
				else cout << player_arr[i][j] << ' ';
			}
		}
		cout << char(186) << endl;
		if (i == 9) {
			cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
			if ((ship1 + ship2 + ship3 + ship4) != 0)
			{
				if (language == 'e')
				{
					cout << "REMAINING SHIPS : " << endl;
					cout << "<<Destroyer(1)>> ~ " << ship1 << endl;
					cout << "<<SubMarine(2)>> ~ " << ship2 << endl;
					cout << "<<BattleShip(3)>> ~ " << ship3 << endl;
					cout << "<<Carrier(4)>> ~ " << ship4 << endl;
					cout << "\n\n--> Press B to return to previous page" << endl;
					cout << "--> Press SPACE to rotate ship" << endl;
				}
				else if (language == 'a')
				{
					cout << "Qalan Gemiler : " << endl;
					cout << "<<Dagidici(1)>> ~ " << ship1 << endl;
					cout << "<<SualtiQayiq(2)>> ~ " << ship2 << endl;
					cout << "<<BattleShip(3)>> ~ " << ship3 << endl;
					cout << "<<Dasiyici(4)>> ~ " << ship4 << endl;
					cout << "\n\n--> Geri qayitmaq ucun B bas" << endl;
					cout << "--> Gemini dondermek ucun SPACE bas" << endl;
				}
			}
		}
	}
}

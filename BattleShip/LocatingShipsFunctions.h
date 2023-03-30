#pragma once

void manual_auto_locate();

void locate_ship1() {
	int x = 0, y = 0;
	while (true)
	{
		x = rand() % 10;
		y = rand() % 10;
		if (player_arr[x][y] == ' ') {
			player_arr[x][y] = '0';
			system("cls");
			locate_display();
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
				player_arr[x][y] = char(32);
				int a = x, b = y;
				while (player_arr[x - 1][y] != ' ' && x > 0) x--;
				if ((x - 1) >= 0)x--;
				else x += 9;
				if (player_arr[x][y] != ' ') while (player_arr[x][y] != ' ') x--;
				if (a == x && b == y)
				{
					while (true)
					{
						x = rand() % 10;
						y = rand() % 10;
						if (player_arr[x][y] == ' ') break;
					}
				}
				player_arr[x][y] = '0';
			}
			else if (number == 80) {
				player_arr[x][y] = char(32);
				int a = x, b = y;
				while (player_arr[x + 1][y] != ' ' && x < 9) x++;
				if ((x + 1) <= 9)x++;
				else x -= 9;
				if (player_arr[x][y] != ' ') while (player_arr[x][y] != ' ') x++;
				if (a == x && b == y)
				{
					while (true)
					{
						x = rand() % 10;
						y = rand() % 10;
						if (player_arr[x][y] == ' ') break;
					}
				}
				player_arr[x][y] = '0';
			}
			else if (number == 75) {
				player_arr[x][y] = char(32);
				int a = x, b = y;
				while (player_arr[x][y - 1] != ' ' && y > 0) y--;
				if ((y - 1) >= 0)y--;
				else y += 9;
				if (player_arr[x][y] != ' ') while (player_arr[x][y] != ' ') y--;
				if (a == x && b == y)
				{
					while (true)
					{
						x = rand() % 10;
						y = rand() % 10;
						if (player_arr[x][y] == ' ') break;
					}
				}
				player_arr[x][y] = '0';
			}
			else if (number == 77) {
				player_arr[x][y] = char(32);
				int a = x, b = y;
				while (player_arr[x][y + 1] != ' ' && y < 9) y++;
				if ((y + 1) <= 9) y++;
				else y -= 9;
				if (player_arr[x][y] != ' ') while (player_arr[x][y] != ' ') y++;
				if (a == x && b == y)
				{
					while (true)
					{
						x = rand() % 10;
						y = rand() % 10;
						if (player_arr[x][y] == ' ') break;
					}
				}
				player_arr[x][y] = '0';
			}
		}
		else if (number == 13)
		{
			switch (ship1)
			{
			case 1:
				player_ship11x = x;
				player_ship11y = y;
				break;
			case 2:
				player_ship12x = x;
				player_ship12y = y;
				break;
			case 3:
				player_ship13x = x;
				player_ship13y = y;
				break;
			case 4:
				player_ship14x = x;
				player_ship14y = y;
				break;
			}
			if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
			else if (x == 0 && y > 0 && y < 9) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
			else if (x > 0 && x < 9 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
			else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
			else if (x == 0 && y == 9) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = char(250);
			else if (x == 9 && y == 0) player_arr[x - 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = char(250);
			system("cls");
			ship1--;
			locate_display();
			locate_ships();
		}
		else if (number == 98 || number == 66)
		{
			fillplayer_arr();
			ship1 = 4;
			ship2 = 3;
			ship3 = 2;
			ship4 = 1;
			manual_auto_locate();
		}
		system("cls");
		locate_display();
	}
}

void locate_ship2() {
	int x = 0, y = 0, n = 0, k = 1;
	while (true)
	{
		x = rand() % 10;
		y = rand() % 10;
		if (player_arr[x][y] == ' ' && player_arr[x][y + 1] == ' ' && y < 9) {
			player_arr[x][y] = '0';
			player_arr[x + n][y + k] = '0';
			system("cls");
			locate_display();
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
				player_arr[x][y] = ' ';
				player_arr[x + n][y + k] = ' ';
				while (k == 1 && (player_arr[x - 1][y] != ' ' || player_arr[x - 1][y + 1] != ' ') && x > 0) x--;
				while (n == 1 && (player_arr[x - 1][y] != ' ' || player_arr[x][y] != ' ') && x > 0) x--;
				if ((x - 1) >= 0) x--;
				else if (n == 1) x += 8;
				else x += 9;
				if ((player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') && k == 1) while (player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') x--;
				else if ((player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') && n == 1) while (player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') x--;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
			}
			else if (number == 80) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				while (k == 1 && (player_arr[x + 1][y] != ' ' || player_arr[x + 1][y + 1] != ' ') && x < 9) x++;
				while (n == 1 && player_arr[x + 2][y] != ' ' && x < 8) x++;
				if (k == 1 && (x + 1) <= 9) x++;
				else if (n == 1 && (x + 1) <= 8) x++;
				else if (k == 1) x -= 9;
				else x -= 8;
				if ((player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') && k == 1) while (player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') x++;
				else if ((player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') && n == 1) while (player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') x++;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
			}
			else if (number == 75) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				while (k == 1 && (player_arr[x][y - 1] != ' ' || player_arr[x][y] != ' ') && y > 0) y--;
				while (n == 1 && (player_arr[x][y - 1] != ' ' || player_arr[x + 1][y - 1] != ' ') && y > 0) y--;
				if ((y - 1) >= 0) y--;
				else if (k == 1) y += 8;
				else y += 9;
				if ((player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') && k == 1) while (player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') y--;
				else if ((player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') && n == 1) while (player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') y--;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
			}
			else if (number == 77) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				while (n == 1 && (player_arr[x][y + 1] != ' ' || player_arr[x + 1][y + 1] != ' ') && y < 9) y++;
				while (k == 1 && player_arr[x][y + 2] != ' ' && y < 8) y++;
				if (k == 1 && (y + 1) <= 8) y++;
				else if (n == 1 && (y + 1) <= 9) y++;
				else if (n == 1) y -= 9;
				else y -= 8;
				if ((player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') && k == 1) while (player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') y++;
				else if ((player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') && n == 1) while (player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') y++;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
			}
		}
		else if (number == 32 && (player_arr[x][y + 1] == ' ' || player_arr[x + 1][y] == ' '))
		{
			player_arr[x + n][y + k] = ' ';
			if (n == 1 && y < 9)
			{
				n = 0;
				k = 1;
			}
			else if (k == 1 && x < 9)
			{
				n = 1;
				k = 0;
			}
			else cout << "\a";
			player_arr[x + n][y + k] = '0';
		}
		else if (number == 32) cout << "\a";
		else if (number == 13)
		{
			switch (ship2)
			{
			case 1:
				player_ship21x = x;
				player_ship21y = y;
				if (n == 1) player_ship21 = 'h';
				break;
			case 2:
				player_ship22x = x;
				player_ship22y = y;
				if (n == 1) player_ship22 = 'h';
				break;
			case 3:
				player_ship23x = x;
				player_ship23y = y;
				if (n == 1) player_ship23 = 'h';
				break;
			}
			if (x > 0 && y > 0 && k == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x][y + 2] = player_arr[x + 1][y + 2] = char(250);
			else if (x > 0 && y > 0 && n == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
			else if (x == 0 && y > 0 && k == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
			else if (x == 0 && y > 0 && n == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
			else if (x > 0 && y == 0 && k == 1) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x - 1][y + 2] = char(250);
			else if (x > 0 && y == 0 && n == 1) player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
			else if (x == 0 && y == 0 && k == 1) player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
			else if (x == 0 && y == 0 && n == 1) player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
			system("cls");
			locate_display();
			ship2--;
			locate_ships();
		}
		else if (number == 98 || number == 66)
		{
			fillplayer_arr();
			ship1 = 4;
			ship2 = 3;
			ship3 = 2;
			ship4 = 1;
			manual_auto_locate();
		}
		system("cls");
		locate_display();
	}
}

void locate_ship3() {
	int x = 0, y = 0, n = 0, k = 1;
	while (true)
	{
		x = rand() % 10;
		y = rand() % 10;
		if (player_arr[x][y] == ' ' && player_arr[x][y + 1] == ' ' && player_arr[x][y + 2] == ' ' && y < 8) {
			player_arr[x][y] = '0';
			player_arr[x + n][y + k] = '0';
			player_arr[x + n + n][y + k + k] = '0';
			system("cls");
			locate_display();
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
				player_arr[x][y] = ' ';
				player_arr[x + n][y + k] = ' ';
				player_arr[x + n + n][y + k + k] = ' ';
				while (k == 1 && (player_arr[x - 1][y] != ' ' || player_arr[x - 1][y + 1] != ' ' || player_arr[x - 1][y + 2] != ' ') && x > 0) x--;
				while (n == 1 && (player_arr[x - 1][y] != ' ' || player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ') && x > 0) x--;
				if ((x - 1) >= 0) x--;
				else if (n == 1) x += 7;
				else x += 9;
				if ((player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ' || player_arr[x][y + 2] != ' ') && k == 1) while (player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ' || player_arr[x][y + 2] != ' ') x--;
				else if ((player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ' || player_arr[x + 2][y] != ' ') && n == 1) while (player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ' || player_arr[x + 2][y] != ' ') x--;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
			}
			else if (number == 80) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				player_arr[x + n + n][y + k + k] = ' ';
				while (k == 1 && (player_arr[x + 1][y] != ' ' || player_arr[x + 1][y + 1] != ' ' || player_arr[x + 1][y + 2] != ' ') && x < 9) x++;
				while (n == 1 && player_arr[x + 3][y] != ' ' && x < 7) x++;
				if (k == 1 && (x + 1) <= 9) x++;
				else if (n == 1 && (x + 1) <= 7) x++;
				else if (k == 1) x -= 9;
				else x -= 7;
				if ((player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ' || player_arr[x][y + 2] != ' ') && k == 1) while (player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ' || player_arr[x][y + 2] != ' ') x++;
				else if ((player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ' || player_arr[x + 2][y] != ' ') && n == 1) while (player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ' || player_arr[x + 2][y] != ' ') x++;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
			}
			else if (number == 75) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				player_arr[x + n + n][y + k + k] = ' ';
				while (k == 1 && (player_arr[x][y - 1] != ' ' || player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ') && y > 0) y--;
				while (n == 1 && (player_arr[x][y - 1] != ' ' || player_arr[x + 1][y - 1] != ' ' || player_arr[x + 2][y - 1] != ' ') && y > 0) y--;
				if ((y - 1) >= 0) y--;
				else if (k == 1) y += 7;
				else y += 9;
				if ((player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ' || player_arr[x][y + 2] != ' ') && k == 1) while (player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ' || player_arr[x][y + 2] != ' ') y--;
				else if ((player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ' || player_arr[x + 2][y] != ' ') && n == 1) while (player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ' || player_arr[x + 2][y] != ' ') y--;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
			}
			else if (number == 77) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				player_arr[x + n + n][y + k + k] = ' ';
				while (n == 1 && (player_arr[x][y + 1] != ' ' || player_arr[x + 1][y + 1] != ' ' || player_arr[x + 2][y + 1] != ' ') && y < 9) y++;
				while (k == 1 && player_arr[x][y + 3] != ' ' && y < 7) y++;
				if (k == 1 && (y + 1) <= 7) y++;
				else if (n == 1 && (y + 1) <= 9) y++;
				else if (n == 1) y -= 9;
				else y -= 7;
				if ((player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ' || player_arr[x][y + 2] != ' ') && k == 1) while (player_arr[x][y] != ' ' || player_arr[x][y + 1] != ' ' || player_arr[x][y + 2] != ' ') y++;
				else if ((player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ' || player_arr[x + 2][y] != ' ') && n == 1) while (player_arr[x][y] != ' ' || player_arr[x + 1][y] != ' ' || player_arr[x + 2][y] != ' ') y++;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
			}
		}
		else if (number == 32 && ((player_arr[x][y + 1] == ' ' && player_arr[x][y + 2]) || (player_arr[x + 1][y] == ' ' && player_arr[x + 2][y] == ' ')))
		{
			player_arr[x + n][y + k] = ' ';
			player_arr[x + n + n][y + k + k] = ' ';
			if (n == 1 && y < 8)
			{
				n = 0;
				k = 1;
			}
			else if (k == 1 && x < 8)
			{
				n = 1;
				k = 0;
			}
			else cout << "\a";
			player_arr[x + n][y + k] = '0';
			player_arr[x + n + n][y + k + k] = '0';
		}
		else if (number == 32) cout << "\a";
		else if (number == 13)
		{
			switch (ship3)
			{
			case 1:
				player_ship31x = x;
				player_ship31y = y;
				if (n == 1) player_ship31 = 'h';
				break;
			case 2:
				player_ship32x = x;
				player_ship32y = y;
				if (n == 1) player_ship32 = 'h';
				break;
			}
			if (x > 0 && y > 0 && k == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 3] = char(250);
			else if (x > 0 && y > 0 && n == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x - 1][y] = player_arr[x + 3][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
			else if (x == 0 && y > 0 && k == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 3] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = char(250);
			else if (x == 0 && y > 0 && n == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 3][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
			else if (x > 0 && y == 0 && k == 1) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 3] = char(250);
			else if (x > 0 && y == 0 && n == 1) player_arr[x - 1][y] = player_arr[x + 3][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
			else if (x == 0 && y == 0 && k == 1) player_arr[x + 1][y] = player_arr[x][y + 3] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = char(250);
			else if (x == 0 && y == 0 && n == 1) player_arr[x + 3][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
			system("cls");
			locate_display();
			ship3--;
			locate_ships();
		}
		else if (number == 98 || number == 66)
		{
			fillplayer_arr();
			ship1 = 4;
			ship2 = 3;
			ship3 = 2;
			ship4 = 1;
			manual_auto_locate();
		}
		system("cls");
		locate_display();
	}
}

void locate_ship4() {
	int x = 0, y = 0, n = 0, k = 1;
	while (true)
	{
		x = rand() % 10;
		y = rand() % 10;
		if (y < 7) {
			player_arr[x][y] = '0';
			player_arr[x + n][y + k] = '0';
			player_arr[x + n + n][y + k + k] = '0';
			player_arr[x + n + n + n][y + k + k + k] = '0';
			system("cls");
			locate_display();
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
				player_arr[x][y] = ' ';
				player_arr[x + n][y + k] = ' ';
				player_arr[x + n + n][y + k + k] = ' ';
				player_arr[x + n + n + n][y + k + k + k] = ' ';
				if ((x - 1) >= 0) x--;
				else if (n == 1) x += 6;
				else x += 9;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
				player_arr[x + n + n + n][y + k + k + k] = '0';
			}
			else if (number == 80) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				player_arr[x + n + n][y + k + k] = ' ';
				player_arr[x + n + n + n][y + k + k + k] = ' ';
				if (k == 1 && (x + 1) <= 9) x++;
				else if (n == 1 && (x + 1) <= 6) x++;
				else if (k == 1) x -= 9;
				else x -= 6;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
				player_arr[x + n + n + n][y + k + k + k] = '0';
			}
			else if (number == 75) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				player_arr[x + n + n][y + k + k] = ' ';
				player_arr[x + n + n + n][y + k + k + k] = ' ';
				if ((y - 1) >= 0) y--;
				else if (k == 1) y += 6;
				else y += 9;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
				player_arr[x + n + n + n][y + k + k + k] = '0';
			}
			else if (number == 77) {
				player_arr[x][y] = char(32);
				player_arr[x + n][y + k] = ' ';
				player_arr[x + n + n][y + k + k] = ' ';
				player_arr[x + n + n + n][y + k + k + k] = ' ';
				if (k == 1 && (y + 1) <= 6) y++;
				else if (n == 1 && (y + 1) <= 9) y++;
				else if (n == 1) y -= 9;
				else y -= 6;
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
				player_arr[x + n + n + n][y + k + k + k] = '0';
			}
		}
		else if (number == 32)
		{
			player_arr[x + n][y + k] = ' ';
			player_arr[x + n + n][y + k + k] = ' ';
			player_arr[x + n + n + n][y + k + k + k] = ' ';
			if (n == 1 && y < 7)
			{
				n = 0;
				k = 1;
			}
			else if (k == 1 && x < 7)
			{
				n = 1;
				k = 0;
			}
			else cout << "\a";
			player_arr[x + n][y + k] = '0';
			player_arr[x + n + n][y + k + k] = '0';
			player_arr[x + n + n + n][y + k + k + k] = '0';
		}
		else if (number == 32) cout << "\a";
		else if (number == 13)
		{
			switch (ship4)
			{
			case 1:
				player_ship41x = x;
				player_ship41y = y;
				if (n == 1) player_ship41 = 'h';
				break;
			}
			if (x > 0 && y > 0 && k == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 4] = player_arr[x - 1][y + 4] = player_arr[x + 1][y + 4] = char(250);
			else if (x > 0 && y > 0 && n == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 4][y - 1] = player_arr[x - 1][y] = player_arr[x + 4][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
			else if (x == 0 && y > 0 && k == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x][y + 4] = player_arr[x + 1][y + 4] = char(250);
			else if (x == 0 && y > 0 && n == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 4][y - 1] = player_arr[x + 4][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
			else if (x > 0 && y == 0 && k == 1) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 4] = player_arr[x - 1][y + 4] = player_arr[x + 1][y + 4] = char(250);
			else if (x > 0 && y == 0 && n == 1) player_arr[x - 1][y] = player_arr[x + 4][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
			else if (x == 0 && y == 0 && k == 1) player_arr[x + 1][y] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x][y + 4] = player_arr[x + 1][y + 4] = char(250);
			else if (x == 0 && y == 0 && n == 1) player_arr[x + 4][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
			system("cls");
			locate_display();
			ship4--;
			locate_ships();
		}
		else if (number == 98 || number == 66)
		{
			fillplayer_arr();
			ship1 = 4;
			ship2 = 3;
			ship3 = 2;
			ship4 = 1;
			manual_auto_locate();
		}
		system("cls");
		locate_display();
	}
}

void locate_bot_ships() {
	system("cls");
	srand(time(0));
	int x = 0, y = 0, n = 0, k = 1;
	int random = 0;
	while (bot_ship4 > 0)
	{
		while (true)
		{
			random = rand() % 2;
			if (random == 1)
			{
				n = 1;
				k = 0;
			}
			x = rand() % 10;
			y = rand() % 10;
			if ((k == 1 && y < 7) || (n == 1 && x < 7)) {
				switch (bot_ship4)
				{
				case 1:
					ship41x = x;
					ship41y = y;
					if (n == 1) ship41 = 'h';
					break;
				}
				bot_arr[x][y] = '0';
				bot_arr[x + n][y + k] = '0';
				bot_arr[x + n + n][y + k + k] = '0';
				bot_arr[x + n + n + n][y + k + k + k] = '0';
				bot_ship4--;
				if (x > 0 && y > 0 && k == 1) bot_arr[x - 1][y - 1] = bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x - 1][y] = bot_arr[x + 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x - 1][y + 2] = bot_arr[x + 1][y + 2] = bot_arr[x + 1][y + 3] = bot_arr[x - 1][y + 3] = bot_arr[x][y + 4] = bot_arr[x - 1][y + 4] = bot_arr[x + 1][y + 4] = char(250);
				else if (x > 0 && y > 0 && n == 1) bot_arr[x - 1][y - 1] = bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 2][y - 1] = bot_arr[x + 3][y - 1] = bot_arr[x + 4][y - 1] = bot_arr[x - 1][y] = bot_arr[x + 4][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = bot_arr[x + 3][y + 1] = bot_arr[x + 4][y + 1] = char(250);
				else if (x == 0 && y > 0 && k == 1) bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 1][y] = bot_arr[x + 1][y + 1] = bot_arr[x + 1][y + 2] = bot_arr[x + 1][y + 3] = bot_arr[x][y + 4] = bot_arr[x + 1][y + 4] = char(250);
				else if (x == 0 && y > 0 && n == 1) bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 2][y - 1] = bot_arr[x + 3][y - 1] = bot_arr[x + 4][y - 1] = bot_arr[x + 4][y] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = bot_arr[x + 3][y + 1] = bot_arr[x + 4][y + 1] = char(250);
				else if (x > 0 && y == 0 && k == 1) bot_arr[x - 1][y] = bot_arr[x + 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x - 1][y + 2] = bot_arr[x + 1][y + 2] = bot_arr[x + 1][y + 3] = bot_arr[x - 1][y + 3] = bot_arr[x][y + 4] = bot_arr[x - 1][y + 4] = bot_arr[x + 1][y + 4] = char(250);
				else if (x > 0 && y == 0 && n == 1) bot_arr[x - 1][y] = bot_arr[x + 4][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = bot_arr[x + 3][y + 1] = bot_arr[x + 4][y + 1] = char(250);
				else if (x == 0 && y == 0 && k == 1) bot_arr[x + 1][y] = bot_arr[x + 1][y + 1] = bot_arr[x + 1][y + 2] = bot_arr[x + 1][y + 3] = bot_arr[x][y + 4] = bot_arr[x + 1][y + 4] = char(250);
				else if (x == 0 && y == 0 && n == 1) bot_arr[x + 4][y] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = bot_arr[x + 3][y + 1] = bot_arr[x + 4][y + 1] = char(250);
				break;
			}
		}
	}
	while (bot_ship3 > 0)
	{
		while (true)
		{
			random = rand() % 2;
			if (random == 1)
			{
				n = 1;
				k = 0;
			}
			else {
				n = 0;
				k = 1;
			}
			x = rand() % 10;
			y = rand() % 10;
			if ((k == 1 && bot_arr[x][y] == ' ' && bot_arr[x][y + 1] == ' ' && bot_arr[x][y + 2] == ' ' && y < 8) || (n == 1 && bot_arr[x][y] == ' ' && bot_arr[x + 1][y] == ' ' && bot_arr[x + 2][y] == ' ' && x < 8))
			{
				switch (bot_ship3)
				{
				case 1:
					ship31x = x;
					ship31y = y;
					if (n == 1) ship31 = 'h';
					break;
				case 2:
					ship32x = x;
					ship32y = y;
					if (n == 1) ship32 = 'h';
					break;
				}
				bot_arr[x][y] = '0';
				bot_arr[x + n][y + k] = '0';
				bot_arr[x + n + n][y + k + k] = '0';
				bot_ship3--;
				if (x > 0 && y > 0 && k == 1) bot_arr[x - 1][y - 1] = bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x - 1][y] = bot_arr[x + 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x - 1][y + 2] = bot_arr[x + 1][y + 2] = bot_arr[x + 1][y + 3] = bot_arr[x - 1][y + 3] = bot_arr[x][y + 3] = char(250);
				else if (x > 0 && y > 0 && n == 1) bot_arr[x - 1][y - 1] = bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 2][y - 1] = bot_arr[x + 3][y - 1] = bot_arr[x - 1][y] = bot_arr[x + 3][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = bot_arr[x + 3][y + 1] = char(250);
				else if (x == 0 && y > 0 && k == 1) bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 1][y] = bot_arr[x][y + 3] = bot_arr[x + 1][y + 1] = bot_arr[x + 1][y + 2] = bot_arr[x + 1][y + 3] = char(250);
				else if (x == 0 && y > 0 && n == 1) bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 2][y - 1] = bot_arr[x + 3][y - 1] = bot_arr[x + 3][y] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = bot_arr[x + 3][y + 1] = char(250);
				else if (x > 0 && y == 0 && k == 1) bot_arr[x - 1][y] = bot_arr[x + 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x - 1][y + 2] = bot_arr[x + 1][y + 2] = bot_arr[x + 1][y + 3] = bot_arr[x - 1][y + 3] = bot_arr[x][y + 3] = char(250);
				else if (x > 0 && y == 0 && n == 1) bot_arr[x - 1][y] = bot_arr[x + 3][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = bot_arr[x + 3][y + 1] = char(250);
				else if (x == 0 && y == 0 && k == 1) bot_arr[x + 1][y] = bot_arr[x][y + 3] = bot_arr[x + 1][y + 1] = bot_arr[x + 1][y + 2] = bot_arr[x + 1][y + 3] = char(250);
				else if (x == 0 && y == 0 && n == 1) bot_arr[x + 3][y] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = bot_arr[x + 3][y + 1] = char(250);
				break;
			}
		}
	}
	while (bot_ship2 > 0)
	{
		while (true)
		{
			random = rand() % 2;
			if (random == 1)
			{
				n = 1;
				k = 0;
			}
			else {
				n = 0;
				k = 1;
			}
			x = rand() % 10;
			y = rand() % 10;
			if ((k == 1 && bot_arr[x][y] == ' ' && bot_arr[x][y + 1] == ' ' && y < 9) || (n == 1 && bot_arr[x][y] == ' ' && bot_arr[x + 1][y] == ' ' && x < 9))
			{
				switch (bot_ship2)
				{
				case 1:
					ship21x = x;
					ship21y = y;
					if (n == 1) ship21 = 'h';
					break;
				case 2:
					ship22x = x;
					ship22y = y;
					if (n == 1) ship22 = 'h';
					break;
				case 3:
					ship23x = x;
					ship23y = y;
					if (n == 1) ship23 = 'h';
					break;
				}
				bot_arr[x][y] = '0';
				bot_arr[x + n][y + k] = '0';
				bot_ship2--;
				if (x > 0 && y > 0 && k == 1) bot_arr[x - 1][y - 1] = bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x - 1][y] = bot_arr[x + 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x - 1][y + 2] = bot_arr[x][y + 2] = bot_arr[x + 1][y + 2] = char(250);
				else if (x > 0 && y > 0 && n == 1) bot_arr[x - 1][y - 1] = bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 2][y - 1] = bot_arr[x - 1][y] = bot_arr[x + 2][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = char(250);
				else if (x == 0 && y > 0 && k == 1) bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 1][y] = bot_arr[x][y + 2] = bot_arr[x + 1][y + 1] = bot_arr[x + 1][y + 2] = char(250);
				else if (x == 0 && y > 0 && n == 1) bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 2][y - 1] = bot_arr[x + 2][y] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = char(250);
				else if (x > 0 && y == 0 && k == 1) bot_arr[x - 1][y] = bot_arr[x + 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 2] = bot_arr[x + 1][y + 1] = bot_arr[x + 1][y + 2] = bot_arr[x - 1][y + 2] = char(250);
				else if (x > 0 && y == 0 && n == 1) bot_arr[x - 1][y] = bot_arr[x + 2][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = char(250);
				else if (x == 0 && y == 0 && k == 1) bot_arr[x + 1][y] = bot_arr[x][y + 2] = bot_arr[x + 1][y + 1] = bot_arr[x + 1][y + 2] = char(250);
				else if (x == 0 && y == 0 && n == 1) bot_arr[x + 2][y] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = bot_arr[x + 2][y + 1] = char(250);
				break;
			}
		}
	}
	while (bot_ship1 > 0)
	{
		while (true)
		{
			x = rand() % 10;
			y = rand() % 10;
			if (bot_arr[x][y] == ' ') {
				switch (bot_ship1)
				{
				case 1:
					ship11x = x;
					ship11y = y;
					break;
				case 2:
					ship12x = x;
					ship12y = y;
					break;
				case 3:
					ship13x = x;
					ship13y = y;
					break;
				case 4:
					ship14x = x;
					ship14y = y;
					break;
				}
				bot_arr[x][y] = '0';
				bot_ship1--;
				if (x > 0 && y > 0) bot_arr[x - 1][y - 1] = bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x - 1][y] = bot_arr[x + 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = char(250);
				else if (x == 0 && y > 0 && y < 9) bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 1][y] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = char(250);
				else if (x > 0 && x < 9 && y == 0) bot_arr[x - 1][y] = bot_arr[x + 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = char(250);
				else if (x == 0 && y == 0) bot_arr[x + 1][y] = bot_arr[x][y + 1] = bot_arr[x + 1][y + 1] = char(250);
				else if (x == 0 && y == 9) bot_arr[x][y - 1] = bot_arr[x + 1][y - 1] = bot_arr[x + 1][y] = char(250);
				else if (x == 9 && y == 0) bot_arr[x - 1][y] = bot_arr[x - 1][y + 1] = bot_arr[x][y + 1] = char(250);
				break;
			}
		}
	}
	bot_ship1 = 4;
	bot_ship2 = 3;
	bot_ship3 = 2;
	bot_ship4 = 1;
}

void locate_auto_ships() {
	system("cls");
	srand(time(0));
	int x = 0, y = 0, n = 0, k = 1;
	int random = 0;
	while (ship4 > 0)
	{
		while (true)
		{
			random = rand() % 2;
			if (random == 1)
			{
				n = 1;
				k = 0;
			}
			x = rand() % 10;
			y = rand() % 10;
			if ((k == 1 && y < 7) || (n == 1 && x < 7)) {
				switch (ship4)
				{
				case 1:
					player_ship41x = x;
					player_ship41y = y;
					if (n == 1) player_ship41 = 'h';
					break;
				}
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
				player_arr[x + n + n + n][y + k + k + k] = '0';
				ship4--;
				if (x > 0 && y > 0 && k == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 4] = player_arr[x - 1][y + 4] = player_arr[x + 1][y + 4] = char(250);
				else if (x > 0 && y > 0 && n == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 4][y - 1] = player_arr[x - 1][y] = player_arr[x + 4][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
				else if (x == 0 && y > 0 && k == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x][y + 4] = player_arr[x + 1][y + 4] = char(250);
				else if (x == 0 && y > 0 && n == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 4][y - 1] = player_arr[x + 4][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
				else if (x > 0 && y == 0 && k == 1) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 4] = player_arr[x - 1][y + 4] = player_arr[x + 1][y + 4] = char(250);
				else if (x > 0 && y == 0 && n == 1) player_arr[x - 1][y] = player_arr[x + 4][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
				else if (x == 0 && y == 0 && k == 1) player_arr[x + 1][y] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x][y + 4] = player_arr[x + 1][y + 4] = char(250);
				else if (x == 0 && y == 0 && n == 1) player_arr[x + 4][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = player_arr[x + 4][y + 1] = char(250);
				break;
			}
		}
	}
	while (ship3 > 0)
	{
		while (true)
		{
			random = rand() % 2;
			if (random == 1)
			{
				n = 1;
				k = 0;
			}
			else {
				n = 0;
				k = 1;
			}
			x = rand() % 10;
			y = rand() % 10;
			if ((k == 1 && player_arr[x][y] == ' ' && player_arr[x][y + 1] == ' ' && player_arr[x][y + 2] == ' ' && y < 8) || (n == 1 && player_arr[x][y] == ' ' && player_arr[x + 1][y] == ' ' && player_arr[x + 2][y] == ' ' && x < 8))
			{
				switch (ship3)
				{
				case 1:
					player_ship31x = x;
					player_ship31y = y;
					if (n == 1) player_ship31 = 'h';
					break;
				case 2:
					player_ship32x = x;
					player_ship32y = y;
					if (n == 1) player_ship32 = 'h';
					break;
				}
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				player_arr[x + n + n][y + k + k] = '0';
				ship3--;
				if (x > 0 && y > 0 && k == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 3] = char(250);
				else if (x > 0 && y > 0 && n == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x - 1][y] = player_arr[x + 3][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
				else if (x == 0 && y > 0 && k == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 3] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = char(250);
				else if (x == 0 && y > 0 && n == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 3][y - 1] = player_arr[x + 3][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
				else if (x > 0 && y == 0 && k == 1) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = player_arr[x - 1][y + 3] = player_arr[x][y + 3] = char(250);
				else if (x > 0 && y == 0 && n == 1) player_arr[x - 1][y] = player_arr[x + 3][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
				else if (x == 0 && y == 0 && k == 1) player_arr[x + 1][y] = player_arr[x][y + 3] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x + 1][y + 3] = char(250);
				else if (x == 0 && y == 0 && n == 1) player_arr[x + 3][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = player_arr[x + 3][y + 1] = char(250);
				break;
			}
		}
	}
	while (ship2 > 0)
	{
		while (true)
		{
			random = rand() % 2;
			if (random == 1)
			{
				n = 1;
				k = 0;
			}
			else {
				n = 0;
				k = 1;
			}
			x = rand() % 10;
			y = rand() % 10;
			if ((k == 1 && player_arr[x][y] == ' ' && player_arr[x][y + 1] == ' ' && y < 9) || (n == 1 && player_arr[x][y] == ' ' && player_arr[x + 1][y] == ' ' && x < 9))
			{
				switch (ship2)
				{
				case 1:
					player_ship21x = x;
					player_ship21y = y;
					if (n == 1) player_ship21 = 'h';
					break;
				case 2:
					player_ship22x = x;
					player_ship22y = y;
					if (n == 1) player_ship22 = 'h';
					break;
				case 3:
					player_ship23x = x;
					player_ship23y = y;
					if (n == 1) player_ship23 = 'h';
					break;
				}
				player_arr[x][y] = '0';
				player_arr[x + n][y + k] = '0';
				ship2--;
				if (x > 0 && y > 0 && k == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x + 1][y + 1] = player_arr[x - 1][y + 2] = player_arr[x][y + 2] = player_arr[x + 1][y + 2] = char(250);
				else if (x > 0 && y > 0 && n == 1) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
				else if (x == 0 && y > 0 && k == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
				else if (x == 0 && y > 0 && n == 1) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 2][y - 1] = player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
				else if (x > 0 && y == 0 && k == 1) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = player_arr[x - 1][y + 2] = char(250);
				else if (x > 0 && y == 0 && n == 1) player_arr[x - 1][y] = player_arr[x + 2][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
				else if (x == 0 && y == 0 && k == 1) player_arr[x + 1][y] = player_arr[x][y + 2] = player_arr[x + 1][y + 1] = player_arr[x + 1][y + 2] = char(250);
				else if (x == 0 && y == 0 && n == 1) player_arr[x + 2][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = player_arr[x + 2][y + 1] = char(250);
				break;
			}
		}
	}
	while (ship1 > 0)
	{
		while (true)
		{
			x = rand() % 10;
			y = rand() % 10;
			if (player_arr[x][y] == ' ') {
				switch (ship1)
				{
				case 1:
					player_ship11x = x;
					player_ship11y = y;
					break;
				case 2:
					player_ship12x = x;
					player_ship12y = y;
					break;
				case 3:
					player_ship13x = x;
					player_ship13y = y;
					break;
				case 4:
					player_ship14x = x;
					player_ship14y = y;
					break;
				}
				player_arr[x][y] = '0';
				ship1--;
				if (x > 0 && y > 0) player_arr[x - 1][y - 1] = player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
				else if (x == 0 && y > 0 && y < 9) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
				else if (x > 0 && x < 9 && y == 0) player_arr[x - 1][y] = player_arr[x + 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
				else if (x == 0 && y == 0) player_arr[x + 1][y] = player_arr[x][y + 1] = player_arr[x + 1][y + 1] = char(250);
				else if (x == 0 && y == 9) player_arr[x][y - 1] = player_arr[x + 1][y - 1] = player_arr[x + 1][y] = char(250);
				else if (x == 9 && y == 0) player_arr[x - 1][y] = player_arr[x - 1][y + 1] = player_arr[x][y + 1] = char(250);
				break;
			}
		}
	}
	locate_display();
	cout << endl;
	if (language == 'e') cout << "--> Press ENTER to proceed.\n--> Press B return to previous page.\n--> If you want to change press any other button.";
	else if (language == 'a') cout << "--> Tesdiq etmek ucun ENTER basin.\n--> Geri donmek ucun B basin.\n--> Eger duzulusu deyismek isteyirsinizse diger duymelere basin.";
	int number = _getch();
	if (number == 13)
	{
		point_deleter();
		system("cls");
		locate_display();
		ship1 = 4;
		ship2 = 3;
		ship3 = 2;
		ship4 = 1;
		attack_turn(1);
	}
	else if (number == 98 || number == 66)
	{
		loading_animation();
		fillplayer_arr();
		ship1 = 4;
		ship2 = 3;
		ship3 = 2;
		ship4 = 1;
		manual_auto_locate();
	}
	else
	{
		loading_animation();
		fillplayer_arr();
		ship1 = 4;
		ship2 = 3;
		ship3 = 2;
		ship4 = 1;
		locate_auto_ships();
	}
}

void locate_ships() {
	while (ship4 > 0)
	{
		locate_ship4();
	}
	while (ship3 > 0)
	{
		locate_ship3();
	}
	while (ship2 > 0)
	{
		locate_ship2();
	}
	while (ship1 > 0)
	{
		locate_ship1();
	}
	cout << endl;
	cin.get();
	if (language == 'e') cout << "Press any button to start game" << endl;
	else if (language == 'a') cout << "Oyuna baslamaqcun istenilen duymeni secin" << endl;
	point_deleter();
	ship1 = 4;
	ship2 = 3;
	ship3 = 2;
	ship4 = 1;
	attack_turn(1);
}

int color_d = 124;
int color_e = 7;
void manual_auto_locate() {
	system("cls");
	if (language == 'e')
	{
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("Manual Locate", color_d);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(186);
		print_color("Auto Locate", color_e);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
	}
	else if (language == 'a')
	{
		system("cls");
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(186);
		print_color("Manual Yerlesdir", color_d);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(186);
		print_color("Auto Yerlesdir", color_e);
		cout << char(186);
		cout << endl;
		cout << "\t\t\t\t\t\t\t\b";
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
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
	else if (number == 98 || number == 66) main_menu();
	if (k == "up" || k == "down")
	{
		int temp = color_d;
		color_d = color_e;
		color_e = temp;
		manual_auto_locate();
	}
	else if (k == "enter") {
		loading_animation();
		if (color_d == 124) locate_ships();
		else if (color_e == 124) locate_auto_ships();
	}
	else manual_auto_locate();
}

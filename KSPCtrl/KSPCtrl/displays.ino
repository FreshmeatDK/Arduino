void printTime()
{
	readTime();
	if (hour > 21)
	{
		if ((second % 2) == 0)
		{
			lc.setChar(0, 7, 'b', false);
		}
		else
		{
			lc.setChar(0, 7, ' ', false);
		}
	}
	if (hour > 9)
	{
		int ones = hour % 10;
		hour = hour / 10;
		lc.setDigit(0, 5, hour, false);
		lc.setDigit(0, 4, ones, true);
	}
	else
	{
		lc.setDigit(0, 5, 0, false);
		lc.setDigit(0, 4, hour, true);
	}
	if (minute > 9)
	{
		int ones = minute % 10;
		minute = minute / 10;
		lc.setDigit(0, 3, minute, false);
		lc.setDigit(0, 2, ones, true);
	}
	else
	{
		lc.setDigit(0, 3, 0, false);
		lc.setDigit(0, 2, minute, true);
	}
	if (second > 9)
	{
		int ones = second % 10;
		second = second / 10;
		lc.setDigit(0, 1, second, false);
		lc.setDigit(0, 0, ones, false);
	}
	else
	{
		lc.setDigit(0, 1, 0, false);
		lc.setDigit(0, 0, second, false);
	}
}

void LCD1Rocket()
{
	// Here we assemble the string to send to LCD display 1 and update it
	char lcd1out[81]; //char buffer to send to display 1
	char pstr[8]; //temp string for f2str

	charcpypos("AP: ", 0, lcd1out);
	f2str(VData.ap, 3, pstr);
	charcpypos(pstr, 4, lcd1out);

	lcd.setCursor(0, 0);
	lcd.print(lcd1out);
}

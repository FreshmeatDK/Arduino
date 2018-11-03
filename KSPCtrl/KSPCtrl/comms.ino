void serialcoms()
{
	byte buffer[256];

	byte rx_len;
	byte rx_index;
	byte structSize;

	float alt = 0;

	byte throttle;
	throttle = analogRead(0) / 4;


	structSize = sizeof(VData);
	rx_index = 0;
	if (Serial.available()) {

		rx_len = Serial.available();
		if (rx_len == structSize)
		{
			while (Serial.available()) {
				buffer[rx_index] = Serial.read();
				rx_index++;
			}
			memcpy(&VData, buffer, structSize);
			rx_index = 0;
			alt = VData.alt;
		}
		else
		{
			while (Serial.available())
			{
				Serial.read();
			}
			rx_index = 0;
			alt = -1;
		}

		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print(alt);
		lcd.setCursor(0, 1);
		lcd.print(VData.ap);
		lcd.setCursor(10, 0);
		lcd.print(throttle);


		Serial.write(throttle);
		delay(100);
	}
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Waiting");
	delay(10);


}

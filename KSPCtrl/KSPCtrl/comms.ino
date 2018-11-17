void serialcoms()
{
	byte buffer[256];

	byte rx_len;
	byte rx_index;
	byte structSize;

	structSize = sizeof(VData);
	rx_index = 0;
	if (Serial.available()) 
	{
		connected = true; // Sets flag and resets timeout timer
		timeout = millis();

		rx_len = Serial.available();
		if (rx_len == structSize)
		{
			while (Serial.available()) {
				buffer[rx_index] = Serial.read();
				rx_index++;
			}
			memcpy(&VData, buffer, structSize);
			rx_index = 0;
			lcd.print("Conn");

		}
		else if (rx_len > structSize)
		{
			while (Serial.available())
			{
				Serial.read();
			}
			rx_index = 0;
			lcd.print("NoConn");

		}

		lcd.setCursor(0, 0);
		Serial.write(85);
		Serial.write(85);
		Serial.write((byte*)&Cpacket, sizeof(Cpacket));
		
	}
	else
	{
		if ((millis()-timeout) > TIMEOUT)
		{
			connected = false;
		}
		lcd.clear();
		lcd.setCursor(0, 0);
		//lcd.print("Waiting");
		delay(10);
	}


}

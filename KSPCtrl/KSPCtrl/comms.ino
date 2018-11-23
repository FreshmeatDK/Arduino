void serialcoms()
{
	byte buffer[256];

	byte chk1, chk2;
	byte rx_len;
	byte rx_index;
	byte structSize;

	structSize = sizeof(VData);
	rx_index = 0;
	if (Serial.available() > 3) 
	{
		connected = true; // Sets flag and resets timeout timer
		timeout = millis();
		bufferlenght = Serial.available();
		chk1 = Serial.read();
		
		if (chk1 == 0x55)
		{
			
			
			rx_len = Serial.available();
			if (rx_len >= structSize)
			{
				while (Serial.available()) {
					buffer[rx_index] = Serial.read();
					rx_index++;
				}


				memcpy(&VData, buffer, structSize);
				rx_index = 0;
				

			}
			
		}
		

		
	}
	else
	{
		if ((millis()-timeout) > TIMEOUT)
		{
			connected = false;
		}
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Waiting");
		delay(10);
	}


	Serial.write(85);
	Serial.write((byte*)&Cpacket, sizeof(Cpacket));
}


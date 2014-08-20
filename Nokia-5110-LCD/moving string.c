    while(1)
	{
	  	for( int i = 83; i >= 0; i-- )
		{
			for(int n = 0; n < 504; n++)
			{
				LCD_write_byte( frame_1[ n ], 0);
			}
			
			_delay_ms(50);
			LCD_set_XY( i, 0);
		}
  }

void main()
{
	int   x, y, z = 1;

	switch (z + 1)
	{	
		case 0:
			if(z){
				x = 3;
			}
		case 1:
			while(1){
				z = 1;
				if(z) break;
			}
			y = 4;
		break;
		

		case 4:
			y = 3;
		break;
		
		default:
			y = 1;
	}
	
		x = y + z;
        return x;
}

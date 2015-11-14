void main()
{
	int   x, y, z = 1;
	
	if(x){
	  y = 3;
	}else{
	switch (z + 1)
	{	
		case 0:
			if(z){
				x = 3;
			}
		case 1:
			y = 4;
		break;
		

		case 4:
			y = 3;
		break;
		
		default:
			y = 1;
	}
	}
	
		x = y + z;
        return x;
}

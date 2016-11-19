int iGetch(void)    //定义getch()函数无需回车确认地获取用户输入，用于控制行走方向。
{
	struct termios strTm, strTmOld;
	int bFd = 0, bCh;
	
	if (tcgetattr(bFd, &strTm) < 0) 
	{
		return -1;
	}
	
	strTmOld = strTm;
	cfmakeraw(&strTm);
	if (tcsetattr(bFd, TCSANOW, &strTm) < 0)
	{
		return -1;
	}
	
	bCh = getchar();
	if (tcsetattr(bFd, TCSANOW, &strTmOld) < 0)
	{
		return -1;
	}
    
	return bCh;
} 


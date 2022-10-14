#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <sys/stat.h>

using namespace std;

class Bug{
	public:
		string FileName = "";
		size_t pos = 0;
		string Path = "";
		string Type = "";
		int Sizz = 0.0;
		Bug(){}
		string GetFileSize(string filename){
			FILE * fpS;
			fpS = fopen (filename.c_str(), "r");
			fseek(fpS, 0L, SEEK_END);
			int Ans = ftell(fpS);
			fclose(fpS);
			int i = 0;
			int o ;
			for(i = 0,o = Ans; o > 0; o / 10, i++);
			char str[i];
			for(int o = 0;Ans > 0;Ans / 10,o++){
				str[o] = (Ans%10)+48;
			}
			return str;
		}
		void Debug(int argc, char** argv){
			string base_filename = Path.substr(Path.find_last_of("/\\") + 1);
			string path_filename = Path.substr(0, Path.find_last_of("/\\"));
			srand( time(NULL) );
			string Str = "{\n";
			const char * c = Path.c_str();
			FILE * fp;
			fp = fopen (c, "w");
			Str += "\t\"Name\" :\t\"" + base_filename +"\",\n";
			Str += "\t\"Type\" :\t\"RIP File\",\n";
			//Str += "\t\"Size\" :\t\"" + GetFileSize(FileName) + "\",\n";
			Str += "\t\"Path\" :\t\"" + path_filename +"\"\n}";
			char Sout[Str.length() + 1];
			for(int i = 0; i < sizeof(Sout); i++)	Sout[i] = Str[i];
			Sout[Str.length()] = '\0';
			fprintf(fp,"%s",Sout);
			fseek(fp, 0L, SEEK_END);
			Sizz = ftell(fp);
			fclose(fp);
		}
		void Compiler(int argc, char** argv){
			if(argc > 2){
				cout << "Error!!!";
				system("pause");
				return;
			}
			FileName = *(argv+1);
			pos = FileName.find(".");
			Path = FileName.substr(0, pos) + ".rip";
			Type = FileName.substr(pos);
			Debug(argc, argv);
			remove(*(argv+1));
			cout << "Fired file...\n" <<
					"--------\n" <<
					"- Filename: " << Path << endl <<
					"- Stove Name: Furnace 4.9.2 64-bit Release\n" <<

					"Processing " << Type << " source file...\n" <<
					"--------\n" <<
					"- Sound player: block.furnace.fire_crackle Play\n" <<
					"- Command: furnace.exe \" " << Path << "\" -o \"" << Path << "\"  -I\"" << Path << "furnace.Items\" -I\"" << Path << "furnace.Items\" -I\"" << Path << "furnace.Items\" -I\"" << Path << "furnace.Items\" -L\"" << Path << "furnace.Items\" -L\"" << Path << "furnace.Items\" -static-Burn\n" <<

					"Fired results...\n" <<
					"--------\n" <<
					"- Errors: " << rand() << "\n" <<
					"- Warnings: " << rand() << "\n" <<
					"- Output Filename: " << Path << "\n" <<
					"- Output Size: " << Sizz << " B\n" <<
					"- Compilation Time: " << clock() << "ms \n" ;
			system("pause");
		}
};
int main(int argc, char** argv){
	Bug b ;
	b.Compiler(argc, argv);
}

#include <string>
using namespace std;
class Uzorak;

class Ucitavanje
{
public:
	Ucitavanje(char* dat);
	Ucitavanje(string dat);
	Uzorak ucitajUzorak();
	static void setPath(string newPath);
	static string getPath();

private:
	char imeDatoteke[50];
	static string path;

};


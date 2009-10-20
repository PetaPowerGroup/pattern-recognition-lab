

class Greska
{
public:
	enum streamEnum 
		{KONZOLA, DATOTEKA};
	Greska(char* poruka);
	void ispisGreske();
	void ispisGreske(streamEnum stream);

private:
	char porukaGreske[100];
};

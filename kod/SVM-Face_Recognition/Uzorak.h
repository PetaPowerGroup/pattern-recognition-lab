

class Uzorak
{
public:
	Uzorak(int sirina, int visina);
	unsigned char getPixel(int red, int stupac);
	unsigned char getPixel(int pozicija);
	void setPixel(int red, int stupac, unsigned char nijansa);
	void setPixel(int pozicija, unsigned char nijansa);
	int getVelicina();
	int getSirina();
	int getVisina();

private:
	unsigned char* pixeli;
	int sirina;
	int visina;
};

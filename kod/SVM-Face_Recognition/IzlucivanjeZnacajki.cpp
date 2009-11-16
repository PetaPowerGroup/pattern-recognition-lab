// koristit æemo Haarove znaèajke 

/*
Osnovni algoritam:
	- šetat se "oknom" -> prozorom po slici 
	- za svako okno na slici izraèunati razliku tamnog i svijetlog dijela
	- tu razliku spremiti u novi vektor znaèajki

Na ovaj naèin dobit æemo puno znaèajki, no uz kotrolu velièine okna i to se može smanjiti. 
Naravno rezultat æe ovisiti o izboru broja znaèajki, za ovo ne znam u kolikoj mjeri. Vidjet æemo testiranjem.

*/

int izluciZnacajke() {

int sirina_okna = 24;  
int visina_okna = 24;  // ako je slika velika 64x64 imamo  40^2 znaèajki (1600)
// ako je potrebno manje znaèajki onda ova metoda nije za nas. premda sam èuo za dosta sluèajeva kada se radilo i sa 
// neusporedivo više znaèajki

int tamni, svijetli, sirina_slike, visina_slike, pozicija, slika;   //ovo je samo kako bi kod bio error-free
int pixel[4096];                                                    //ovo je samo kako bi kod bio error-free
int znacajka[10][100];                                              //ovo je samo kako bi kod bio error-free

for (int i = 0; i < (visina_slike - visina_okna); i++)  
{
	for (int j = 0; j < (sirina_slike - sirina_okna); j++) 
	{
		tamni = 0;   // moramo resetirati zbog ponovne iteracije
		svijetli =0;  // moramo resetirati zbog ponovne iteracije
		// pomoæu gornje dvije petlje šeæemo okno kroz cijelu sliku
		// sada je potrebno izraèunati razliku intenziteta za tamni i svijetli dio
		for (int k = i; k < (i + visina_okna); k++) 
		{
			for (int l = j; l < (j + sirina_okna); l++)
			{
				if (l < (j + sirina_okna/2))
					tamni += pixel[k*sirina_okna+l];
				else
					svijetli += pixel[k*sirina_okna+1];   
			}
		}
		znacajka[slika][pozicija] = tamni - svijetli; // i dobili smo znaèajku
		pozicija++;  // pomièemo kako bi mogli spremiti iduæu znaèajku 
	}
}


return 0;
}
/*
Evo ovo je kako algoritam radi. Jasno mi je da nije u skladu s ostalim kodom, no važno je da saznam dali 
æe nam ova metoda biti dovoljno dobra. Ako da onda u jednom danu mogu napisati funkcionalan kod. 

Ovo je primjer samo za jednu sliku, za sve slike bi trebali ovako. 

Pretpostavljam da je ovakav algoritam malo spor, 4 petlje :S . Ali ako se odluèimo da je ovo dobra metoda
tada mogu napraviti neke promijene koje æe znatno ubrzati izluèivanje znaèajki. Ovo ubrzanje se odnosi na to
da æe dvije unutarnje petlje(k,l) nestati, te se tamnom i svijetlom dijelu pristupa izravno. Takav postupak je moguæ
pomoæu integrirane slike(znam kako napraviti integriranu sliku, nije teško). 

Molim za komentare dali je ovo dobra metoda, ili ako nije prijedlog za neku drugu.

Fisher za više razreda bi se isto mogao napraviti, ali taj postupak je puno kompliciraniji. I ima puno operacija 
sa matricama što opet znaèi dosta vremena. I fishera nisam baš skužio :(  
*/
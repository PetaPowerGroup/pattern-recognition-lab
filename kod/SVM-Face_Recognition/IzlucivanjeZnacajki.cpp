// koristit �emo Haarove zna�ajke 

/*
Osnovni algoritam:
	- �etat se "oknom" -> prozorom po slici 
	- za svako okno na slici izra�unati razliku tamnog i svijetlog dijela
	- tu razliku spremiti u novi vektor zna�ajki

Na ovaj na�in dobit �emo puno zna�ajki, no uz kotrolu veli�ine okna i to se mo�e smanjiti. 
Naravno rezultat �e ovisiti o izboru broja zna�ajki, za ovo ne znam u kolikoj mjeri. Vidjet �emo testiranjem.

*/

int izluciZnacajke() {

int sirina_okna = 24;  
int visina_okna = 24;  // ako je slika velika 64x64 imamo  40^2 zna�ajki (1600)
// ako je potrebno manje zna�ajki onda ova metoda nije za nas. premda sam �uo za dosta slu�ajeva kada se radilo i sa 
// neusporedivo vi�e zna�ajki

int tamni, svijetli, sirina_slike, visina_slike, pozicija, slika;   //ovo je samo kako bi kod bio error-free
int pixel[4096];                                                    //ovo je samo kako bi kod bio error-free
int znacajka[10][100];                                              //ovo je samo kako bi kod bio error-free

for (int i = 0; i < (visina_slike - visina_okna); i++)  
{
	for (int j = 0; j < (sirina_slike - sirina_okna); j++) 
	{
		tamni = 0;   // moramo resetirati zbog ponovne iteracije
		svijetli =0;  // moramo resetirati zbog ponovne iteracije
		// pomo�u gornje dvije petlje �e�emo okno kroz cijelu sliku
		// sada je potrebno izra�unati razliku intenziteta za tamni i svijetli dio
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
		znacajka[slika][pozicija] = tamni - svijetli; // i dobili smo zna�ajku
		pozicija++;  // pomi�emo kako bi mogli spremiti idu�u zna�ajku 
	}
}


return 0;
}
/*
Evo ovo je kako algoritam radi. Jasno mi je da nije u skladu s ostalim kodom, no va�no je da saznam dali 
�e nam ova metoda biti dovoljno dobra. Ako da onda u jednom danu mogu napisati funkcionalan kod. 

Ovo je primjer samo za jednu sliku, za sve slike bi trebali ovako. 

Pretpostavljam da je ovakav algoritam malo spor, 4 petlje :S . Ali ako se odlu�imo da je ovo dobra metoda
tada mogu napraviti neke promijene koje �e znatno ubrzati izlu�ivanje zna�ajki. Ovo ubrzanje se odnosi na to
da �e dvije unutarnje petlje(k,l) nestati, te se tamnom i svijetlom dijelu pristupa izravno. Takav postupak je mogu�
pomo�u integrirane slike(znam kako napraviti integriranu sliku, nije te�ko). 

Molim za komentare dali je ovo dobra metoda, ili ako nije prijedlog za neku drugu.

Fisher za vi�e razreda bi se isto mogao napraviti, ali taj postupak je puno kompliciraniji. I ima puno operacija 
sa matricama �to opet zna�i dosta vremena. I fishera nisam ba� sku�io :(  
*/
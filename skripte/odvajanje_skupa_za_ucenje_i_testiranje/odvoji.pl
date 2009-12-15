#!/usr/bin/perl

$brojac = 0;
$zaucenje = $ARGV[0];  #uzimamo argument iz komandne linije

open ULAZ, "<", "skup_svih_znacajki.txt" ;
open UCENJE, ">", "skup_za_ucenje.txt" ;
open TESTIRANJE, ">", "skup_za_testiranje.txt" ;

while (<ULAZ>) {
	chomp;
	if ($brojac == 8) {
		$brojac = 0;
	}
	$brojac += 1;
	if ($brojac <= $zaucenje) {     
		print UCENJE "$_ \n";
	}
	else {
		print TESTIRANJE "$_ \n";
	}
}

close ULAZ;
close UCENJE;
close TESTIRANJE;

# pozivanje skripte: perl odvoji.pl 6   ,6 uzoraka za uèenje, 2 za testiranje 
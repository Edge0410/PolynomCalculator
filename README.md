# Temalab1

Proiect 1 – POO – Sandu Eduard Alexandru – Grupa 134

1.	Clasa Polynom
Aceasta clasa are rolul de a aduna, scadea, inmulti si de a realiza diverse operatii si relatii matematice asupra polinoamelor.
Polinoamele au urmatoarea structura: 

## ax^n + bx^n-1 + cx^n-2 + ... + m ... etc.

unde fiecare termen consta intr-un coeficient inmultit cu necunoscuta ( X ) la o putere.
Pentru fiecare polinom am stocat gradul (Puterea maxima a necunoscutei) intr-o variabila de tip unsigned int si sirul coeficientilor polinomului intr-un vector din STL.
Totodata, avem stocata o variabila de tip Algebra, o clasa definita ulterior(detaliata mai tarziu):
 
Avem un constructor de initializare care are rolul de a redimensiona vectorul cu coeficienti in functie de gradul cu care a fost definit (acesta apeleaza si constructorul pentru variabila de clasa Algebra):
 
 
Bineinteles, avem si set-eri si get-eri pentru gradul polinomului, utili in cazul in care acesta se modifica in urma operatiilor de adunara/inmultire etc.:
 
Functionalitatile clasei sunt reprezentate prin posibilitatea de a aduna, scadea si inmulti polinoame, acest lucru realizandu-se cu ajutorul supraincarcarii de operatori. Astfel, daca adunam 2 obiecte sub forma normala – obiect3 = obiect2 + obiect1 sau le inmultim – obiect3 = obiect2 * obiect 1 etc., vom avea ca rezultat un nou polinom:
 


Pentru a citi un polinom, trebuie sa dam de la tastatura n+1 numere (unde n este gradul poinomului) reprezentand coeficientii termenilor, in ordinea descrescatoare a puterilor (Spre exemplu, pentru un obiect declarat astfel: Polynom obiect1(3); , vom avea de dat de la tastaura 4 termeni in momentul in care citim simplu: 

# cin>>obiect1;– ex. 1 5 6 9.

Pentru a afisa un polinom, simplu, folosim operatorul “<<”:

# cout<<obiect1;

Rezultatul va fi sub forma algebrica: 

# 1x^3 + 5x^2 + 6x^1 + 9

Totodata, putem verifica egalitatea dintre polinoame (operatorii == si !=):
 
2.	Clasa Algebra
Aceasta clasa a fost realizata cu scopul de a fi folosita in interiorul clasei precedente pentru operatii specifice precum Relatiile lui Viete, un concept matematic care are rolul de a calcula suma, produsul si alte relatii corespunzatoare radacinilor polinomului.
Clasa este ampla,  are 3 variabile corespunzatoare numarului de termeni (egal cu gradul, avem nevoie sa stim daca putem face produsul sau nu), suma si produsul radacinilor polinomului.
 
Aceasta clasa are set-eri si get-eri corespunzatori ce primesc (in cazul set-terilor) vectorul de coeficienti ca parametru si realizeaza calcule prin intermediul metodelor publice. 
Pentru a calcula suma si produsul radacinilor unui obiect din clasa Polynom, apelam metodele publice ale variabilei de tip Algebra prin metode publice ale clasei Polynom.
 
 

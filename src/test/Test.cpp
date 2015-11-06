#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "../logic/Campeonato.h"

void test_Atleta(){

	Atleta a("Alguem", "Portugal", 21, 60, 170);

	ASSERT_EQUAL(a.getInfo().nome, "Alguem");
	ASSERT_EQUAL(a.getPais(), "Portugal");
	ASSERT_EQUAL(a.getInfo().idade, 21);
	ASSERT_EQUAL(a.getPeso(), 60);
	ASSERT_EQUAL(a.getInfo().altura, 170);

	ASSERT_THROWS(a.setPontuacao(-1), ValorIncorrecto);
		try {
			a.setPontuacao(-1);
		}
		catch (ValorIncorrecto &e) {
			cout << "Apanhou excepçao. Pontuacao inválida: " << e.getValor() << endl;
			ASSERT_EQUAL(-1, e.getValor());
		}
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(test_Atleta));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AEDA PROJECTO 1 - Campeonatos Polidesportivos");
}

/*
int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
*/



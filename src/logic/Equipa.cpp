#include "Equipa.h"

Equipa::Equipa(string n, string p, string pat): nome(n), pais(p), patrocinador(pat) {
	pontuacao=0;
}

Equipa::Equipa() {
}

string Equipa::getNome() const {
	return nome;
}

string Equipa::getPais() const {
	return pais;
}

string Equipa::getPatrocinador() const {
	return patrocinador;
}

float Equipa::getPontuacao() const {
	return pontuacao;
}

void Equipa::setPontuacao(float p) {
	pontuacao=p;
}

vector<Atleta*> Equipa::getAtletas() const {
	return atletas;
}

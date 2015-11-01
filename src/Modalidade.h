#ifndef AEDA_PROJECTO_1_MODALIDADE_H
#define AEDA_PROJECTO_1_MODALIDADE_H

class Modalidade: public Desporto{

private:
    string nome;
    bool singular; // true: não pode ser executada simultâneo ("modalidades de um desporto poderão não poder ser executadas em simultâneo")

public:
    Modalidade(string n, bool s);
    virtual ~Modalidade();
    string getNome() const;
    //void calcPont();

};

#endif //AEDA_PROJECTO_1_MODALIDADE_H

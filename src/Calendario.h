#ifndef SRC_CALENDARIO_H_
#define SRC_CALENDARIO_H_

#include <string>
#include <vector>
#include "Prova.h"

using namespace std;

class Calendario{

    vector<Prova*> provas;

public:
    Calendario();
    vector<Prova*> getProvas() const;

};

#endif /* SRC_CALENDARIO_H_ */

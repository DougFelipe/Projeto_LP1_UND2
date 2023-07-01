#ifndef NO_H
#define NO_H

template <class O>
class No {
public:
    O valor;
    No<O>* proximo;

    No(O valor) : valor(valor), proximo(nullptr) {}
};

#endif  

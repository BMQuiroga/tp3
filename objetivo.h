#ifndef OBJETIVO_H
#define OBJETIVO_H

class Objetivo{

private:
    std::string nombre;
    std::string destripcion;
    int progreso;
    int objetivo;
public:
    //Objetivo(int numero_generador);
    //Objetivo();
    virtual bool checkear()=0;
    virtual void actualizar()=0;
};

class Comprar_Andypolis : public Objetivo {
    public:
        Comprar_Andypolis();
        bool checkear();
};

class Edad_De_Piedra : public Objetivo {
    public:
        Edad_De_Piedra();
        bool checkear();
};

class Bombardero : public Objetivo {
    public:
        Bombardero();
        bool checkear();
};

class Energetico : public Objetivo {
    public:
        Energetico();
        bool checkear();
};

class Letrado : public Objetivo {
    public:
        Letrado();
        bool checkear();
};

class Minero : public Objetivo {
    public:
        Minero();
        bool checkear();
};

class Cansado : public Objetivo {
    public:
        Cansado();
        bool checkear();
};

class Constructor : public Objetivo {
    public:
        Constructor();
        bool checkear();
};

class Armado : public Objetivo {
    public:
        Armado();
        bool checkear();
};

class Extremista : public Objetivo {
    public:
        Extremista();
        bool checkear();
};

class Principal : public Objetivo {
    public:
        Principal();
        bool checkear();
};










#endif
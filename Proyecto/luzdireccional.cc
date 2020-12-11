#include "aux.h"
#include "luz.h"
#include "luzdireccional.h"
#include "math.h"

LuzDireccional::LuzDireccional(const Tupla2f & orientacion){
    // Primero lo obtenemos en grados
    alpha = orientacion[0];
    beta = orientacion[1];

    // Lo pasamos a radianes, y calculamos el angulo z (ganma)
    alpha = sin(alpha*M_PI/180);
    beta = cos(beta*M_PI/180);
    float ganma = sin(alpha) * cos(beta);

    // Asignamos cada angulo a su posicion correspondiente;
    this->posicion[0] = alpha;
    this->posicion[1] = beta;
    this->posicion[2] = ganma;
    this->posicion[3] = 0.0;
    
}

LuzDireccional::LuzDireccional(Tupla2f direccion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){
    //Asignamos los valores por parametro a su correspondiente lugar 

    // Primero lo obtenemos en grados
    alpha = direccion[0];
    beta = direccion[1];

    // Lo pasamos a radianes, y calculamos el angulo z (ganma)
    alpha = sin(alpha*M_PI/180);
    beta = cos(beta*M_PI/180);
    float ganma = sin(alpha) * cos(beta);

    // Asignamos cada angulo a su posicion correspondiente;
    this->posicion[0] = alpha;
    this->posicion[1] = beta;
    this->posicion[2] = ganma;
    this->posicion[3] = 0.0;

    // IdLuz
    id = idLuzOpenGL;

    // Colores
    this->colorAmbiente = colorAmbiente;
    this->colorDifuso = colorDifuso;
    this->colorEspecular = colorEspecular;
}

void LuzDireccional::variarAnguloAlpha(float incremento){
    alpha += incremento;

    alpha = sin(alpha*M_PI/180);
    float ganma = sin(alpha) * cos(beta);

    this->posicion[0] = alpha;
    this->posicion[2] = ganma;
}

void LuzDireccional::variarAnguloBeta(float incremento){
    beta += incremento;

    beta = cos(beta*M_PI/180);
    float ganma = sin(alpha) * cos(beta);

    this->posicion[1] = beta;
    this->posicion[2] = ganma;
}
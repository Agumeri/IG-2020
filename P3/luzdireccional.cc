#include "aux.h"
#include "luz.h"
#include "luzdireccional.h"

LuzDireccional::LuzDireccional(const Tupla3f & orientacion){
    // Posicion luz 
    for(int i=0; i<3; i++) posicion(i) = orientacion(i);
    posicion(3) = 1.0;
}

LuzDireccional::LuzDireccional(Tupla3f direccion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){
    //Asignamos los valores por parametro a su correspondiente lugar 
    
    // Posicion luz 
    for(int i=0; i<3; i++) posicion(i) = direccion(i);
    posicion(3) = 1.0;

    // IdLuz
    id = idLuzOpenGL;

    // Colores
    this->colorAmbiente = colorAmbiente;
    this->colorDifuso = colorDifuso;
    this->colorEspecular = colorEspecular;
}

void LuzDireccional::variarAnguloAlpha(float incremento){
    alpha += incremento;
}

void LuzDireccional::variarAnguloBeta(float incremento){
    beta += incremento;
}
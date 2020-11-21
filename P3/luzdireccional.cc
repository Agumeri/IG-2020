#include "aux.h"
#include "luz.h"
#include "luzdireccional.h"

LuzDireccional::LuzDireccional(const Tupla2f & orientacion){

}

LuzDireccional::LuzDireccional(Tupla2f direccion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){

}

void LuzDireccional::variarAnguloAlpha(float incremento){
    alpha += incremento;
}

void LuzDireccional::variarAnguloBeta(float incremento){
    beta += incremento;
}
#include "aux.h"
#include "ala.h"

Ala::Ala(){}

void Ala::dibuja(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glScalef(3,3,3);
        glTranslatef(-8,0,0);
        glRotatef(90.0,0.0,1.0,0.0);
        aleron->draw(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    glPushMatrix();
        glScalef(1,1,1);
        conector->dibuja(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
}
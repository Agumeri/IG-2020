#include "aux.h"
#include "ala.h"

Ala::Ala(){}

void Ala::dibuja(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez){
    glMatrixMode(GL_MODELVIEW);

    // glPushMatrix()
    // si queremos rotar, ponemos glRotatef(45.0,0.0,1.0,0.0) POS_COMBATE
    glPushMatrix();
        glScalef(3,3,3);
        glTranslatef(-8,0,0);
        // glRotatef(90.0,0.0,0.0,1.0);
        glRotatef(90.0,0.0,1.0,0.0);
        aleron->draw(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    glPushMatrix();
        glScalef(1,1,1);
        conector->dibuja(modo_dibujado,puntos,lineas,solido,ajedrez); // cambiar a conector superior
    glPopMatrix();
    // glPopMatrix()
    
    /*
    glPushMatrix();
        glScalef(1,1,1);
        conector_inferior->dibuja(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    */
}

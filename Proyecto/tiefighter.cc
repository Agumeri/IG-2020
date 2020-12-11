#include "aux.h"
#include "tiefighter.h"

TieFighter::TieFighter(){
    Tupla4f goma_negra_ambiente(0.02,0.02,0.02,1.0),
              goma_negra_difuso(0.01,0.01,0.01,1.0),
              goma_negra_especular(0.4,0.4,0.4,1.0);

    Material goma_negra = Material(goma_negra_difuso,goma_negra_especular,goma_negra_ambiente,1.0*128.0);

    cabina->setMaterial(goma_negra);
}

void TieFighter::dibuja(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez){
    glPushMatrix();
        glScalef(5,5,5);
        cabina->VerTapas(true);
        cabina->draw(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    glPushMatrix();
        // glScalef(3,3,3);
        glTranslatef(-20,0,0);
        ala_izquierda->dibuja(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20,0,0);
        glRotatef(180,0.0,0.0,1.0);
        ala_derecha->dibuja(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
}    
#include "aux.h"
#include "conector.h"

Conector::Conector(){
    Tupla4f goma_negra_ambiente(0.02,0.02,0.02,1.0),
            goma_negra_difuso(0.01,0.01,0.01,1.0),
            goma_negra_especular(0.4,0.4,0.4,1.0);

    Material goma_negra = Material(goma_negra_difuso,goma_negra_especular,goma_negra_ambiente,1.0*128.0);       
    // asignamos los materiales deseados

    e1->setMaterial(goma_negra);
    e2->setMaterial(goma_negra);
    e3->setMaterial(goma_negra);
    c1->setMaterial(goma_negra);
    c2->setMaterial(goma_negra);
}

void Conector::dibuja(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glTranslatef(-20,0,0);
        e1->VerTapas(true);
        e1->draw(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-11,0,0);
        glRotatef(90.0,0.0,0.0,1.0);
        c1->VerTapas(true);
        c1->draw(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,0,0);
        e2->VerTapas(true);
        e2->draw(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(11,0,0);
        glRotatef(-90.0,0.0,0.0,1.0);
        c2->VerTapas(true);
        c2->draw(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20,0,0);
        e3->VerTapas(true);
        e3->draw(modo_dibujado,puntos,lineas,solido,ajedrez);
    glPopMatrix();

}
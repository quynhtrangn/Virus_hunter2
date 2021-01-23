//
// Created by nQuynhtrang on 11/14/2020.
//

#include "Collision.h"
Collision::Collision() {
    
}
bool Collision::isOnButton(FloatRect&){

}
bool Collision::isClickButton(RenderWindow &window, Animation object){  //neu click vao button
    float mousex= Mouse::getPosition(window).x;
    float mousey= Mouse::getPosition(window).y;

    float objectposwidth=object.getImagine().getPosition().x+object.getImagine().getLocalBounds().width*0.5f;
    float objectposhigh=object.getImagine().getPosition().y+object.getImagine().getLocalBounds().height*0.5f;

    float objectposx=object.getImagine().getPosition().x-object.getImagine().getLocalBounds().width*0.5f;
    float objectposy=object.getImagine().getPosition().y-object.getImagine().getLocalBounds().height*0.5f;


    if(mousex<objectposwidth&&mousex>objectposx&&mousey<objectposhigh&&mousey>objectposy&&Mouse::isButtonPressed(Mouse::Left)){
        return true;
    }
    return false;
}
bool Collision::isButton(int x1, int y1, float r1, int x2, int y2, float r2){// neu chuot di chuyen den button
    if(abs(x1-x2)<r1+r2&&abs(y1-y2)<(r1+r2)&&Mouse::isButtonPressed(Mouse::Left)) return 1;
    return 0;
}

bool Collision::isCollision(int x1, int y1, float r1,float h1, int x2, int y2, float r2, float h2) {
    if(abs(x1-x2)<r1+r2&&abs(y1-y2)<(h1+h2)) return 1;
    return 0;
}
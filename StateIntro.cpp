//
// Created by nQuynhtrang on 11/14/2020.
//

#include "StateIntro.h"
void StateIntro::setStateIntro(RenderWindow &window){
    data.loadFormFile();
}
void StateIntro::run(RenderWindow &window,int &titlemove,int &dd, int &menubtnmove, int &playbtnmove, int &ddchange){
    background.run(data.getBackground("InGame"),0.5f,Vector2f(360,475),Vector2f(1.35,0.98),window);
    logo.run(data.getBackground("logo"),0.5f,Vector2f(40,40),Vector2f(0.6,0.6),window);
    if(titlemove<=100&&dd==0){
        title.run(data.getBackground("title"),0.5f,Vector2f(360,204+titlemove*0.1f),Vector2f(1.2,1.2),window);
        titlemove++;
        if(titlemove==100){
            titlemove=0;
            dd=1;
        }
    }
    else if(titlemove<=100&&dd==1){
        title.run(data.getBackground("title"),0.5f,Vector2f(360,212-titlemove*0.1f),Vector2f(1.2,1.2),window);
        titlemove++;
        if(titlemove==100){
            titlemove=0;
            dd=0;
        }
    }

    if(menubtnmove<=16){
        menubtn.run(data.getBackground("SettingBtn"),0.5f,Vector2f(740-23.75f*menubtnmove,560),Vector2f(0.7,0.7),window);
        menubtnmove++;
    }
    else{
        menubtn.run(data.getBackground("SettingBtn"),0.5f,Vector2f(360,560),Vector2f(0.7,0.7),window);
    }
    if(playbtnmove<=16){
        playbtn.run(data.getBackground("PlayBtn"),0.5f,Vector2f(-10+playbtnmove*23.125f,750),Vector2f(0.75,0.75),window);
        playbtnmove++;
    }
    else{
        if(check.isCollision(playbtn.getImagine().getPosition().x,playbtn.getImagine().getPosition().y,playbtn.getImagine().getLocalBounds().width*0.25f,playbtn.getImagine().getLocalBounds().height*0.25f,Mouse::getPosition().x,Mouse::getPosition().y,0.001,0.001f)){
            playbtn.run(data.getBackground("PlayBtn"),0.5f,Vector2f(360,753),Vector2f(0.6,0.6),window);
        }
        else if(check.isClickButton(window,playbtn)){
            ddchange=1;
        }
        else{
            playbtn.run(data.getBackground("PlayBtn"),0.5f,Vector2f(360,750),Vector2f(0.75,0.75),window);
        }
    }
    //playbtn.run(data.getBackground("PlayBtn"),0.5f,Vector2f(360,750),Vector2f(0.75,0.75),window);
}
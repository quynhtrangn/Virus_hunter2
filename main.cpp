#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "StateLoad.h"
#include "Data.h"
#include "StateIntro.h"
#include "StatePlay.h"
using namespace sf;
using namespace std;
int main(){

    RenderWindow window(VideoMode(720,950),"Virus Hunter");
    window.setFramerateLimit(60);

    Data data;
    data.loadFormFile();

    StateLoad stateload;
    stateload.setStateLoad(window);
    int timeload=0;

    StateIntro stateintro;
    stateintro.setStateIntro(window);
    int titlemove=0;
    int ddtitle=0;
    int menubtnmove=0;
    int playbtnmove=0;
    int ddchange=0;
    int timego=0;
    Animation go;

    StatePlay stateplay;
    stateplay.setStatePlay();
    int enemyrate=1.5*60;
    int bulletrate=15;
    int mark=0;
    Animation gameover;
    int timegameover=0;
    int ddbullet=0;

    while(window.isOpen()){
        Event event;

        while (window.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                    window.close();
                    break;
                case Event::Resized:
                    std::cout<<"new width: "<<event.size.width<<"new height: "<<event.size.height<<std::endl;
                    break;
            }
        }
        window.clear();
        if(timeload<=100){
            stateload.run(window,timeload);
        }else if(ddchange==0){
            stateintro.run(window,titlemove, ddtitle,menubtnmove, playbtnmove, ddchange);
        }
        else if(ddchange==1){
            if(timego<=50){
                go.run(data.getBackground("go"),0.5f,Vector2f(360,475),Vector2f(1+0.05*timego,1+0.05*timego),window);
                timego++;
            }
            else{
                stateplay.run(window,enemyrate,bulletrate,mark, ddchange,ddbullet);
            }
        }
        else if(ddchange==2){
            if(timegameover<=60){
                gameover.run(data.getBackground("GameOver"),0.5f,Vector2f(360,475),Vector2f(0.5+0.02*timegameover,0.5+0.02*timegameover),window);
                timegameover++;
            }
            else{
                timegameover=0;
                mark=0;
                ddchange=0;
                timego=0;
                ddchange=0;
            }
        }

        window.display();
    }
    return 0;
}

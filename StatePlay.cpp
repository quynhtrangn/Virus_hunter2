//
// Created by nQuynhtrang on 11/14/2020.
//

#include "StatePlay.h"
bool StatePlay::isOutside(Sprite tmp){
    if(tmp.getPosition().y<-60||tmp.getPosition().y>980){
        return 1;
    }
    return 0;
}
bool StatePlay::isCollision(int x1, int y1, float r1,float h1, int x2, int y2, float r2, float h2) {
    if(abs(x1-x2)<r1+r2&&abs(y1-y2)<(h1+h2)) return 1;
    return 0;
}

void StatePlay::setStatePlay(){
    data.loadFormFile();
    font.loadFromFile("../Data/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(30);
    //text.setColor(Color::Yellow);
//    text.setString("Hello World!!");
    text.setPosition(Vector2f(100,30));
    text.setStyle(Text::Bold);
}
void StatePlay::run(RenderWindow &window, int &enemyrate,int &bulletrate, int &mark, int &ddchange,int &ddbullet){
    background.run(data.getBackground("Play"),0.5f,Vector2f(360,475),Vector2f(1,1),window);
    score.run(data.getBackground("score"),0.5f,Vector2f(100,40),Vector2f(1,1),Vector2f(0,0),window);

    enemyrate--;// venemy
    if(enemyrate==0){
        enemyrate=1.5*60;
        vtrix=rand()%(201)+30;
        for(int i=0;i<5;i++){
            //vtriy=rand()%(46)-50;  //-50 -5
            tmp.setTexture(data.getBackground("Virus"));
            tmp.setOrigin((Vector2f)tmp.getTexture()->getSize()*0.5f);
            tmp.setScale(Vector2f(0.4,0.4));
            tmp.setPosition(Vector2f(vtrix+(i*110),-20));
            enemy.push_back(tmp);
        }

    }
    //enemy
    for(int i=0;i<enemy.size();i++){
        enemy[i].move(0,5);
        enemy[i].setRotation(enemy[i].getRotation()-10);
    }
    for(int i=0;i<enemy.size();i++){
        drawTo(window,enemy[i]);
    }
    for(int i=0;i<enemy.size();i++) {
        if (isOutside(enemy[i]) == 1) {
            enemy.erase(enemy.begin() + i,enemy.begin() + i+1);
        }
    }

    // tao dan
    bulletrate--;
    Sprite tmp2;
    if(bulletrate==0){
        if(ddbullet==0){
            namebullet="B1";
            bulletrate=15;
        }
        else if(ddbullet==1){
            namebullet="B2";
            bulletrate=10;
        }
        else{
            namebullet="B3";
            bulletrate=5;
        }

        tmp2.setTexture(data.getBullet(namebullet));
        tmp2.setOrigin((Vector2f)tmp2.getTexture()->getSize()*0.5f);
        tmp2.setScale(Vector2f(0.6,0.6));
        tmp2.setOrigin(Vector2f(15.0f,15.0f));
        tmp2.setPosition(player.getImagine().getPosition());

        bullet.push_back(tmp2);
    }
    // dan bay
    for(int i=0;i<bullet.size();i++){
        bullet[i].move(0.0f,-10.0f);
        //move(0.0f,-10.0f);move(10*0.886f,-10*0.5f);

    }
    // pha huy dan
    for(int i=0;i<bullet.size();i++) {
        if (isOutside(bullet[i]) == 1) {
            bullet.erase(bullet.begin() + i,bullet.begin() + i+1);
        }
    }
    // window.draw(bullet);
    for(int i=0;i<bullet.size();i++){
        window.draw(bullet[i]);
    }
    for(int i=0;i<enemy.size();i++){
        for(int j=0;j<bullet.size();j++){
            if(isCollision(enemy[i].getPosition().x,enemy[i].getPosition().y,enemy[i].getLocalBounds().width*0.25f,enemy[i].getLocalBounds().height*0.25f,bullet[j].getPosition().x,bullet[j].getPosition().y,bullet[j].getLocalBounds().width*0.125f,bullet[j].getLocalBounds().height*0.125f)){
                enemy.erase(enemy.begin()+i,enemy.begin()+i+1);
                bullet.erase(bullet.begin()+j,bullet.begin()+j+1);
                mark+=10;
            }
        }
    }
    if(mark<100){
        ddbullet=0;
    }
    else if(mark<500)ddbullet=1;
    else ddbullet=2;

    text.setString(to_string(mark));
    window.draw(text);
    if(Mouse::getPosition(window).x<0) {
        //player.setPosition(Vector2f(10, 800));
        player.run(data.getPlayer("1"), 0.5f, Vector2f(10, 800), Vector2f(0.7, 0.7), window);
    }
    else if(Mouse::getPosition(window).x>720) {
        //player.setPosition(Vector2f(710, 800));
        player.run(data.getPlayer("1"), 0.5f, Vector2f(710, 800), Vector2f(0.7, 0.7), window);
    }
    else{
        player.run(data.getPlayer("1"),0.5f,Vector2f(Mouse::getPosition(window).x, 800),Vector2f(0.7,0.7),window);
    }
    for(int i=0;i<enemy.size();i++){
        if(isCollision(enemy[i].getPosition().x,enemy[i].getPosition().y,enemy[i].getLocalBounds().width*0.2f,enemy[i].getLocalBounds().height*0.2f,player.getImagine().getPosition().x,player.getImagine().getPosition().y,player.getImagine().getLocalBounds().width*0.2,player.getImagine().getLocalBounds().height*0.2)){
            ddchange=2;
            cout<<player.getImagine().getLocalBounds().height*0.2<<" "<<player.getImagine().getLocalBounds().width*0.2f<<endl;
            cout<<enemy[i].getLocalBounds().height*0.2<<" "<<enemy[i].getLocalBounds().width*0.2;
            cout<<player.getImagine().getPosition().x<<" ";
            enemy.clear();
            bullet.clear();
            break;
            mark++;
        }

    }

}

void StatePlay::drawTo(RenderWindow &window, Sprite textu ) {
    window.draw(textu);
}

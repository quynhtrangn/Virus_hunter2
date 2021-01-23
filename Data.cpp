//
// Created by nQuynhtrang on 11/14/2020.
//

#include "Data.h"
void Data::loadFormFile(){
    tmp.loadFromFile("../Data/Background/GameOver.png");
    background.emplace_back("GameOver",tmp);

    tmp.loadFromFile("../Data/Background/go.png");
    background.emplace_back("go",tmp);

    tmp.loadFromFile("../Data/Background/InGame.png");
    background.emplace_back("InGame",tmp);

    tmp.loadFromFile("../Data/Background/Intro.png");
    background.emplace_back("Intro",tmp);

    tmp.loadFromFile("../Data/Background/LoadBar.png");
    background.emplace_back("LoadBar",tmp);

    tmp.loadFromFile("../Data/Background/Loading.png");
    background.emplace_back("Loading",tmp);

    tmp.loadFromFile("../Data/Background/logo.png");
    background.emplace_back("logo",tmp);

    tmp.loadFromFile("../Data/Background/Play.png");
    background.emplace_back("Play",tmp);

    tmp.loadFromFile("../Data/Background/PlayBtn.png");
    background.emplace_back("PlayBtn",tmp);

    tmp.loadFromFile("../Data/Background/PlayBtn2.png");
    background.emplace_back("PlayBtn2",tmp);

    tmp.loadFromFile("../Data/Background/ResetBtn.png");
    background.emplace_back("ResetBtn",tmp);

    tmp.loadFromFile("../Data/Background/score.png");
    background.emplace_back("score",tmp);

    tmp.loadFromFile("../Data/Background/SettingBtn.png");
    background.emplace_back("SettingBtn",tmp);

    tmp.loadFromFile("../Data/Background/title.png");
    background.emplace_back("title",tmp);

    tmp.loadFromFile("../Data/Background/Virus.png");
    background.emplace_back("Virus",tmp);

    tmp.loadFromFile("../Data/Player/1.png");
    player.emplace_back("1",tmp);

    tmp.loadFromFile("../Data/Player/2.png");
    player.emplace_back("2",tmp);

    tmp.loadFromFile("../Data/Player/3.png");
    player.emplace_back("3",tmp);

    tmp.loadFromFile("../Data/Bullet/B1.png");
    bullet.emplace_back("B1",tmp);

    tmp.loadFromFile("../Data/Bullet/B2.png");
    bullet.emplace_back("B2",tmp);

    tmp.loadFromFile("../Data/Bullet/B3.png");
    bullet.emplace_back("B3",tmp);

//    vector<Texture> tmp1;
//    for(int i=0;i<6;i++){
//        tmp1[i].loadFromFile("../Data/Virus/VirusGreen/"+to_string(i+1)+".png");
//    }
//    enemy.emplace_back("VirusGreen",tmp1);
//    tmp1.clear();
//
//    for(int i=0;i<6;i++){
//        tmp1[i].loadFromFile("../Data/Virus/VirusPink/"+to_string(i+1)+".png");
//    }
//    enemy.emplace_back("VirusPink",tmp1);
//    tmp1.clear();
//
//    for(int i=0;i<6;i++){
//        tmp1[i].loadFromFile("../Data/Virus/VirusYellow/"+to_string(i+1)+".png");
//    }
//    enemy.emplace_back("VirusYellow",tmp1);
//    tmp1.clear();
}
Texture& Data::getBackground(string name){
    for(int i=0;i<background.size();i++){
        if(background[i].first==name)
            return background[i].second;
    }
}
Texture& Data::getPlayer(string name){
    for(int i=0;i<player.size();i++){
        if(player[i].first==name)
            return player[i].second;
    }
}
Texture& Data::getBullet(string name){
    for(int i=0;i<bullet.size();i++){
        if(bullet[i].first==name)
            return bullet[i].second;
    }
}
vector <Texture>& Data::getEnemy(string name){
    for(int i=0;i<enemy.size();i++){
        if(enemy[i].first==name)
            return enemy[i].second;
    }
}
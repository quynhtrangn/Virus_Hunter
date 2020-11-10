#include "SFML/Graphics.hpp"
#include<iostream>
#include <vector>
#include <math.h>
#include<string>
using namespace std;
using namespace sf;


int main(){

    RenderWindow window(VideoMode(800,800),"Destroy Corona Virus ");
    window.setFramerateLimit(10);
    vector<Texture> quai;
    Texture texture;
    Sprite s;
    for(int i=0;i<4;i++){
        texture.loadFromFile("../"+to_string(i+2)+".png");
        quai.push_back(texture);
    }
    int index=0;
    int dd=0;
    //s.setTexture(quai[0]);
    s.scale(0.15f,0.15f);
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

        //s.setPosition(Vector2f(100,100));
        if(dd==0) {
            s.setTexture(quai[index++]);
        }
        else  {
            s.setTexture(quai[index--]);
        }
        s.move(0,9);
        if(index==3) dd=1;
        if(index==0) dd=0;
        window.clear();
        window.draw(s);

        window.display();
    }
    return 0;
}
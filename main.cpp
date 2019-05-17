#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int checkWin(char a[][16],char player, char _player,int i,int j);

int main()
{
    sf::RenderWindow window(sf::VideoMode(602, 452), "SFML works!",Style::Close);

    //ve ban co
    Texture texture_banco;
    texture_banco.loadFromFile("banco.png");
    Sprite banCo;
    banCo.setTexture(texture_banco);

    //ve quan co 0
    Texture texture_quan0;
    texture_quan0.loadFromFile("quanO.png");
    Sprite quanO;
    quanO.setTexture(texture_quan0);

    // ve quan co X
    Texture texture_quanX;
    texture_quanX.loadFromFile("quanX.png");
    Sprite quanX;
    quanX.setTexture(texture_quanX);

    Texture _playerOwin;
    _playerOwin.loadFromFile("playerOwin.png");
    Sprite PlayerOwin;
    PlayerOwin.setTexture(_playerOwin);
    PlayerOwin.setPosition(50,150);

     Texture _playerXwin;
    _playerXwin.loadFromFile("playerXwin.png");
    Sprite PlayerXwin;
    PlayerXwin.setTexture(_playerXwin);
    PlayerXwin.setPosition(50,150);

    int chieuRong=16 ,chieuDai=16;
	//vector< vector<char> > array(chieuDai,vector<char>(chieuRong));
    char array[16][16];

	for(int i=0;i<chieuDai;i++){
		for(int j=0;j<chieuRong;j++){
			array[i][j]='0';
		}
	}

	int demO=0,count=1,demX=0;
	char play1='1';
	char play2='2';

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(banCo);
        if(Mouse::isButtonPressed(Mouse::Left)) {
            int x=Mouse::getPosition(window).x/30;
            int y=Mouse::getPosition(window).y/30;
            if(count%2==1 && x<=16 && x>=0 && y>=0 && y<=16 && array[x+1][y+1]=='0')
            {
                array[x+1][y+1]='1';
                count++;
                if(checkWin(array,play1,play2,x+1,y+1)==1)
                    demX++;
            }
            else if(count%2==0 && x<=16 && x>=0 && y>=0 && y<=16 && array[x+1][y+1]=='0') {
                array[x+1][y+1]='2';
                count++;
                if(checkWin(array,play2,play1,x+1,y+1)==1)
                    demO++;
            }
        }
        for(int i=0;i<chieuDai;i++){
            for(int j=0;j<chieuRong;j++){
                if(array[i][j]=='1'){
                        // do bi lech bang nen +2px
                    quanX.setPosition((i-1)*30+2,(j-1)*30+2);
                    window.draw(quanX);
                }
                if(array[i][j]=='2'){
                    // do bi lech bang nen +2px
                    quanO.setPosition((i-1)*30+2,(j-1)*30+2);
                    window.draw(quanO);
                }
            }
        }
        if(demO!=0){
            window.draw(PlayerOwin);
        } else if(demX!=0){
            window.draw(PlayerXwin);
        }
        window.display();
        //if(dem==0){
        //    cout<<"hoa"<<endl;
        //}
    }

    return 0;
}
int checkWin(char a[][16],char player, char _player,int i,int j){
    //DOC
    if(a[i][j+1] == player && a[i][j+2] == player && a[i][j+3] == player && a[i][j+4] != _player && a[i][j-1] != _player) return 1;
    if(a[i][j-1] == player && a[i][j+1] == player && a[i][j+2] == player && a[i][j+3] != _player && a[i][j-2] != _player) return 1;
    if(a[i][j-2] == player && a[i][j-1] == player && a[i][j+1] == player && a[i][j+2] != _player && a[i][j-3] != _player) return 1;
    if(a[i][j-3] == player && a[i][j-2] == player && a[i][j-1] == player && a[i][j+1] != _player && a[i][j-4] != _player) return 1;

    //NGANG
    if(a[i+1][j] == player && a[i+2][j] == player && a[i+3][j] == player && a[i+4][j] != _player && a[i-1][j] != _player) return 1;
    if(a[i-1][j] == player && a[i+1][j] == player && a[i+2][j] == player && a[i+3][j] != _player && a[i-2][j] != _player) return 1;
    if(a[i-2][j] == player && a[i-1][j] == player && a[i+1][j] == player && a[i+2][j] != _player && a[i-3][j] != _player) return 1;
    if(a[i-3][j] == player && a[i-2][j] == player && a[i-1][j] == player && a[i+1][j] != _player && a[i-4][j] != _player) return 1;

    //cheo
    if(a[i+1][j+1] == player && a[i+2][j+2] == player && a[i+3][j+3] == player && a[i+4][j+4] != _player && a[i-1][j-1] != _player) return 1;
    if(a[i-1][j-1] == player && a[i+1][j+1] == player && a[i+2][j+2] == player && a[i-2][j-2] != _player && a[i+3][j+3] != _player) return 1;
    if(a[i-2][j-2] == player && a[i-1][j-1] == player && a[i+1][j+1] == player && a[i-3][j-3] != _player && a[i+2][j+2] != _player) return 1;
    if(a[i-3][j-3] == player && a[i-2][j-2] == player && a[i-1][j-1] == player && a[i+1][j+1] != _player && a[i-4][j-4] != _player) return 1;

    //cheo
    if(a[i-1][j+1] == player && a[i-2][j+2] == player && a[i-3][j+3] == player && a[i+1][j-1] != _player && a[i-4][j+4] != _player) return 1;
    if(a[i+1][j-1] == player && a[i-1][j+1] == player && a[i-2][j+2] == player && a[i-3][j+3] != _player && a[i+2][j-2] != _player) return 1;
    if(a[i+2][j-2] == player && a[i+1][j-1] == player && a[i-1][j+1] == player && a[i-2][j+2] != _player && a[i+3][j-3] != _player) return 1;
    if(a[i+3][j-3] == player && a[i+2][j-2] == player && a[i+1][j-1] == player && a[i+4][j-4] != _player && a[i-1][j+1] != _player) return 1;
    else return -1;
}




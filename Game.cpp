#include <QTimer>
#include <Enemy.h>
#include <Game.h>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget * parent)
{

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();


    // set music background
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/AppData/bgsound.wav"));
    music->play();


    // set background Images
    setBackgroundBrush(QBrush(QImage(":/images/AppData/bg.jpg")));


    // add a view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
        // set scene and view width, height
    scene->setSceneRect(0,0,800,600);
    setFixedSize(800,600);


    // create a Player
        // create player and specify rect
    player = new Player();
        // set rect to focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
        // set player position
    player->setPos(width()/2 - player->pixmap().width(), height()-player->pixmap().height());
        // add player to the scene
    scene->addItem(player);


    //create enemy
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);


    // Adding score to game
    score = new Score();
    scene->addItem(score);

    // Adding health to game
    health = new Health();
    health->setPos(x(),y()+25);
    scene->addItem(health);
}

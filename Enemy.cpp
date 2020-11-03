#include <Enemy.h>
#include <QTimer>
#include <QGraphicsScene>
#include <Game.h>

#include "stdlib.h" // rand really large number

extern Game * game; // there is an external object called game

Enemy::Enemy()
{
    // set Random position
    int random_number = rand() % 700;

    //create a rect
    setPos(random_number, 0);
    setPixmap(QPixmap(":/images/AppData/Dragon.png"));


    //connect
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(pos().x(),pos().y()+5);

    if (pos().y() > 600) {
        // decrease health point
        game->health->decrease();
        // remove enemy from scene
        scene()->removeItem(this);
        delete this;
    }
}

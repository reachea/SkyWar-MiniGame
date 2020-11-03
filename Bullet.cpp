#include <Bullet.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <Enemy.h>
#include <Game.h>

extern Game * game; // there is an external object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw the rect
    setPixmap(QPixmap(":/images/AppData/laserBullet.png"));

    //create timer
    QTimer * timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    setPos(x(), y()-10);
    QList <QGraphicsItem *> colliding_items = collidingItems();

    // Delete when the bullet hits enemy
    for (int i=0, n=colliding_items.size(); i<n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            //increase the score
            game->score->increase();

            //remove both from scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //remove both objects;
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //Delete the bullet;
    if (pos().y() + 100 < 0) {
        scene()->removeItem(this);
        delete this;
    }
}

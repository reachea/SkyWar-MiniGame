#include <Player.h>
#include <QKeyEvent>
#include <Bullet.h>
#include <QGraphicsScene>
#include <Enemy.h>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/AppData/shooting.wav"));

    setPixmap(QPixmap(":/images/AppData/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            setPos(x()-10, y());
        }
    } else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800) {
            setPos(x()+10, y());
        }

    } else if (event->key() == Qt::Key_Space) {
        // play bullet sound
        if (bulletsound->state() == QMediaPlayer::PlayingState) {
            bulletsound->setPosition(0);
        } else if (bulletsound->state() == QMediaPlayer::StoppedState) {
            bulletsound->play();
        }


        // create new bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+32, y());
        scene()->addItem(bullet);
    }
}

void Player::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

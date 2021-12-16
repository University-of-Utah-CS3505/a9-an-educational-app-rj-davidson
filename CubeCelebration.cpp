/*
 * Lacking Ideas - Rubiks Educational App
 * CS 3505 - A9 - An Education App
 * @authors: Robert Davidson
 *           Orion Santiago
 *           Ronnie Koe
 *           Maiko Tuitupou
 *           Elizabeth Thomas
 *           Alex Gill
 * CubeCelebration.cpp
*/

#include "CubeCelebration.h"
#include "ui_CubeCelebration.h"

CubeCelebration::CubeCelebration(QWidget *parent) : QDialog(parent),
                                                    pmGreen(":/img/green.png"),
                                                    pmRed(":/img/red.png"),
                                                    pmYellow(":/img/yellow.png"),
                                                    pmWhite(":/img/white.png"),
                                                    pmOrange(":/img/orange.png"),
                                                    pmBlue(":/img/blue.png"),
                                                    world(b2Vec2(0.0f, 10.0f)),
                                                    worldTimer(this),
                                                    ui(new Ui::CubeCelebration)
{
    ui->setupUi(this);

    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    pmGreen = pmGreen.scaled(30, 30, Qt::KeepAspectRatio);
    pmRed = pmRed.scaled(30, 30, Qt::KeepAspectRatio);
    pmYellow = pmYellow.scaled(30, 30, Qt::KeepAspectRatio);
    pmWhite = pmWhite.scaled(30, 30, Qt::KeepAspectRatio);
    pmOrange = pmOrange.scaled(30, 30, Qt::KeepAspectRatio);
    pmBlue = pmBlue.scaled(30, 30, Qt::KeepAspectRatio);

    // Ground body
    b2BodyDef groundBody;
    groundBody.position.Set(100, 300);
    ground = world.CreateBody(&groundBody);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(200, 10.0f);
    ground->CreateFixture(&groundBox, 0.0f);

    // Properties for each cube
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(15, 15);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    // Blue body
    b2BodyDef blueBody;
    blueBody.type = b2_dynamicBody;
    blueBody.position.Set(rand() % 150, rand() % 150);
    blueCube = world.CreateBody(&blueBody);
    blueCube->CreateFixture(&fixtureDef);
    blueCube->ApplyLinearImpulse(b2Vec2(10000, -50000), blueCube->GetPosition(), true);
    blueCube->SetAngularVelocity(500);

    // Green body
    b2BodyDef greenBody;
    greenBody.type = b2_dynamicBody;
    greenBody.position.Set(rand() % 150, rand() % 150);
    greenCube = world.CreateBody(&greenBody);
    greenCube->CreateFixture(&fixtureDef);
    greenCube->ApplyLinearImpulse(b2Vec2(10000, -50000), greenCube->GetPosition(), true);
    greenCube->SetAngularVelocity(500);

    // Red body
    b2BodyDef redBody;
    redBody.type = b2_dynamicBody;
    redBody.position.Set(rand() % 150, rand() % 150);
    redCube = world.CreateBody(&redBody);
    redCube->CreateFixture(&fixtureDef);
    redCube->ApplyLinearImpulse(b2Vec2(10000, -50000), redCube->GetPosition(), true);
    redCube->SetAngularVelocity(500);

    // Yellow body
    b2BodyDef yellowBody;
    yellowBody.type = b2_dynamicBody;
    yellowBody.position.Set(rand() % 150, rand() % 150);
    yellowCube = world.CreateBody(&yellowBody);
    yellowCube->CreateFixture(&fixtureDef);
    yellowCube->ApplyLinearImpulse(b2Vec2(10000, -50000), yellowCube->GetPosition(), true);
    yellowCube->SetAngularVelocity(500);

    // White body
    b2BodyDef whiteBody;
    whiteBody.type = b2_dynamicBody;
    whiteBody.position.Set(rand() % 150, rand() % 150);
    whiteCube = world.CreateBody(&whiteBody);
    whiteCube->CreateFixture(&fixtureDef);
    whiteCube->ApplyLinearImpulse(b2Vec2(10000, -50000), whiteCube->GetPosition(), true);
    whiteCube->SetAngularVelocity(500);

    // Orange body
    b2BodyDef orangeBody;
    orangeBody.type = b2_dynamicBody;
    orangeBody.position.Set(rand() % 150, rand() % 150);
    orangeCube = world.CreateBody(&orangeBody);
    orangeCube->CreateFixture(&fixtureDef);
    orangeCube->ApplyLinearImpulse(b2Vec2(10000, -50000), orangeCube->GetPosition(), true);
    orangeCube->SetAngularVelocity(500);

    // Updates each of the cube faces
    worldTimer.setInterval(1000.0 / 30.0);
    connect(&worldTimer, &QTimer::timeout, this, [=]()
            {
        world.Step(1.0f / 10.0f, 8, 3);
        update(); });
    worldTimer.start();
}

CubeCelebration::~CubeCelebration()
{
    delete ui;
}

void CubeCelebration::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QTransform transform;

    // Draws blue cube
    painter.drawRect(ground->GetTransform().p.x - 200, ground->GetTransform().p.y - 10, 400, 5.0f);
    transform.rotate(blueCube->GetAngle());
    QPixmap blueRotation = pmBlue.transformed(transform);
    painter.drawPixmap(blueCube->GetPosition().x - 25, blueCube->GetPosition().y - 25, blueRotation);

    //  Draws green cube
    painter.drawRect(ground->GetTransform().p.x - 100, ground->GetTransform().p.y - 10, 400, 5.0f);
    transform.rotate(greenCube->GetAngle());
    QPixmap greenRotation = pmGreen.transformed(transform);
    painter.drawPixmap(greenCube->GetPosition().x - 25, greenCube->GetPosition().y - 25, greenRotation);

    // Draws red cube
    painter.drawRect(ground->GetTransform().p.x - 100, ground->GetTransform().p.y - 10, 400, 5.0f);
    transform.rotate(redCube->GetAngle());
    QPixmap redRotation = pmRed.transformed(transform);
    painter.drawPixmap(redCube->GetPosition().x - 25, redCube->GetPosition().y - 25, redRotation);

    // Draws yellow cube
    painter.drawRect(ground->GetTransform().p.x - 100, ground->GetTransform().p.y - 10, 400, 5.0f);
    transform.rotate(yellowCube->GetAngle());
    QPixmap yellowRotation = pmYellow.transformed(transform);
    painter.drawPixmap(yellowCube->GetPosition().x - 25, yellowCube->GetPosition().y - 25, yellowRotation);

    // Draws white cube
    painter.drawRect(ground->GetTransform().p.x - 100, ground->GetTransform().p.y - 10, 400, 5.0f);
    transform.rotate(whiteCube->GetAngle());
    QPixmap whiteRotation = pmWhite.transformed(transform);
    painter.drawPixmap(whiteCube->GetPosition().x - 25, whiteCube->GetPosition().y - 25, whiteRotation);

    // Draws orange cube
    painter.drawRect(ground->GetTransform().p.x - 100, ground->GetTransform().p.y - 10, 400, 5.0f);
    transform.rotate(orangeCube->GetAngle());
    QPixmap orangeRotation = pmOrange.transformed(transform);
    painter.drawPixmap(orangeCube->GetPosition().x - 25, orangeCube->GetPosition().y - 25, orangeRotation);
}

void CubeCelebration::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        // Blue cube
        blueCube->SetLinearVelocity(b2Vec2(0, 0));
        blueCube->ApplyLinearImpulse(b2Vec2(10000, -50000), blueCube->GetPosition(), true);
        blueCube->SetAngularVelocity(500);

        // Green cube
        greenCube->SetLinearVelocity(b2Vec2(0, 0));
        greenCube->ApplyLinearImpulse(b2Vec2(10000, -50000), greenCube->GetPosition(), true);
        greenCube->SetAngularVelocity(500);

        // Red cube
        redCube->SetLinearVelocity(b2Vec2(0, 0));
        redCube->ApplyLinearImpulse(b2Vec2(10000, -50000), redCube->GetPosition(), true);
        redCube->SetAngularVelocity(500);

        // Yellow cube
        yellowCube->SetLinearVelocity(b2Vec2(0, 0));
        yellowCube->ApplyLinearImpulse(b2Vec2(10000, -50000), yellowCube->GetPosition(), true);
        yellowCube->SetAngularVelocity(500);

        // White cube
        whiteCube->SetLinearVelocity(b2Vec2(0, 0));
        whiteCube->ApplyLinearImpulse(b2Vec2(10000, -50000), whiteCube->GetPosition(), true);
        whiteCube->SetAngularVelocity(500);

        // Orange cube
        orangeCube->SetLinearVelocity(b2Vec2(0, 0));
        orangeCube->ApplyLinearImpulse(b2Vec2(10000, -50000), orangeCube->GetPosition(), true);
        orangeCube->SetAngularVelocity(500);
    }
}

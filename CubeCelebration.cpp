#include "CubeCelebration.h"
#include "ui_CubeCelebration.h"

CubeCelebration::CubeCelebration(QWidget *parent, bool *solved) :
    QDialog(parent),
    pmGreen(":/img/green.png"),
    pmRed(":/img/red.png"),
    pmYellow(":/img/yellow.png"),
    pmWhite(":/img/white.png"),
    pmOrange(":/img/orange.png"),
    pmBlue(":/img/blue.png"),
    pmW(":/img/takethew.png"),
    pmL(":/img/holdthel.png"),
    pmCoal(":/img/coal.png"),
    world(b2Vec2(0.0f, 10.0f)),
    worldTimer(this),
    ui(new Ui::CubeCelebration)
{
    ui->setupUi(this);
    completed = solved;

    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    pmGreen = pmGreen.scaled(50, 50, Qt::KeepAspectRatio);
    pmRed = pmRed.scaled(50, 50, Qt::KeepAspectRatio);
    pmYellow = pmYellow.scaled(50, 50, Qt::KeepAspectRatio);
    pmWhite = pmWhite.scaled(50, 50, Qt::KeepAspectRatio);
    pmOrange = pmOrange.scaled(50, 50, Qt::KeepAspectRatio);
    pmBlue = pmBlue.scaled(50, 50, Qt::KeepAspectRatio);
    pmW = pmW.scaled(150, 150, Qt::KeepAspectRatio);
    pmL = pmL.scaled(150, 150, Qt::KeepAspectRatio);
    pmCoal = pmCoal.scaled(50, 50, Qt::KeepAspectRatio);

    // ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(200, 300);
    ground = world.CreateBody(&groundBodyDef);

    // shape of the ground
    b2PolygonShape groundBox;
    groundBox.SetAsBox(200, 10.0f);
    ground->CreateFixture(&groundBox, 0.0f);

    if (true)
    {
        cubes.push_back(greenCube);
        cubes.push_back(redCube);
        cubes.push_back(yellowCube);
        cubes.push_back(whiteCube);
        cubes.push_back(orangeCube);
        cubes.push_back(blueCube);
        cubes.push_back(wCube);
    }
    else
    {
        cubes.push_back(lCube);
        cubes.push_back(coalCube);
    }

    for (b2Body *c : cubes) {

        // rubiks cube body
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(rand()%150, rand()%150);
        c = world.CreateBody(&bodyDef);

        // square rubiks cube
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(25, 25);

        // properties of cube
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        c->CreateFixture(&fixtureDef);

        c->ApplyLinearImpulse(b2Vec2(10000, -50000), c->GetPosition(), true);
        c->SetAngularVelocity(500);
    }

    worldTimer.setInterval(1000.0 / 30.0);
    connect(&worldTimer, &QTimer::timeout, this, [=]() {
      world.Step(1.0f / 10.0f, 8, 3);
      update();
    });
    worldTimer.start();
}

CubeCelebration::~CubeCelebration()
{
    delete ui;
}

void CubeCelebration::paintEvent(QPaintEvent *event) {
    for (b2Body *c : cubes)
    {
        QPainter painter(this);
        painter.drawRect(ground->GetTransform().p.x - 200,
                         ground->GetTransform().p.y - 10, 400, 5.0f);
        QTransform transform;
        transform.rotate(c->GetAngle());
        QPixmap rotated = pmBlue.transformed(transform);
        painter.drawPixmap(c->GetPosition().x - 25, c->GetPosition().y - 25,
                           rotated);
    }
}

void CubeCelebration::keyPressEvent(QKeyEvent *event) {
  for (b2Body *c : cubes)
  {
      if (event->key() == Qt::Key_Space) {
          c->SetTransform(b2Vec2(150, 200), 0);
          c->SetLinearVelocity(b2Vec2(0, 0));

          c->ApplyLinearImpulse(b2Vec2(10000, -50000), c->GetPosition(), true);
          c->SetAngularVelocity(500);
      }
  }
}

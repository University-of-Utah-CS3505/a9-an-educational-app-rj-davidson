#include "CubeCelebration.h"
#include "ui_CubeCelebration.h"

CubeCelebration::CubeCelebration(QWidget *parent) :
    QDialog(parent),
    pm(":/rubiks_face.png"),
    world(b2Vec2(0.0f, 10.0f)),
    worldTimer(this),
    ui(new Ui::CubeCelebration)
{
    ui->setupUi(this);


    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    pm = pm.scaled(50, 50, Qt::KeepAspectRatio);

    // ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(200, 300);
    ground = world.CreateBody(&groundBodyDef);

    // shape of the ground
    b2PolygonShape groundBox;
    groundBox.SetAsBox(200, 10.0f);
    ground->CreateFixture(&groundBox, 0.0f);

    // rubiks cube body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(150, 200);
    cube = world.CreateBody(&bodyDef);

    // square rubiks cube
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(25, 25);

    // properties of cube
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    cube->CreateFixture(&fixtureDef);

    cube->ApplyLinearImpulse(b2Vec2(10000, -50000), cube->GetPosition(), true);
    cube->SetAngularVelocity(500);

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
  QPainter painter(this);
  painter.drawRect(ground->GetTransform().p.x - 200,
                   ground->GetTransform().p.y - 10, 400, 5.0f);
  QTransform transform;
  transform.rotate(cube->GetAngle());
  QPixmap rotated = pm.transformed(transform);
  painter.drawPixmap(cube->GetPosition().x - 25, cube->GetPosition().y - 25,
                     rotated);
}

void CubeCelebration::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Space) {
    cube->SetTransform(b2Vec2(150, 200), 0);
    cube->SetLinearVelocity(b2Vec2(0, 0));

    cube->ApplyLinearImpulse(b2Vec2(10000, -50000), cube->GetPosition(), true);
    cube->SetAngularVelocity(500);
  }
}

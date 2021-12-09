#include "RubiksCelebration.h"

RubiksCelebration::RubiksCelebration(QObject *parent) : QObject(parent)
{


}

//LabRubiksWidget::LabRubiksWidget(QWidget *parent)
//    : QWidget(parent),
//      pm(":/rubiks_face.png"),
//      world(b2Vec2(0.0f, 10.0f)),
//      worldTimer(this) {
//  setFocusPolicy(Qt::FocusPolicy::StrongFocus);
//  pm = pm.scaled(50, 50, Qt::KeepAspectRatio);
//  b2BodyDef groundBodyDef;
//  groundBodyDef.position.Set(200, 300);
//  ground = world.CreateBody(&groundBodyDef);
//  b2PolygonShape groundBox;
//  groundBox.SetAsBox(200, 10.0f);
//  ground->CreateFixture(&groundBox, 0.0f);

//  b2BodyDef bodyDef;
//  bodyDef.type = b2_dynamicBody;
//  bodyDef.position.Set(150, 200);
//  cube = world.CreateBody(&bodyDef);
//  b2PolygonShape dynamicBox;
//  dynamicBox.SetAsBox(25, 25);
//  b2FixtureDef fixtureDef;
//  fixtureDef.shape = &dynamicBox;
//  fixtureDef.density = 1.0f;
//  fixtureDef.friction = 0.3f;
//  cube->CreateFixture(&fixtureDef);

//  cube->ApplyLinearImpulse(b2Vec2(10000, -50000), cube->GetPosition(), true);
//  cube->SetAngularVelocity(500);

//  worldTimer.setInterval(1000.0 / 30.0);
//  connect(&worldTimer, &QTimer::timeout, this, [=]() {
//    world.Step(1.0f / 10.0f, 8, 3);
//    update();
//  });
//  worldTimer.start();
//}

//void LabRubiksWidget::paintEvent(QPaintEvent *event) {
//  QPainter painter(this);
//  painter.drawRect(ground->GetTransform().p.x - 200,
//                   ground->GetTransform().p.y - 10, 400, 5.0f);
//  QTransform transform;
//  transform.rotate(cube->GetAngle());
//  QPixmap rotated = pm.transformed(transform);
//  painter.drawPixmap(cube->GetPosition().x - 25, cube->GetPosition().y - 25,
//                     rotated);
//}

//void LabRubiksWidget::keyPressEvent(QKeyEvent *event) {
//  if (event->key() == Qt::Key_Space) {
//    cube->SetTransform(b2Vec2(150, 200), 0);
//    cube->SetLinearVelocity(b2Vec2(0, 0));

//    cube->ApplyLinearImpulse(b2Vec2(10000, -50000), cube->GetPosition(), true);
//    cube->SetAngularVelocity(500);
//  }
//}

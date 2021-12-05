#ifndef WINDOW3DCUBE_H
#define WINDOW3DCUBE_H

#include <QMainWindow>


namespace Ui {
class Window3DCube;
}

class Window3DCube : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window3DCube(QWidget *parent = nullptr);
    ~Window3DCube();

public slots:
    void open3DCubeWindow();



private:
    Ui::Window3DCube *ui;



};

#endif // WINDOW3DCUBE_H

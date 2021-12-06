#ifndef CUBE2DWINDOW_H
#define CUBE2DWINDOW_H

#include <QMainWindow>

namespace Ui {
class Cube2dWindow;
}

class Cube2dWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cube2dWindow(QWidget *parent = nullptr);
    ~Cube2dWindow();

private:
    Ui::Cube2dWindow *ui;
};

#endif // CUBE2DWINDOW_H

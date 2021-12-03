/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSolve;
    QAction *actionLearn;
    QWidget *centralwidget;
    QFrame *frameMainCube;
    QWidget *widgetFace0;
    QWidget *widgetFace1;
    QWidget *widgetFace3;
    QWidget *widgetFace4;
    QWidget *widgetFace5;
    QWidget *widgetFace6;
    QFrame *frameCubeDirBtns;
    QPushButton *btnReset;
    QPushButton *btnU2;
    QPushButton *btnU2_2;
    QPushButton *btnU2_3;
    QPushButton *btnU2_4;
    QPushButton *btnU2_5;
    QPushButton *btnU2_6;
    QPushButton *btnU2_7;
    QPushButton *btnU2_8;
    QPushButton *btnU2_9;
    QPushButton *btnU2_10;
    QPushButton *btnU2_11;
    QPushButton *btnU2_12;
    QPushButton *btnU2_13;
    QPushButton *btnU2_18;
    QPushButton *btnU2_17;
    QPushButton *btnU2_16;
    QPushButton *btnU2_15;
    QPushButton *btnU2_14;
    QFrame *frame;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menuMode;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionSolve = new QAction(MainWindow);
        actionSolve->setObjectName(QString::fromUtf8("actionSolve"));
        actionLearn = new QAction(MainWindow);
        actionLearn->setObjectName(QString::fromUtf8("actionLearn"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frameMainCube = new QFrame(centralwidget);
        frameMainCube->setObjectName(QString::fromUtf8("frameMainCube"));
        frameMainCube->setGeometry(QRect(70, 20, 531, 441));
        frameMainCube->setFrameShape(QFrame::StyledPanel);
        frameMainCube->setFrameShadow(QFrame::Raised);
        widgetFace0 = new QWidget(frameMainCube);
        widgetFace0->setObjectName(QString::fromUtf8("widgetFace0"));
        widgetFace0->setGeometry(QRect(150, 70, 120, 120));
        widgetFace1 = new QWidget(frameMainCube);
        widgetFace1->setObjectName(QString::fromUtf8("widgetFace1"));
        widgetFace1->setGeometry(QRect(150, 190, 120, 120));
        widgetFace3 = new QWidget(frameMainCube);
        widgetFace3->setObjectName(QString::fromUtf8("widgetFace3"));
        widgetFace3->setGeometry(QRect(150, 310, 120, 120));
        widgetFace4 = new QWidget(frameMainCube);
        widgetFace4->setObjectName(QString::fromUtf8("widgetFace4"));
        widgetFace4->setGeometry(QRect(30, 190, 120, 120));
        widgetFace5 = new QWidget(frameMainCube);
        widgetFace5->setObjectName(QString::fromUtf8("widgetFace5"));
        widgetFace5->setGeometry(QRect(270, 190, 120, 120));
        widgetFace6 = new QWidget(frameMainCube);
        widgetFace6->setObjectName(QString::fromUtf8("widgetFace6"));
        widgetFace6->setGeometry(QRect(390, 190, 120, 120));
        frameCubeDirBtns = new QFrame(centralwidget);
        frameCubeDirBtns->setObjectName(QString::fromUtf8("frameCubeDirBtns"));
        frameCubeDirBtns->setGeometry(QRect(70, 470, 531, 80));
        frameCubeDirBtns->setFrameShape(QFrame::StyledPanel);
        frameCubeDirBtns->setFrameShadow(QFrame::Raised);
        btnReset = new QPushButton(frameCubeDirBtns);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setGeometry(QRect(250, 60, 80, 22));
        btnU2 = new QPushButton(frameCubeDirBtns);
        btnU2->setObjectName(QString::fromUtf8("btnU2"));
        btnU2->setGeometry(QRect(10, 60, 30, 20));
        btnU2_2 = new QPushButton(frameCubeDirBtns);
        btnU2_2->setObjectName(QString::fromUtf8("btnU2_2"));
        btnU2_2->setGeometry(QRect(10, 0, 30, 20));
        btnU2_3 = new QPushButton(frameCubeDirBtns);
        btnU2_3->setObjectName(QString::fromUtf8("btnU2_3"));
        btnU2_3->setGeometry(QRect(50, 0, 30, 20));
        btnU2_4 = new QPushButton(frameCubeDirBtns);
        btnU2_4->setObjectName(QString::fromUtf8("btnU2_4"));
        btnU2_4->setGeometry(QRect(90, 0, 30, 20));
        btnU2_5 = new QPushButton(frameCubeDirBtns);
        btnU2_5->setObjectName(QString::fromUtf8("btnU2_5"));
        btnU2_5->setGeometry(QRect(130, 0, 30, 20));
        btnU2_6 = new QPushButton(frameCubeDirBtns);
        btnU2_6->setObjectName(QString::fromUtf8("btnU2_6"));
        btnU2_6->setGeometry(QRect(170, 0, 30, 20));
        btnU2_7 = new QPushButton(frameCubeDirBtns);
        btnU2_7->setObjectName(QString::fromUtf8("btnU2_7"));
        btnU2_7->setGeometry(QRect(210, 0, 30, 20));
        btnU2_8 = new QPushButton(frameCubeDirBtns);
        btnU2_8->setObjectName(QString::fromUtf8("btnU2_8"));
        btnU2_8->setGeometry(QRect(10, 30, 30, 20));
        btnU2_9 = new QPushButton(frameCubeDirBtns);
        btnU2_9->setObjectName(QString::fromUtf8("btnU2_9"));
        btnU2_9->setGeometry(QRect(50, 30, 30, 20));
        btnU2_10 = new QPushButton(frameCubeDirBtns);
        btnU2_10->setObjectName(QString::fromUtf8("btnU2_10"));
        btnU2_10->setGeometry(QRect(90, 30, 30, 20));
        btnU2_11 = new QPushButton(frameCubeDirBtns);
        btnU2_11->setObjectName(QString::fromUtf8("btnU2_11"));
        btnU2_11->setGeometry(QRect(130, 30, 30, 20));
        btnU2_12 = new QPushButton(frameCubeDirBtns);
        btnU2_12->setObjectName(QString::fromUtf8("btnU2_12"));
        btnU2_12->setGeometry(QRect(170, 30, 30, 20));
        btnU2_13 = new QPushButton(frameCubeDirBtns);
        btnU2_13->setObjectName(QString::fromUtf8("btnU2_13"));
        btnU2_13->setGeometry(QRect(210, 30, 30, 20));
        btnU2_18 = new QPushButton(frameCubeDirBtns);
        btnU2_18->setObjectName(QString::fromUtf8("btnU2_18"));
        btnU2_18->setGeometry(QRect(50, 60, 30, 20));
        btnU2_17 = new QPushButton(frameCubeDirBtns);
        btnU2_17->setObjectName(QString::fromUtf8("btnU2_17"));
        btnU2_17->setGeometry(QRect(90, 60, 30, 20));
        btnU2_16 = new QPushButton(frameCubeDirBtns);
        btnU2_16->setObjectName(QString::fromUtf8("btnU2_16"));
        btnU2_16->setGeometry(QRect(130, 60, 30, 20));
        btnU2_15 = new QPushButton(frameCubeDirBtns);
        btnU2_15->setObjectName(QString::fromUtf8("btnU2_15"));
        btnU2_15->setGeometry(QRect(170, 60, 30, 20));
        btnU2_14 = new QPushButton(frameCubeDirBtns);
        btnU2_14->setObjectName(QString::fromUtf8("btnU2_14"));
        btnU2_14->setGeometry(QRect(210, 60, 30, 20));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(630, 180, 120, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        plainTextEdit = new QPlainTextEdit(frame);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 10, 104, 311));
        MainWindow->setCentralWidget(centralwidget);
        frameCubeDirBtns->raise();
        frameMainCube->raise();
        frame->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuMode = new QMenu(menubar);
        menuMode->setObjectName(QString::fromUtf8("menuMode"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMode->menuAction());
        menuMode->addSeparator();
        menuMode->addAction(actionSolve);
        menuMode->addAction(actionLearn);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSolve->setText(QCoreApplication::translate("MainWindow", "Solve", nullptr));
        actionLearn->setText(QCoreApplication::translate("MainWindow", "Learn", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        btnU2->setText(QCoreApplication::translate("MainWindow", "U2", nullptr));
        btnU2_2->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
        btnU2_3->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        btnU2_4->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        btnU2_5->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        btnU2_6->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        btnU2_7->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        btnU2_8->setText(QCoreApplication::translate("MainWindow", "U'", nullptr));
        btnU2_9->setText(QCoreApplication::translate("MainWindow", "D'", nullptr));
        btnU2_10->setText(QCoreApplication::translate("MainWindow", "L'", nullptr));
        btnU2_11->setText(QCoreApplication::translate("MainWindow", "R'", nullptr));
        btnU2_12->setText(QCoreApplication::translate("MainWindow", "F'", nullptr));
        btnU2_13->setText(QCoreApplication::translate("MainWindow", "B'", nullptr));
        btnU2_18->setText(QCoreApplication::translate("MainWindow", "D2", nullptr));
        btnU2_17->setText(QCoreApplication::translate("MainWindow", "L2", nullptr));
        btnU2_16->setText(QCoreApplication::translate("MainWindow", "R2", nullptr));
        btnU2_15->setText(QCoreApplication::translate("MainWindow", "F2", nullptr));
        btnU2_14->setText(QCoreApplication::translate("MainWindow", "B2", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "\"In order to write down sequences of movements on the cube, we use a notation of six main letters:\n"
"\n"
"U for Up\n"
"D for Down\n"
"L for Left\n"
"R for Right\n"
"F for Front\n"
"B for Back\n"
"\n"
"These letters are used in sequences known as algorithms, and you just perform each letter in the algorithm from left to right. Each letter simply tells you to move that face clockwise by 90 degrees. An apostrophe after a letter (like F', said 'anti-front') tells you to move that face anticlockwise instead, and 2 after a letter (like R2) tells you to move that face by 180 degrees.\n"
"\n"
"It is important to remember that each move should be done as if you were looking directly at the face that the move affects. U and D are clockwise turns for the Up and Down faces, but if you turn the top and bottom layers in the same way while looking at the Up face for both moves, you actually perform U and D'. Use this helpful array of buttons to see how each move affects a solved cube, so you can see how to perform them co"
                        "rrectly.\"", nullptr));
        menuMode->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

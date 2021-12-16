/*
 * Lacking Ideas - Rubiks Educational App
 * CS 3505 - A9 - An Education App
 * @authors:
 *           Ronnie Koe
 *           Maiko Tuitupou
 * TutorialBrowser.h
*/

#ifndef TUTORIALBROWSER_H
#define TUTORIALBROWSER_H

#include <QTextBrowser>

class TutorialBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    TutorialBrowser(QWidget *parent = nullptr);

signals:
    void tutorialStepChanged(int stepNumber);

public slots:
    void setTutorialStep(int stepNumber);

private slots:
    void handleAnchorClicked(QUrl url);
};

#endif // TUTORIALBROWSER_H

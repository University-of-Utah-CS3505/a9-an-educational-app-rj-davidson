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

private slots:
    void handleAnchorClicked(QUrl url);
};

#endif // TUTORIALBROWSER_H

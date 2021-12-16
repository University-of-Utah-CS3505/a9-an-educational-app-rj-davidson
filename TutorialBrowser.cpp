/*
 * Lacking Ideas - Rubiks Educational App
 * CS 3505 - A9 - An Education App
 * @authors: Ronnie Koe
 *           Maiko Tuitupou
 * TutorialBrowser.cpp
*/

#include "TutorialBrowser.h"
#include <QTextDocument>

TutorialBrowser::TutorialBrowser(QWidget *parent) : QTextBrowser(parent)
{
    setOpenLinks(false);
    setSource(QUrl("qrc:/html/home.html"), QTextDocument::HtmlResource);
    connect(this, &QTextBrowser::anchorClicked, this, &TutorialBrowser::handleAnchorClicked);
}

void TutorialBrowser::setTutorialStep(int stepNumber)
{
    if (stepNumber > 0 && stepNumber < 9)
    {
        setSource(QUrl(QString("qrc:/html/step%1.html").arg(stepNumber)), QTextDocument::HtmlResource);
    }
    else
    {
        home();
    }
}

void TutorialBrowser::handleAnchorClicked(QUrl url)
{
    if (url.fileName() != source().fileName() && url.fileName().endsWith(".html"))
    {
        if (url.fileName().startsWith("step"))
        {
            QString file = url.fileName().left(url.fileName().size() - 5);
            std::string str = file.toStdString();
            size_t lastIndex = str.find_last_not_of("0123456789");
            if (lastIndex != str.length())
            {
                std::string intAtEndOfString = str.substr(lastIndex + 1);
                int stepID = std::stoi(intAtEndOfString);
                emit tutorialStepChanged(stepID);
            }
        }
        else
        {
            setSource(url);
        }
    }
    if (url.hasFragment())
    {
        scrollToAnchor(url.fragment());
    }
}

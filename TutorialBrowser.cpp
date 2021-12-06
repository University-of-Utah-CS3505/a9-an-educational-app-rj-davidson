#include "TutorialBrowser.h"
#include <QTextDocument>

TutorialBrowser::TutorialBrowser(QWidget *parent): QTextBrowser(parent)
{
    setSource(QUrl("qrc:/html/home.html"), QTextDocument::HtmlResource);
    connect(this, &QTextBrowser::anchorClicked, this, &TutorialBrowser::handleAnchorClicked);
}

void TutorialBrowser::handleAnchorClicked(QUrl url) {
    std::string str = url.toString().toStdString();
    size_t lastIndex = str.find_last_not_of("0123456789");
    if(lastIndex != str.length()) {
        std::string intAtEndOfString = str.substr(lastIndex+1);
        int stepID = std::stoi(intAtEndOfString);
        emit tutorialStepChanged(stepID);
    }
}

/********************************************************************************
** Form generated from reading UI file 'StudyResourse.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDYRESOURSE_H
#define UI_STUDYRESOURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudyResourse
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *StudyResourse)
    {
        if (StudyResourse->objectName().isEmpty())
            StudyResourse->setObjectName(QString::fromUtf8("StudyResourse"));
        StudyResourse->resize(400, 300);
        verticalLayout = new QVBoxLayout(StudyResourse);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(StudyResourse);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(StudyResourse);

        QMetaObject::connectSlotsByName(StudyResourse);
    } // setupUi

    void retranslateUi(QDialog *StudyResourse)
    {
        StudyResourse->setWindowTitle(QApplication::translate("StudyResourse", "StudyResourse", nullptr));
        textBrowser->setHtml(QApplication::translate("StudyResourse", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\255\244\345\244\204\346\230\276\347\244\272\346\225\231\345\255\246\346\226\207\346\241\243</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudyResourse: public Ui_StudyResourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYRESOURSE_H

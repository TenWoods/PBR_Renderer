/********************************************************************************
** Form generated from reading UI file 'StudyResourseGjrjPQ.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STUDYRESOURSEGJRJPQ_H
#define STUDYRESOURSEGJRJPQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudyResourse
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *upButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *downButton;

    void setupUi(QDialog *StudyResourse)
    {
        if (StudyResourse->objectName().isEmpty())
            StudyResourse->setObjectName(QString::fromUtf8("StudyResourse"));
        StudyResourse->resize(581, 615);
        verticalLayout = new QVBoxLayout(StudyResourse);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(StudyResourse);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 561, 548));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        widget = new QWidget(StudyResourse);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        upButton = new QPushButton(widget);
        upButton->setObjectName(QString::fromUtf8("upButton"));

        horizontalLayout->addWidget(upButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        downButton = new QPushButton(widget);
        downButton->setObjectName(QString::fromUtf8("downButton"));

        horizontalLayout->addWidget(downButton);


        verticalLayout->addWidget(widget);


        retranslateUi(StudyResourse);

        QMetaObject::connectSlotsByName(StudyResourse);
    } // setupUi

    void retranslateUi(QDialog *StudyResourse)
    {
        StudyResourse->setWindowTitle(QApplication::translate("StudyResourse", "StudyResourse", nullptr));
        label->setText(QApplication::translate("StudyResourse", "TextLabel", nullptr));
        upButton->setText(QApplication::translate("StudyResourse", "\344\270\212\344\270\200\351\241\265", nullptr));
        downButton->setText(QApplication::translate("StudyResourse", "\344\270\213\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudyResourse: public Ui_StudyResourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STUDYRESOURSEGJRJPQ_H

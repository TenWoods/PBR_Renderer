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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudyResourse
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
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
        StudyResourse->resize(714, 1010);
        verticalLayout = new QVBoxLayout(StudyResourse);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(StudyResourse);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 551, 541));

        verticalLayout->addWidget(widget_2);

        widget = new QWidget(StudyResourse);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
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

#endif // UI_STUDYRESOURSE_H

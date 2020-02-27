/********************************************************************************
** Form generated from reading UI file 'Render.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDER_H
#define UI_RENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QOpenGLWidget>

QT_BEGIN_NAMESPACE

class Ui_Render
{
public:

    void setupUi(QOpenGLWidget *Render)
    {
        if (Render->objectName().isEmpty())
            Render->setObjectName(QString::fromUtf8("Render"));
        Render->resize(400, 300);
        Render->setMouseTracking(false);
        Render->setFocusPolicy(Qt::ClickFocus);

        retranslateUi(Render);

        QMetaObject::connectSlotsByName(Render);
    } // setupUi

    void retranslateUi(QOpenGLWidget *Render)
    {
        Render->setWindowTitle(QApplication::translate("Render", "Render", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Render: public Ui_Render {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDER_H

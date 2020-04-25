/********************************************************************************
** Form generated from reading UI file 'PBR_Renderer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PBR_RENDERER_H
#define UI_PBR_RENDERER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "property.h"
#include "render.h"

QT_BEGIN_NAMESPACE

class Ui_PBR_RendererClass
{
public:
    QAction *actionNewScene;
    QAction *actionOpenScene;
    QAction *actionSaveScene;
    QAction *actionLoadModel;
    QAction *actionNewTexture;
    QAction *actionLoadTexture;
    QAction *actionPBRMaterial;
    QAction *actionindirectDiffuse;
    QAction *actionIBL;
    QAction *actionPartone;
    QAction *actionsphere;
    QAction *actioncube;
    QAction *actionParttwo;
    QAction *actionPartthree;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    Render *render;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *functionMenu;
    QMenu *learnMenu;
    QDockWidget *sceneDockWidget;
    QWidget *scenedockWidgetContent;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_2;
    QWidget *scene;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeView;
    QWidget *skybox;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QPushButton *envButton;
    QDockWidget *informationDockWidget;
    QWidget *informationDockWidgetContent;
    QVBoxLayout *verticalLayout_2;
    Property *property;

    void setupUi(QMainWindow *PBR_RendererClass)
    {
        if (PBR_RendererClass->objectName().isEmpty())
            PBR_RendererClass->setObjectName(QString::fromUtf8("PBR_RendererClass"));
        PBR_RendererClass->resize(1200, 800);
        actionNewScene = new QAction(PBR_RendererClass);
        actionNewScene->setObjectName(QString::fromUtf8("actionNewScene"));
        actionNewScene->setEnabled(false);
        actionOpenScene = new QAction(PBR_RendererClass);
        actionOpenScene->setObjectName(QString::fromUtf8("actionOpenScene"));
        actionOpenScene->setEnabled(false);
        actionSaveScene = new QAction(PBR_RendererClass);
        actionSaveScene->setObjectName(QString::fromUtf8("actionSaveScene"));
        actionSaveScene->setEnabled(false);
        actionLoadModel = new QAction(PBR_RendererClass);
        actionLoadModel->setObjectName(QString::fromUtf8("actionLoadModel"));
        actionLoadModel->setEnabled(true);
        actionNewTexture = new QAction(PBR_RendererClass);
        actionNewTexture->setObjectName(QString::fromUtf8("actionNewTexture"));
        actionNewTexture->setEnabled(false);
        actionLoadTexture = new QAction(PBR_RendererClass);
        actionLoadTexture->setObjectName(QString::fromUtf8("actionLoadTexture"));
        actionLoadTexture->setEnabled(false);
        actionPBRMaterial = new QAction(PBR_RendererClass);
        actionPBRMaterial->setObjectName(QString::fromUtf8("actionPBRMaterial"));
        actionPBRMaterial->setCheckable(true);
        actionPBRMaterial->setChecked(false);
        actionPBRMaterial->setEnabled(true);
        actionindirectDiffuse = new QAction(PBR_RendererClass);
        actionindirectDiffuse->setObjectName(QString::fromUtf8("actionindirectDiffuse"));
        actionindirectDiffuse->setCheckable(true);
        actionindirectDiffuse->setEnabled(true);
        actionIBL = new QAction(PBR_RendererClass);
        actionIBL->setObjectName(QString::fromUtf8("actionIBL"));
        actionIBL->setCheckable(true);
        actionIBL->setEnabled(true);
        actionPartone = new QAction(PBR_RendererClass);
        actionPartone->setObjectName(QString::fromUtf8("actionPartone"));
        actionsphere = new QAction(PBR_RendererClass);
        actionsphere->setObjectName(QString::fromUtf8("actionsphere"));
        actioncube = new QAction(PBR_RendererClass);
        actioncube->setObjectName(QString::fromUtf8("actioncube"));
        actionParttwo = new QAction(PBR_RendererClass);
        actionParttwo->setObjectName(QString::fromUtf8("actionParttwo"));
        actionPartthree = new QAction(PBR_RendererClass);
        actionPartthree->setObjectName(QString::fromUtf8("actionPartthree"));
        centralWidget = new QWidget(PBR_RendererClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        render = new Render(centralWidget);
        render->setObjectName(QString::fromUtf8("render"));

        horizontalLayout->addWidget(render);

        PBR_RendererClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PBR_RendererClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        functionMenu = new QMenu(menuBar);
        functionMenu->setObjectName(QString::fromUtf8("functionMenu"));
        learnMenu = new QMenu(menuBar);
        learnMenu->setObjectName(QString::fromUtf8("learnMenu"));
        PBR_RendererClass->setMenuBar(menuBar);
        sceneDockWidget = new QDockWidget(PBR_RendererClass);
        sceneDockWidget->setObjectName(QString::fromUtf8("sceneDockWidget"));
        sceneDockWidget->setMinimumSize(QSize(278, 300));
        sceneDockWidget->setMaximumSize(QSize(350, 524287));
        scenedockWidgetContent = new QWidget();
        scenedockWidgetContent->setObjectName(QString::fromUtf8("scenedockWidgetContent"));
        scenedockWidgetContent->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(scenedockWidgetContent);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(scenedockWidgetContent);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        scene = new QWidget();
        scene->setObjectName(QString::fromUtf8("scene"));
        verticalLayout_3 = new QVBoxLayout(scene);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(scene);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_3->addWidget(treeView);

        tabWidget_2->addTab(scene, QString());
        skybox = new QWidget();
        skybox->setObjectName(QString::fromUtf8("skybox"));
        verticalLayout_5 = new QVBoxLayout(skybox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(skybox);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        envButton = new QPushButton(widget);
        envButton->setObjectName(QString::fromUtf8("envButton"));

        verticalLayout_4->addWidget(envButton);


        verticalLayout_5->addWidget(widget);

        tabWidget_2->addTab(skybox, QString());

        verticalLayout->addWidget(tabWidget_2);

        sceneDockWidget->setWidget(scenedockWidgetContent);
        PBR_RendererClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), sceneDockWidget);
        informationDockWidget = new QDockWidget(PBR_RendererClass);
        informationDockWidget->setObjectName(QString::fromUtf8("informationDockWidget"));
        informationDockWidget->setMinimumSize(QSize(200, 280));
        informationDockWidget->setMaximumSize(QSize(350, 524287));
        informationDockWidgetContent = new QWidget();
        informationDockWidgetContent->setObjectName(QString::fromUtf8("informationDockWidgetContent"));
        verticalLayout_2 = new QVBoxLayout(informationDockWidgetContent);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        property = new Property(informationDockWidgetContent);
        property->setObjectName(QString::fromUtf8("property"));

        verticalLayout_2->addWidget(property);

        informationDockWidget->setWidget(informationDockWidgetContent);
        PBR_RendererClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), informationDockWidget);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(functionMenu->menuAction());
        menuBar->addAction(learnMenu->menuAction());
        menu->addAction(actionNewScene);
        menu->addAction(actionOpenScene);
        menu->addAction(actionSaveScene);
        menu->addSeparator();
        menu->addAction(actionLoadModel);
        menu->addAction(menu_2->menuAction());
        menu->addSeparator();
        menu->addAction(actionNewTexture);
        menu->addAction(actionLoadTexture);
        menu_2->addAction(actionsphere);
        menu_2->addAction(actioncube);
        functionMenu->addAction(actionPBRMaterial);
        functionMenu->addSeparator();
        functionMenu->addAction(actionindirectDiffuse);
        functionMenu->addSeparator();
        functionMenu->addAction(actionIBL);
        learnMenu->addAction(actionPartone);
        learnMenu->addAction(actionParttwo);
        learnMenu->addAction(actionPartthree);

        retranslateUi(PBR_RendererClass);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PBR_RendererClass);
    } // setupUi

    void retranslateUi(QMainWindow *PBR_RendererClass)
    {
        PBR_RendererClass->setWindowTitle(QApplication::translate("PBR_RendererClass", "PBR\346\225\231\345\255\246\346\270\262\346\237\223\345\231\250", nullptr));
        actionNewScene->setText(QApplication::translate("PBR_RendererClass", "\346\226\260\345\273\272\345\234\272\346\231\257", nullptr));
        actionOpenScene->setText(QApplication::translate("PBR_RendererClass", "\346\211\223\345\274\200\345\234\272\346\231\257", nullptr));
        actionSaveScene->setText(QApplication::translate("PBR_RendererClass", "\344\277\235\345\255\230\345\234\272\346\231\257", nullptr));
        actionLoadModel->setText(QApplication::translate("PBR_RendererClass", "\345\212\240\350\275\275\346\250\241\345\236\213", nullptr));
        actionNewTexture->setText(QApplication::translate("PBR_RendererClass", "\346\226\260\345\273\272\346\235\220\350\264\250", nullptr));
        actionLoadTexture->setText(QApplication::translate("PBR_RendererClass", "\345\212\240\350\275\275\346\235\220\350\264\250", nullptr));
        actionPBRMaterial->setText(QApplication::translate("PBR_RendererClass", "PBR\346\235\220\350\264\250\344\270\216\347\233\264\346\216\245\345\205\211\347\205\247", nullptr));
        actionindirectDiffuse->setText(QApplication::translate("PBR_RendererClass", "\351\227\264\346\216\245\346\274\253\345\217\215\345\260\204", nullptr));
        actionIBL->setText(QApplication::translate("PBR_RendererClass", "IBL\351\227\264\346\216\245\351\225\234\351\235\242\345\217\215\345\260\204", nullptr));
        actionPartone->setText(QApplication::translate("PBR_RendererClass", "PBR\346\235\220\350\264\250\351\203\250\345\210\206", nullptr));
        actionsphere->setText(QApplication::translate("PBR_RendererClass", "\347\220\203", nullptr));
        actioncube->setText(QApplication::translate("PBR_RendererClass", "\347\253\213\346\226\271\344\275\223", nullptr));
        actionParttwo->setText(QApplication::translate("PBR_RendererClass", "\351\227\264\346\216\245\346\274\253\345\217\215\345\260\204\351\203\250\345\210\206", nullptr));
        actionPartthree->setText(QApplication::translate("PBR_RendererClass", "IBL\351\227\264\346\216\245\351\225\234\351\235\242\345\217\215\345\260\204", nullptr));
        menu->setTitle(QApplication::translate("PBR_RendererClass", "\350\217\234\345\215\225", nullptr));
        menu_2->setTitle(QApplication::translate("PBR_RendererClass", "\346\226\260\345\273\272\351\273\230\350\256\244\347\211\251\344\275\223", nullptr));
        functionMenu->setTitle(QApplication::translate("PBR_RendererClass", "\345\212\237\350\203\275\350\247\243\351\224\201", nullptr));
        learnMenu->setTitle(QApplication::translate("PBR_RendererClass", "\345\255\246\344\271\240", nullptr));
        sceneDockWidget->setWindowTitle(QApplication::translate("PBR_RendererClass", "\345\234\272\346\231\257\344\270\216\345\244\251\347\251\272\347\233\222", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(scene), QApplication::translate("PBR_RendererClass", "\345\234\272\346\231\257", nullptr));
        label->setText(QApplication::translate("PBR_RendererClass", "TextLabel", nullptr));
        envButton->setText(QApplication::translate("PBR_RendererClass", "\351\200\211\346\213\251\347\216\257\345\242\203\350\264\264\345\233\276", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(skybox), QApplication::translate("PBR_RendererClass", "\347\216\257\345\242\203\350\264\264\345\233\276", nullptr));
        informationDockWidget->setWindowTitle(QApplication::translate("PBR_RendererClass", "\345\261\236\346\200\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PBR_RendererClass: public Ui_PBR_RendererClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PBR_RENDERER_H

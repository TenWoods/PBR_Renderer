/********************************************************************************
** Form generated from reading UI file 'PBR_RenderercsMqjr.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PBR_RENDERERCSMQJR_H
#define PBR_RENDERERCSMQJR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *frontLabel;
    QLabel *rightLabel;
    QLabel *backSkybox;
    QLabel *rightSkybox;
    QLabel *frontSkybox;
    QLabel *downSkybox;
    QLabel *downLabel;
    QLabel *leftSkybox;
    QLabel *backLabel;
    QLabel *leftLabel;
    QLabel *upLabel;
    QLabel *upSkybox;
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
        actionOpenScene = new QAction(PBR_RendererClass);
        actionOpenScene->setObjectName(QString::fromUtf8("actionOpenScene"));
        actionSaveScene = new QAction(PBR_RendererClass);
        actionSaveScene->setObjectName(QString::fromUtf8("actionSaveScene"));
        actionLoadModel = new QAction(PBR_RendererClass);
        actionLoadModel->setObjectName(QString::fromUtf8("actionLoadModel"));
        actionNewTexture = new QAction(PBR_RendererClass);
        actionNewTexture->setObjectName(QString::fromUtf8("actionNewTexture"));
        actionLoadTexture = new QAction(PBR_RendererClass);
        actionLoadTexture->setObjectName(QString::fromUtf8("actionLoadTexture"));
        actionPBRMaterial = new QAction(PBR_RendererClass);
        actionPBRMaterial->setObjectName(QString::fromUtf8("actionPBRMaterial"));
        actionPBRMaterial->setCheckable(true);
        actionPBRMaterial->setChecked(false);
        actionPBRMaterial->setEnabled(true);
        actionindirectDiffuse = new QAction(PBR_RendererClass);
        actionindirectDiffuse->setObjectName(QString::fromUtf8("actionindirectDiffuse"));
        actionindirectDiffuse->setCheckable(true);
        actionIBL = new QAction(PBR_RendererClass);
        actionIBL->setObjectName(QString::fromUtf8("actionIBL"));
        actionIBL->setCheckable(true);
        actionPartone = new QAction(PBR_RendererClass);
        actionPartone->setObjectName(QString::fromUtf8("actionPartone"));
        actionsphere = new QAction(PBR_RendererClass);
        actionsphere->setObjectName(QString::fromUtf8("actionsphere"));
        actioncube = new QAction(PBR_RendererClass);
        actioncube->setObjectName(QString::fromUtf8("actioncube"));
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
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
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
        verticalLayout_5->setContentsMargins(2, 2, 2, 2);
        scrollArea = new QScrollArea(skybox);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 266, 347));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frontLabel = new QLabel(scrollAreaWidgetContents);
        frontLabel->setObjectName(QString::fromUtf8("frontLabel"));

        gridLayout->addWidget(frontLabel, 2, 0, 1, 1);

        rightLabel = new QLabel(scrollAreaWidgetContents);
        rightLabel->setObjectName(QString::fromUtf8("rightLabel"));

        gridLayout->addWidget(rightLabel, 1, 3, 1, 2);

        backSkybox = new QLabel(scrollAreaWidgetContents);
        backSkybox->setObjectName(QString::fromUtf8("backSkybox"));

        gridLayout->addWidget(backSkybox, 2, 5, 1, 2);

        rightSkybox = new QLabel(scrollAreaWidgetContents);
        rightSkybox->setObjectName(QString::fromUtf8("rightSkybox"));

        gridLayout->addWidget(rightSkybox, 1, 5, 1, 2);

        frontSkybox = new QLabel(scrollAreaWidgetContents);
        frontSkybox->setObjectName(QString::fromUtf8("frontSkybox"));

        gridLayout->addWidget(frontSkybox, 2, 1, 1, 2);

        downSkybox = new QLabel(scrollAreaWidgetContents);
        downSkybox->setObjectName(QString::fromUtf8("downSkybox"));

        gridLayout->addWidget(downSkybox, 0, 6, 1, 1);

        downLabel = new QLabel(scrollAreaWidgetContents);
        downLabel->setObjectName(QString::fromUtf8("downLabel"));

        gridLayout->addWidget(downLabel, 0, 4, 1, 2);

        leftSkybox = new QLabel(scrollAreaWidgetContents);
        leftSkybox->setObjectName(QString::fromUtf8("leftSkybox"));

        gridLayout->addWidget(leftSkybox, 1, 1, 1, 2);

        backLabel = new QLabel(scrollAreaWidgetContents);
        backLabel->setObjectName(QString::fromUtf8("backLabel"));

        gridLayout->addWidget(backLabel, 2, 3, 1, 2);

        leftLabel = new QLabel(scrollAreaWidgetContents);
        leftLabel->setObjectName(QString::fromUtf8("leftLabel"));

        gridLayout->addWidget(leftLabel, 1, 0, 1, 1);

        upLabel = new QLabel(scrollAreaWidgetContents);
        upLabel->setObjectName(QString::fromUtf8("upLabel"));

        gridLayout->addWidget(upLabel, 0, 0, 1, 1);

        upSkybox = new QLabel(scrollAreaWidgetContents);
        upSkybox->setObjectName(QString::fromUtf8("upSkybox"));

        gridLayout->addWidget(upSkybox, 0, 1, 1, 3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        tabWidget_2->addTab(skybox, QString());

        verticalLayout->addWidget(tabWidget_2);

        sceneDockWidget->setWidget(scenedockWidgetContent);
        PBR_RendererClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), sceneDockWidget);
        informationDockWidget = new QDockWidget(PBR_RendererClass);
        informationDockWidget->setObjectName(QString::fromUtf8("informationDockWidget"));
        informationDockWidget->setMinimumSize(QSize(200, 280));
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

        retranslateUi(PBR_RendererClass);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PBR_RendererClass);
    } // setupUi

    void retranslateUi(QMainWindow *PBR_RendererClass)
    {
        PBR_RendererClass->setWindowTitle(QApplication::translate("PBR_RendererClass", "PBR_Renderer", nullptr));
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
        menu->setTitle(QApplication::translate("PBR_RendererClass", "\350\217\234\345\215\225", nullptr));
        menu_2->setTitle(QApplication::translate("PBR_RendererClass", "\346\226\260\345\273\272\351\273\230\350\256\244\347\211\251\344\275\223", nullptr));
        functionMenu->setTitle(QApplication::translate("PBR_RendererClass", "\345\212\237\350\203\275\350\247\243\351\224\201", nullptr));
        learnMenu->setTitle(QApplication::translate("PBR_RendererClass", "\345\255\246\344\271\240", nullptr));
        sceneDockWidget->setWindowTitle(QApplication::translate("PBR_RendererClass", "\345\234\272\346\231\257\344\270\216\345\244\251\347\251\272\347\233\222", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(scene), QApplication::translate("PBR_RendererClass", "\345\234\272\346\231\257", nullptr));
        frontLabel->setText(QApplication::translate("PBR_RendererClass", "\345\211\215:", nullptr));
        rightLabel->setText(QApplication::translate("PBR_RendererClass", "\345\217\263:", nullptr));
        backSkybox->setText(QApplication::translate("PBR_RendererClass", "TextLabel", nullptr));
        rightSkybox->setText(QApplication::translate("PBR_RendererClass", "TextLabel", nullptr));
        frontSkybox->setText(QApplication::translate("PBR_RendererClass", "TextLabel", nullptr));
        downSkybox->setText(QApplication::translate("PBR_RendererClass", "TextLabel", nullptr));
        downLabel->setText(QApplication::translate("PBR_RendererClass", "\344\270\213:", nullptr));
        leftSkybox->setText(QApplication::translate("PBR_RendererClass", "TextLabel", nullptr));
        backLabel->setText(QApplication::translate("PBR_RendererClass", "\345\220\216:", nullptr));
        leftLabel->setText(QApplication::translate("PBR_RendererClass", "\345\267\246:", nullptr));
        upLabel->setText(QApplication::translate("PBR_RendererClass", "\344\270\212:", nullptr));
        upSkybox->setText(QApplication::translate("PBR_RendererClass", "TextLabel", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(skybox), QApplication::translate("PBR_RendererClass", "\345\244\251\347\251\272\347\233\222", nullptr));
        informationDockWidget->setWindowTitle(QApplication::translate("PBR_RendererClass", "\345\261\236\346\200\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PBR_RendererClass: public Ui_PBR_RendererClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PBR_RENDERERCSMQJR_H

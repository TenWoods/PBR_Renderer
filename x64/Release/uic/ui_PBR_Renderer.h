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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QAction *actionParttwo;
    QAction *actionPartthree;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioButton_pointlight1;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_p1px;
    QLineEdit *lineEdit_p1py;
    QLineEdit *lineEdit_p1pz;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_p1cr;
    QLineEdit *lineEdit_p1cg;
    QLineEdit *lineEdit_p1cb;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_9;
    QRadioButton *radioButton_pointlight2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_p2px;
    QLineEdit *lineEdit_p2py;
    QLineEdit *lineEdit_p2pz;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_p2cr;
    QLineEdit *lineEdit_p2cg;
    QLineEdit *lineEdit_p2cb;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *radioButton_spotlight;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_spx;
    QLineEdit *lineEdit_spy;
    QLineEdit *lineEdit_spz;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_sdx;
    QLineEdit *lineEdit_sdy;
    QLineEdit *lineEdit_sdz;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_scr;
    QLineEdit *lineEdit_scg;
    QLineEdit *lineEdit_scb;
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
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        render = new Render(centralWidget);
        render->setObjectName(QString::fromUtf8("render"));

        verticalLayout_6->addWidget(render);

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
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 325, 440));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        radioButton_pointlight1 = new QRadioButton(widget_2);
        radioButton_pointlight1->setObjectName(QString::fromUtf8("radioButton_pointlight1"));
        radioButton_pointlight1->setEnabled(true);
        radioButton_pointlight1->setChecked(true);

        verticalLayout_7->addWidget(radioButton_pointlight1);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout = new QHBoxLayout(widget_6);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_6);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_p1px = new QLineEdit(widget_6);
        lineEdit_p1px->setObjectName(QString::fromUtf8("lineEdit_p1px"));

        horizontalLayout->addWidget(lineEdit_p1px);

        lineEdit_p1py = new QLineEdit(widget_6);
        lineEdit_p1py->setObjectName(QString::fromUtf8("lineEdit_p1py"));

        horizontalLayout->addWidget(lineEdit_p1py);

        lineEdit_p1pz = new QLineEdit(widget_6);
        lineEdit_p1pz->setObjectName(QString::fromUtf8("lineEdit_p1pz"));

        horizontalLayout->addWidget(lineEdit_p1pz);


        verticalLayout_7->addWidget(widget_6);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_p1cr = new QLineEdit(widget_3);
        lineEdit_p1cr->setObjectName(QString::fromUtf8("lineEdit_p1cr"));

        horizontalLayout_2->addWidget(lineEdit_p1cr);

        lineEdit_p1cg = new QLineEdit(widget_3);
        lineEdit_p1cg->setObjectName(QString::fromUtf8("lineEdit_p1cg"));

        horizontalLayout_2->addWidget(lineEdit_p1cg);

        lineEdit_p1cb = new QLineEdit(widget_3);
        lineEdit_p1cb->setObjectName(QString::fromUtf8("lineEdit_p1cb"));

        horizontalLayout_2->addWidget(lineEdit_p1cb);


        verticalLayout_7->addWidget(widget_3);


        verticalLayout_8->addWidget(widget_2);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_9 = new QVBoxLayout(widget_4);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        radioButton_pointlight2 = new QRadioButton(widget_4);
        radioButton_pointlight2->setObjectName(QString::fromUtf8("radioButton_pointlight2"));
        radioButton_pointlight2->setChecked(true);

        verticalLayout_9->addWidget(radioButton_pointlight2);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_p2px = new QLineEdit(widget_7);
        lineEdit_p2px->setObjectName(QString::fromUtf8("lineEdit_p2px"));

        horizontalLayout_3->addWidget(lineEdit_p2px);

        lineEdit_p2py = new QLineEdit(widget_7);
        lineEdit_p2py->setObjectName(QString::fromUtf8("lineEdit_p2py"));

        horizontalLayout_3->addWidget(lineEdit_p2py);

        lineEdit_p2pz = new QLineEdit(widget_7);
        lineEdit_p2pz->setObjectName(QString::fromUtf8("lineEdit_p2pz"));

        horizontalLayout_3->addWidget(lineEdit_p2pz);


        verticalLayout_9->addWidget(widget_7);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_p2cr = new QLineEdit(widget_5);
        lineEdit_p2cr->setObjectName(QString::fromUtf8("lineEdit_p2cr"));

        horizontalLayout_4->addWidget(lineEdit_p2cr);

        lineEdit_p2cg = new QLineEdit(widget_5);
        lineEdit_p2cg->setObjectName(QString::fromUtf8("lineEdit_p2cg"));

        horizontalLayout_4->addWidget(lineEdit_p2cg);

        lineEdit_p2cb = new QLineEdit(widget_5);
        lineEdit_p2cb->setObjectName(QString::fromUtf8("lineEdit_p2cb"));

        horizontalLayout_4->addWidget(lineEdit_p2cb);


        verticalLayout_9->addWidget(widget_5);


        verticalLayout_8->addWidget(widget_4);

        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_10 = new QVBoxLayout(widget_8);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        radioButton_spotlight = new QRadioButton(widget_8);
        radioButton_spotlight->setObjectName(QString::fromUtf8("radioButton_spotlight"));
        radioButton_spotlight->setChecked(true);

        verticalLayout_10->addWidget(radioButton_spotlight);

        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_5 = new QHBoxLayout(widget_9);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(widget_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_spx = new QLineEdit(widget_9);
        lineEdit_spx->setObjectName(QString::fromUtf8("lineEdit_spx"));

        horizontalLayout_5->addWidget(lineEdit_spx);

        lineEdit_spy = new QLineEdit(widget_9);
        lineEdit_spy->setObjectName(QString::fromUtf8("lineEdit_spy"));

        horizontalLayout_5->addWidget(lineEdit_spy);

        lineEdit_spz = new QLineEdit(widget_9);
        lineEdit_spz->setObjectName(QString::fromUtf8("lineEdit_spz"));

        horizontalLayout_5->addWidget(lineEdit_spz);


        verticalLayout_10->addWidget(widget_9);

        widget_10 = new QWidget(widget_8);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_6 = new QHBoxLayout(widget_10);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(widget_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_sdx = new QLineEdit(widget_10);
        lineEdit_sdx->setObjectName(QString::fromUtf8("lineEdit_sdx"));

        horizontalLayout_6->addWidget(lineEdit_sdx);

        lineEdit_sdy = new QLineEdit(widget_10);
        lineEdit_sdy->setObjectName(QString::fromUtf8("lineEdit_sdy"));

        horizontalLayout_6->addWidget(lineEdit_sdy);

        lineEdit_sdz = new QLineEdit(widget_10);
        lineEdit_sdz->setObjectName(QString::fromUtf8("lineEdit_sdz"));

        horizontalLayout_6->addWidget(lineEdit_sdz);


        verticalLayout_10->addWidget(widget_10);

        widget_11 = new QWidget(widget_8);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_7 = new QHBoxLayout(widget_11);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(widget_11);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_scr = new QLineEdit(widget_11);
        lineEdit_scr->setObjectName(QString::fromUtf8("lineEdit_scr"));

        horizontalLayout_7->addWidget(lineEdit_scr);

        lineEdit_scg = new QLineEdit(widget_11);
        lineEdit_scg->setObjectName(QString::fromUtf8("lineEdit_scg"));

        horizontalLayout_7->addWidget(lineEdit_scg);

        lineEdit_scb = new QLineEdit(widget_11);
        lineEdit_scb->setObjectName(QString::fromUtf8("lineEdit_scb"));

        horizontalLayout_7->addWidget(lineEdit_scb);


        verticalLayout_10->addWidget(widget_11);


        verticalLayout_8->addWidget(widget_8);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

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
        menu->addAction(actionLoadModel);
        menu->addAction(menu_2->menuAction());
        menu->addSeparator();
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

        tabWidget_2->setCurrentIndex(1);


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
        radioButton_pointlight1->setText(QApplication::translate("PBR_RendererClass", "\347\202\271\345\205\211\346\272\2201", nullptr));
        label->setText(QApplication::translate("PBR_RendererClass", "position", nullptr));
        label_2->setText(QApplication::translate("PBR_RendererClass", "color", nullptr));
        radioButton_pointlight2->setText(QApplication::translate("PBR_RendererClass", "\347\202\271\345\205\211\346\272\2202", nullptr));
        label_3->setText(QApplication::translate("PBR_RendererClass", "position", nullptr));
        label_4->setText(QApplication::translate("PBR_RendererClass", "color", nullptr));
        radioButton_spotlight->setText(QApplication::translate("PBR_RendererClass", "\346\211\213\347\224\265\347\255\222", nullptr));
        label_5->setText(QApplication::translate("PBR_RendererClass", "position", nullptr));
        label_6->setText(QApplication::translate("PBR_RendererClass", "direction", nullptr));
        label_7->setText(QApplication::translate("PBR_RendererClass", "color", nullptr));
        envButton->setText(QApplication::translate("PBR_RendererClass", "\351\200\211\346\213\251\347\216\257\345\242\203\350\264\264\345\233\276", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(skybox), QApplication::translate("PBR_RendererClass", "\347\216\257\345\242\203\350\264\264\345\233\276\344\270\216\345\205\211\346\272\220", nullptr));
        informationDockWidget->setWindowTitle(QApplication::translate("PBR_RendererClass", "\345\261\236\346\200\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PBR_RendererClass: public Ui_PBR_RendererClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PBR_RENDERER_H

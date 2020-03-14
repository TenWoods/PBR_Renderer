/********************************************************************************
** Form generated from reading UI file 'Property.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTY_H
#define UI_PROPERTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Property
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *textureonoffButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_17;
    QLineEdit *px;
    QLineEdit *py;
    QLineEdit *pz;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_18;
    QLineEdit *sx;
    QLineEdit *sy;
    QLineEdit *sz;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_19;
    QLineEdit *rx;
    QLineEdit *ry;
    QLineEdit *rz;
    QWidget *colorWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *colorR;
    QLineEdit *colorG;
    QLineEdit *colorB;
    QWidget *metallicWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *metallicSlider;
    QLineEdit *metallicEdit;
    QWidget *roughnessWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *roughnessSlider;
    QLineEdit *roughnessEdit;
    QWidget *aoWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *aoSlider;
    QLineEdit *aoEdit;
    QWidget *diffuseWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QPushButton *diffuseButton;
    QLabel *label_11;
    QWidget *specularWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QPushButton *specularButton;
    QLabel *label_12;
    QWidget *normalWidget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QPushButton *normalButton;
    QLabel *label_13;
    QWidget *metallictexWidget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QPushButton *metallicButton;
    QLabel *label_14;
    QWidget *roughnesstexWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QPushButton *roughnessButton;
    QLabel *label_15;
    QWidget *aotexWidget;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QPushButton *AOButton;
    QLabel *label_16;

    void setupUi(QWidget *Property)
    {
        if (Property->objectName().isEmpty())
            Property->setObjectName(QString::fromUtf8("Property"));
        Property->resize(332, 540);
        verticalLayout = new QVBoxLayout(Property);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(Property);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 295, 630));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textureonoffButton = new QRadioButton(scrollAreaWidgetContents);
        textureonoffButton->setObjectName(QString::fromUtf8("textureonoffButton"));
        textureonoffButton->setChecked(false);

        verticalLayout_2->addWidget(textureonoffButton);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_11 = new QHBoxLayout(widget);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_17 = new QLabel(widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_11->addWidget(label_17);

        px = new QLineEdit(widget);
        px->setObjectName(QString::fromUtf8("px"));

        horizontalLayout_11->addWidget(px);

        py = new QLineEdit(widget);
        py->setObjectName(QString::fromUtf8("py"));

        horizontalLayout_11->addWidget(py);

        pz = new QLineEdit(widget);
        pz->setObjectName(QString::fromUtf8("pz"));

        horizontalLayout_11->addWidget(pz);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_12 = new QHBoxLayout(widget_3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_12->addWidget(label_18);

        sx = new QLineEdit(widget_3);
        sx->setObjectName(QString::fromUtf8("sx"));

        horizontalLayout_12->addWidget(sx);

        sy = new QLineEdit(widget_3);
        sy->setObjectName(QString::fromUtf8("sy"));

        horizontalLayout_12->addWidget(sy);

        sz = new QLineEdit(widget_3);
        sz->setObjectName(QString::fromUtf8("sz"));

        horizontalLayout_12->addWidget(sz);


        verticalLayout_2->addWidget(widget_3);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_13 = new QHBoxLayout(widget_2);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_19 = new QLabel(widget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_13->addWidget(label_19);

        rx = new QLineEdit(widget_2);
        rx->setObjectName(QString::fromUtf8("rx"));

        horizontalLayout_13->addWidget(rx);

        ry = new QLineEdit(widget_2);
        ry->setObjectName(QString::fromUtf8("ry"));

        horizontalLayout_13->addWidget(ry);

        rz = new QLineEdit(widget_2);
        rz->setObjectName(QString::fromUtf8("rz"));

        horizontalLayout_13->addWidget(rz);


        verticalLayout_2->addWidget(widget_2);

        colorWidget = new QWidget(scrollAreaWidgetContents);
        colorWidget->setObjectName(QString::fromUtf8("colorWidget"));
        horizontalLayout = new QHBoxLayout(colorWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(colorWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        colorR = new QLineEdit(colorWidget);
        colorR->setObjectName(QString::fromUtf8("colorR"));
        colorR->setEnabled(true);

        horizontalLayout->addWidget(colorR);

        colorG = new QLineEdit(colorWidget);
        colorG->setObjectName(QString::fromUtf8("colorG"));

        horizontalLayout->addWidget(colorG);

        colorB = new QLineEdit(colorWidget);
        colorB->setObjectName(QString::fromUtf8("colorB"));

        horizontalLayout->addWidget(colorB);


        verticalLayout_2->addWidget(colorWidget);

        metallicWidget = new QWidget(scrollAreaWidgetContents);
        metallicWidget->setObjectName(QString::fromUtf8("metallicWidget"));
        horizontalLayout_2 = new QHBoxLayout(metallicWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(metallicWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        metallicSlider = new QSlider(metallicWidget);
        metallicSlider->setObjectName(QString::fromUtf8("metallicSlider"));
        metallicSlider->setMaximum(100);
        metallicSlider->setValue(0);
        metallicSlider->setOrientation(Qt::Horizontal);
        metallicSlider->setTickPosition(QSlider::NoTicks);
        metallicSlider->setTickInterval(0);

        horizontalLayout_2->addWidget(metallicSlider);

        metallicEdit = new QLineEdit(metallicWidget);
        metallicEdit->setObjectName(QString::fromUtf8("metallicEdit"));

        horizontalLayout_2->addWidget(metallicEdit);


        verticalLayout_2->addWidget(metallicWidget);

        roughnessWidget = new QWidget(scrollAreaWidgetContents);
        roughnessWidget->setObjectName(QString::fromUtf8("roughnessWidget"));
        horizontalLayout_3 = new QHBoxLayout(roughnessWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(roughnessWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        roughnessSlider = new QSlider(roughnessWidget);
        roughnessSlider->setObjectName(QString::fromUtf8("roughnessSlider"));
        roughnessSlider->setMinimum(5);
        roughnessSlider->setMaximum(100);
        roughnessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(roughnessSlider);

        roughnessEdit = new QLineEdit(roughnessWidget);
        roughnessEdit->setObjectName(QString::fromUtf8("roughnessEdit"));

        horizontalLayout_3->addWidget(roughnessEdit);


        verticalLayout_2->addWidget(roughnessWidget);

        aoWidget = new QWidget(scrollAreaWidgetContents);
        aoWidget->setObjectName(QString::fromUtf8("aoWidget"));
        aoWidget->setEnabled(true);
        horizontalLayout_4 = new QHBoxLayout(aoWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(aoWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        aoSlider = new QSlider(aoWidget);
        aoSlider->setObjectName(QString::fromUtf8("aoSlider"));
        aoSlider->setMaximum(100);
        aoSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(aoSlider);

        aoEdit = new QLineEdit(aoWidget);
        aoEdit->setObjectName(QString::fromUtf8("aoEdit"));

        horizontalLayout_4->addWidget(aoEdit);


        verticalLayout_2->addWidget(aoWidget);

        diffuseWidget = new QWidget(scrollAreaWidgetContents);
        diffuseWidget->setObjectName(QString::fromUtf8("diffuseWidget"));
        horizontalLayout_5 = new QHBoxLayout(diffuseWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(diffuseWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        diffuseButton = new QPushButton(diffuseWidget);
        diffuseButton->setObjectName(QString::fromUtf8("diffuseButton"));

        horizontalLayout_5->addWidget(diffuseButton);

        label_11 = new QLabel(diffuseWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_5->addWidget(label_11);


        verticalLayout_2->addWidget(diffuseWidget);

        specularWidget = new QWidget(scrollAreaWidgetContents);
        specularWidget->setObjectName(QString::fromUtf8("specularWidget"));
        horizontalLayout_6 = new QHBoxLayout(specularWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(specularWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        specularButton = new QPushButton(specularWidget);
        specularButton->setObjectName(QString::fromUtf8("specularButton"));

        horizontalLayout_6->addWidget(specularButton);

        label_12 = new QLabel(specularWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_6->addWidget(label_12);


        verticalLayout_2->addWidget(specularWidget);

        normalWidget = new QWidget(scrollAreaWidgetContents);
        normalWidget->setObjectName(QString::fromUtf8("normalWidget"));
        horizontalLayout_9 = new QHBoxLayout(normalWidget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(normalWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        normalButton = new QPushButton(normalWidget);
        normalButton->setObjectName(QString::fromUtf8("normalButton"));

        horizontalLayout_9->addWidget(normalButton);

        label_13 = new QLabel(normalWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_9->addWidget(label_13);


        verticalLayout_2->addWidget(normalWidget);

        metallictexWidget = new QWidget(scrollAreaWidgetContents);
        metallictexWidget->setObjectName(QString::fromUtf8("metallictexWidget"));
        horizontalLayout_8 = new QHBoxLayout(metallictexWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(metallictexWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        metallicButton = new QPushButton(metallictexWidget);
        metallicButton->setObjectName(QString::fromUtf8("metallicButton"));

        horizontalLayout_8->addWidget(metallicButton);

        label_14 = new QLabel(metallictexWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_8->addWidget(label_14);


        verticalLayout_2->addWidget(metallictexWidget);

        roughnesstexWidget = new QWidget(scrollAreaWidgetContents);
        roughnesstexWidget->setObjectName(QString::fromUtf8("roughnesstexWidget"));
        horizontalLayout_7 = new QHBoxLayout(roughnesstexWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(roughnesstexWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        roughnessButton = new QPushButton(roughnesstexWidget);
        roughnessButton->setObjectName(QString::fromUtf8("roughnessButton"));

        horizontalLayout_7->addWidget(roughnessButton);

        label_15 = new QLabel(roughnesstexWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_7->addWidget(label_15);


        verticalLayout_2->addWidget(roughnesstexWidget);

        aotexWidget = new QWidget(scrollAreaWidgetContents);
        aotexWidget->setObjectName(QString::fromUtf8("aotexWidget"));
        horizontalLayout_10 = new QHBoxLayout(aotexWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(aotexWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        AOButton = new QPushButton(aotexWidget);
        AOButton->setObjectName(QString::fromUtf8("AOButton"));

        horizontalLayout_10->addWidget(AOButton);

        label_16 = new QLabel(aotexWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_10->addWidget(label_16);


        verticalLayout_2->addWidget(aotexWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Property);

        QMetaObject::connectSlotsByName(Property);
    } // setupUi

    void retranslateUi(QWidget *Property)
    {
        Property->setWindowTitle(QApplication::translate("Property", "Property", nullptr));
        textureonoffButton->setText(QApplication::translate("Property", "\345\274\200\345\220\257\350\264\264\345\233\276\346\250\241\345\274\217", nullptr));
        label_17->setText(QApplication::translate("Property", "Position", nullptr));
        px->setText(QApplication::translate("Property", "0", nullptr));
        py->setText(QApplication::translate("Property", "0", nullptr));
        pz->setText(QApplication::translate("Property", "0", nullptr));
        label_18->setText(QApplication::translate("Property", "Scale", nullptr));
        sx->setText(QApplication::translate("Property", "1", nullptr));
        sy->setText(QApplication::translate("Property", "1", nullptr));
        sz->setText(QApplication::translate("Property", "1", nullptr));
        label_19->setText(QApplication::translate("Property", "Rotation", nullptr));
        rx->setText(QApplication::translate("Property", "0", nullptr));
        ry->setText(QApplication::translate("Property", "0", nullptr));
        rz->setText(QApplication::translate("Property", "0", nullptr));
        label->setText(QApplication::translate("Property", "Color", nullptr));
        colorR->setText(QApplication::translate("Property", "1", nullptr));
        colorG->setText(QApplication::translate("Property", "1", nullptr));
        colorB->setText(QApplication::translate("Property", "1", nullptr));
        label_2->setText(QApplication::translate("Property", "Metallic", nullptr));
        label_3->setText(QApplication::translate("Property", "Roughness", nullptr));
        label_4->setText(QApplication::translate("Property", "AO", nullptr));
        label_5->setText(QApplication::translate("Property", "Diffuse Texture", nullptr));
        diffuseButton->setText(QApplication::translate("Property", "\351\200\211\346\213\251\350\264\264\345\233\276", nullptr));
        label_11->setText(QApplication::translate("Property", "diffuse", nullptr));
        label_7->setText(QApplication::translate("Property", "Specular Texture", nullptr));
        specularButton->setText(QApplication::translate("Property", "\351\200\211\346\213\251\350\264\264\345\233\276", nullptr));
        label_12->setText(QApplication::translate("Property", "specular", nullptr));
        label_8->setText(QApplication::translate("Property", "Normal", nullptr));
        normalButton->setText(QApplication::translate("Property", "\351\200\211\346\213\251\350\264\264\345\233\276", nullptr));
        label_13->setText(QApplication::translate("Property", "normal", nullptr));
        label_9->setText(QApplication::translate("Property", "Metallic Texture", nullptr));
        metallicButton->setText(QApplication::translate("Property", "\351\200\211\346\213\251\350\264\264\345\233\276", nullptr));
        label_14->setText(QApplication::translate("Property", "metaliic", nullptr));
        label_10->setText(QApplication::translate("Property", "Roughness Texture", nullptr));
        roughnessButton->setText(QApplication::translate("Property", "\351\200\211\346\213\251\350\264\264\345\233\276", nullptr));
        label_15->setText(QApplication::translate("Property", "rougnness", nullptr));
        label_6->setText(QApplication::translate("Property", "AO Texture", nullptr));
        AOButton->setText(QApplication::translate("Property", "\351\200\211\346\213\251\350\264\264\345\233\276", nullptr));
        label_16->setText(QApplication::translate("Property", "ao", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Property: public Ui_Property {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTY_H

/********************************************************************************
** Form generated from reading UI file 'buttongroup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONGROUP_H
#define UI_BUTTONGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_ButtonGroup
{
public:
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *startPage;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    MyButton *start;
    QSpacerItem *horizontalSpacer_2;
    QWidget *callLordPage;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    MyButton *giveup;
    QSpacerItem *horizontalSpacer_10;
    MyButton *oneScore;
    QSpacerItem *horizontalSpacer_11;
    MyButton *twoScore;
    QSpacerItem *horizontalSpacer_12;
    MyButton *threeScore;
    QSpacerItem *horizontalSpacer_9;
    QWidget *playCardPage;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    MyButton *playCard;
    QSpacerItem *horizontalSpacer_4;
    QWidget *passOrPlayPage;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    MyButton *pass;
    QSpacerItem *horizontalSpacer_5;
    MyButton *playCard1;
    QSpacerItem *horizontalSpacer_7;
    QWidget *nullPage;

    void setupUi(QWidget *ButtonGroup)
    {
        if (ButtonGroup->objectName().isEmpty())
            ButtonGroup->setObjectName("ButtonGroup");
        ButtonGroup->resize(594, 322);
        horizontalLayout_2 = new QHBoxLayout(ButtonGroup);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(ButtonGroup);
        stackedWidget->setObjectName("stackedWidget");
        startPage = new QWidget();
        startPage->setObjectName("startPage");
        horizontalLayout = new QHBoxLayout(startPage);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(244, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        start = new MyButton(startPage);
        start->setObjectName("start");

        horizontalLayout->addWidget(start);

        horizontalSpacer_2 = new QSpacerItem(244, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(startPage);
        callLordPage = new QWidget();
        callLordPage->setObjectName("callLordPage");
        horizontalLayout_5 = new QHBoxLayout(callLordPage);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_8 = new QSpacerItem(52, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        giveup = new MyButton(callLordPage);
        giveup->setObjectName("giveup");

        horizontalLayout_5->addWidget(giveup);

        horizontalSpacer_10 = new QSpacerItem(40, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        oneScore = new MyButton(callLordPage);
        oneScore->setObjectName("oneScore");

        horizontalLayout_5->addWidget(oneScore);

        horizontalSpacer_11 = new QSpacerItem(40, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        twoScore = new MyButton(callLordPage);
        twoScore->setObjectName("twoScore");

        horizontalLayout_5->addWidget(twoScore);

        horizontalSpacer_12 = new QSpacerItem(40, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        threeScore = new MyButton(callLordPage);
        threeScore->setObjectName("threeScore");

        horizontalLayout_5->addWidget(threeScore);

        horizontalSpacer_9 = new QSpacerItem(52, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        stackedWidget->addWidget(callLordPage);
        playCardPage = new QWidget();
        playCardPage->setObjectName("playCardPage");
        horizontalLayout_3 = new QHBoxLayout(playCardPage);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(244, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        playCard = new MyButton(playCardPage);
        playCard->setObjectName("playCard");

        horizontalLayout_3->addWidget(playCard);

        horizontalSpacer_4 = new QSpacerItem(244, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        stackedWidget->addWidget(playCardPage);
        passOrPlayPage = new QWidget();
        passOrPlayPage->setObjectName("passOrPlayPage");
        horizontalLayout_4 = new QHBoxLayout(passOrPlayPage);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_6 = new QSpacerItem(179, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        pass = new MyButton(passOrPlayPage);
        pass->setObjectName("pass");

        horizontalLayout_4->addWidget(pass);

        horizontalSpacer_5 = new QSpacerItem(40, 15, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        playCard1 = new MyButton(passOrPlayPage);
        playCard1->setObjectName("playCard1");

        horizontalLayout_4->addWidget(playCard1);

        horizontalSpacer_7 = new QSpacerItem(178, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        stackedWidget->addWidget(passOrPlayPage);
        nullPage = new QWidget();
        nullPage->setObjectName("nullPage");
        stackedWidget->addWidget(nullPage);

        horizontalLayout_2->addWidget(stackedWidget);


        retranslateUi(ButtonGroup);

        QMetaObject::connectSlotsByName(ButtonGroup);
    } // setupUi

    void retranslateUi(QWidget *ButtonGroup)
    {
        ButtonGroup->setWindowTitle(QCoreApplication::translate("ButtonGroup", "Form", nullptr));
        start->setText(QCoreApplication::translate("ButtonGroup", "PushButton", nullptr));
        giveup->setText(QCoreApplication::translate("ButtonGroup", "PushButton", nullptr));
        oneScore->setText(QCoreApplication::translate("ButtonGroup", "PushButton", nullptr));
        twoScore->setText(QCoreApplication::translate("ButtonGroup", "PushButton", nullptr));
        threeScore->setText(QCoreApplication::translate("ButtonGroup", "PushButton", nullptr));
        playCard->setText(QCoreApplication::translate("ButtonGroup", "PushButton", nullptr));
        pass->setText(QCoreApplication::translate("ButtonGroup", "PushButton", nullptr));
        playCard1->setText(QCoreApplication::translate("ButtonGroup", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ButtonGroup: public Ui_ButtonGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONGROUP_H

/********************************************************************************
** Form generated from reading UI file 'scorepanel.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREPANEL_H
#define UI_SCOREPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScorePanel
{
public:
    QGridLayout *gridLayout;
    QLabel *leftTitle;
    QLabel *score1;
    QLabel *rightScore;
    QLabel *meScore;
    QLabel *leftScore;
    QLabel *score3;
    QLabel *rightTitle;
    QLabel *meTitle;
    QLabel *score2;

    void setupUi(QWidget *ScorePanel)
    {
        if (ScorePanel->objectName().isEmpty())
            ScorePanel->setObjectName("ScorePanel");
        ScorePanel->resize(388, 220);
        ScorePanel->setMinimumSize(QSize(0, 0));
        ScorePanel->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(ScorePanel);
        gridLayout->setObjectName("gridLayout");
        leftTitle = new QLabel(ScorePanel);
        leftTitle->setObjectName("leftTitle");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(12);
        font.setBold(true);
        leftTitle->setFont(font);
        leftTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(leftTitle, 1, 0, 1, 1);

        score1 = new QLabel(ScorePanel);
        score1->setObjectName("score1");
        score1->setFont(font);
        score1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(score1, 0, 2, 1, 1);

        rightScore = new QLabel(ScorePanel);
        rightScore->setObjectName("rightScore");
        rightScore->setMaximumSize(QSize(16777215, 200));
        rightScore->setFont(font);
        rightScore->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(rightScore, 2, 1, 1, 1);

        meScore = new QLabel(ScorePanel);
        meScore->setObjectName("meScore");
        meScore->setFont(font);
        meScore->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(meScore, 0, 1, 1, 1);

        leftScore = new QLabel(ScorePanel);
        leftScore->setObjectName("leftScore");
        leftScore->setFont(font);
        leftScore->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(leftScore, 1, 1, 1, 1);

        score3 = new QLabel(ScorePanel);
        score3->setObjectName("score3");
        score3->setFont(font);
        score3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(score3, 2, 2, 1, 1);

        rightTitle = new QLabel(ScorePanel);
        rightTitle->setObjectName("rightTitle");
        rightTitle->setFont(font);
        rightTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(rightTitle, 2, 0, 1, 1);

        meTitle = new QLabel(ScorePanel);
        meTitle->setObjectName("meTitle");
        meTitle->setFont(font);
        meTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(meTitle, 0, 0, 1, 1);

        score2 = new QLabel(ScorePanel);
        score2->setObjectName("score2");
        score2->setFont(font);
        score2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(score2, 1, 2, 1, 1);


        retranslateUi(ScorePanel);

        QMetaObject::connectSlotsByName(ScorePanel);
    } // setupUi

    void retranslateUi(QWidget *ScorePanel)
    {
        ScorePanel->setWindowTitle(QCoreApplication::translate("ScorePanel", "Form", nullptr));
        leftTitle->setText(QCoreApplication::translate("ScorePanel", "\345\267\246\344\276\247\346\234\272\345\231\250\344\272\272", nullptr));
        score1->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
        rightScore->setText(QString());
        meScore->setText(QString());
        leftScore->setText(QString());
        score3->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
        rightTitle->setText(QCoreApplication::translate("ScorePanel", "\345\217\263\344\276\247\346\234\272\345\231\250\344\272\272", nullptr));
        meTitle->setText(QCoreApplication::translate("ScorePanel", "\346\210\221", nullptr));
        score2->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScorePanel: public Ui_ScorePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREPANEL_H

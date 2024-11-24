/********************************************************************************
** Form generated from reading UI file 'mytable.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTABLE_H
#define UI_MYTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mytable
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *firstButton;
    QPushButton *pastButton;
    QLabel *pagelabel;
    QPushButton *nextButton;
    QPushButton *lastButton;
    QSpinBox *pageBox;
    QPushButton *jumpButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *submitButton;
    QPushButton *addButton;
    QPushButton *delButton;
    QPushButton *flushButton;

    void setupUi(QWidget *mytable)
    {
        if (mytable->objectName().isEmpty())
            mytable->setObjectName("mytable");
        mytable->resize(1049, 525);
        verticalLayout = new QVBoxLayout(mytable);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(mytable);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox = new QGroupBox(mytable);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        firstButton = new QPushButton(groupBox);
        firstButton->setObjectName("firstButton");

        horizontalLayout_2->addWidget(firstButton);

        pastButton = new QPushButton(groupBox);
        pastButton->setObjectName("pastButton");

        horizontalLayout_2->addWidget(pastButton);

        pagelabel = new QLabel(groupBox);
        pagelabel->setObjectName("pagelabel");

        horizontalLayout_2->addWidget(pagelabel);

        nextButton = new QPushButton(groupBox);
        nextButton->setObjectName("nextButton");

        horizontalLayout_2->addWidget(nextButton);

        lastButton = new QPushButton(groupBox);
        lastButton->setObjectName("lastButton");

        horizontalLayout_2->addWidget(lastButton);

        pageBox = new QSpinBox(groupBox);
        pageBox->setObjectName("pageBox");
        pageBox->setMaximum(1000000);

        horizontalLayout_2->addWidget(pageBox);

        jumpButton = new QPushButton(groupBox);
        jumpButton->setObjectName("jumpButton");

        horizontalLayout_2->addWidget(jumpButton);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(mytable);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        submitButton = new QPushButton(groupBox_2);
        submitButton->setObjectName("submitButton");

        horizontalLayout_4->addWidget(submitButton);

        addButton = new QPushButton(groupBox_2);
        addButton->setObjectName("addButton");

        horizontalLayout_4->addWidget(addButton);

        delButton = new QPushButton(groupBox_2);
        delButton->setObjectName("delButton");

        horizontalLayout_4->addWidget(delButton);

        flushButton = new QPushButton(groupBox_2);
        flushButton->setObjectName("flushButton");

        horizontalLayout_4->addWidget(flushButton);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(mytable);

        QMetaObject::connectSlotsByName(mytable);
    } // setupUi

    void retranslateUi(QWidget *mytable)
    {
        mytable->setWindowTitle(QCoreApplication::translate("mytable", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mytable", "\351\241\265\351\235\242", nullptr));
        firstButton->setText(QCoreApplication::translate("mytable", "\351\246\226\351\241\265", nullptr));
        pastButton->setText(QCoreApplication::translate("mytable", "\344\270\212\351\241\265", nullptr));
        pagelabel->setText(QCoreApplication::translate("mytable", "TextLabel", nullptr));
        nextButton->setText(QCoreApplication::translate("mytable", "\344\270\213\351\241\265", nullptr));
        lastButton->setText(QCoreApplication::translate("mytable", "\345\260\276\351\241\265", nullptr));
        jumpButton->setText(QCoreApplication::translate("mytable", "\350\267\263\350\275\254", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("mytable", "\347\274\226\350\276\221", nullptr));
        submitButton->setText(QCoreApplication::translate("mytable", "\344\277\256\346\224\271\346\217\220\344\272\244", nullptr));
        addButton->setText(QCoreApplication::translate("mytable", "\346\267\273\345\212\240", nullptr));
        delButton->setText(QCoreApplication::translate("mytable", "\345\210\240\351\231\244", nullptr));
        flushButton->setText(QCoreApplication::translate("mytable", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mytable: public Ui_mytable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTABLE_H

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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *firstButton;
    QPushButton *pastButton;
    QLabel *pagelabel;
    QPushButton *nextButton;
    QPushButton *lastButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *pageBox;
    QPushButton *jumpButton;
    QPushButton *flushButton;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *uidEdit;
    QLabel *label_2;
    QDoubleSpinBox *balanceSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *stateEdit;
    QPushButton *payButton;
    QDoubleSpinBox *paySpinBox;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *newpasswordEdit;
    QLabel *label_5;
    QLineEdit *confirmEdit;
    QPushButton *submitButton;

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
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(mytable);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
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


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(mytable);
        groupBox_2->setObjectName("groupBox_2");
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pageBox = new QSpinBox(groupBox_2);
        pageBox->setObjectName("pageBox");
        pageBox->setMaximum(1000000);

        horizontalLayout_4->addWidget(pageBox);

        jumpButton = new QPushButton(groupBox_2);
        jumpButton->setObjectName("jumpButton");

        horizontalLayout_4->addWidget(jumpButton);

        flushButton = new QPushButton(groupBox_2);
        flushButton->setObjectName("flushButton");

        horizontalLayout_4->addWidget(flushButton);


        verticalLayout_2->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox_3 = new QGroupBox(mytable);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label);

        uidEdit = new QLineEdit(groupBox_3);
        uidEdit->setObjectName("uidEdit");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(uidEdit->sizePolicy().hasHeightForWidth());
        uidEdit->setSizePolicy(sizePolicy3);
        uidEdit->setMaxLength(20);
        uidEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(uidEdit);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_2);

        balanceSpinBox = new QDoubleSpinBox(groupBox_3);
        balanceSpinBox->setObjectName("balanceSpinBox");
        balanceSpinBox->setReadOnly(true);
        balanceSpinBox->setMaximum(9999.989999999999782);

        horizontalLayout_5->addWidget(balanceSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_3);

        stateEdit = new QLineEdit(groupBox_3);
        stateEdit->setObjectName("stateEdit");
        sizePolicy3.setHeightForWidth(stateEdit->sizePolicy().hasHeightForWidth());
        stateEdit->setSizePolicy(sizePolicy3);
        stateEdit->setMaxLength(20);
        stateEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(stateEdit);

        payButton = new QPushButton(groupBox_3);
        payButton->setObjectName("payButton");

        horizontalLayout_3->addWidget(payButton);

        paySpinBox = new QDoubleSpinBox(groupBox_3);
        paySpinBox->setObjectName("paySpinBox");
        paySpinBox->setMaximum(999.990000000000009);

        horizontalLayout_3->addWidget(paySpinBox);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(mytable);
        groupBox_4->setObjectName("groupBox_4");
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName("label_4");
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label_4);

        newpasswordEdit = new QLineEdit(groupBox_4);
        newpasswordEdit->setObjectName("newpasswordEdit");
        newpasswordEdit->setMaxLength(30);
        newpasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(newpasswordEdit);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName("label_5");
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label_5);

        confirmEdit = new QLineEdit(groupBox_4);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setMaxLength(30);
        confirmEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(confirmEdit);

        submitButton = new QPushButton(groupBox_4);
        submitButton->setObjectName("submitButton");

        horizontalLayout_6->addWidget(submitButton);


        verticalLayout_3->addWidget(groupBox_4);


        horizontalLayout->addLayout(verticalLayout_3);


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
        groupBox_2->setTitle(QCoreApplication::translate("mytable", "\350\267\263\350\275\254", nullptr));
        jumpButton->setText(QCoreApplication::translate("mytable", "\350\267\263\350\275\254", nullptr));
        flushButton->setText(QCoreApplication::translate("mytable", "\345\210\267\346\226\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("mytable", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("mytable", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("mytable", "\344\275\231\351\242\235", nullptr));
        label_3->setText(QCoreApplication::translate("mytable", "\347\212\266\346\200\201", nullptr));
        payButton->setText(QCoreApplication::translate("mytable", "\345\205\205\345\200\274", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("mytable", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("mytable", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("mytable", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        submitButton->setText(QCoreApplication::translate("mytable", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mytable: public Ui_mytable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTABLE_H

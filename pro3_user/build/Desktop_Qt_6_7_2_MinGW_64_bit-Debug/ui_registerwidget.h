/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *uidEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QLabel *label_3;
    QLineEdit *confirmEdit;
    QVBoxLayout *verticalLayout_5;
    QLabel *errorlabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *registerButton;
    QPushButton *jumpButton;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName("RegisterWidget");
        RegisterWidget->resize(613, 404);
        verticalLayout_2 = new QVBoxLayout(RegisterWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(RegisterWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        uidEdit = new QLineEdit(RegisterWidget);
        uidEdit->setObjectName("uidEdit");
        uidEdit->setMaxLength(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, uidEdit);

        label_2 = new QLabel(RegisterWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        passwordEdit = new QLineEdit(RegisterWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setMaxLength(30);
        passwordEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordEdit);

        label_3 = new QLabel(RegisterWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        confirmEdit = new QLineEdit(RegisterWidget);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setMaxLength(30);
        confirmEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, confirmEdit);


        verticalLayout_3->addLayout(formLayout);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        errorlabel = new QLabel(RegisterWidget);
        errorlabel->setObjectName("errorlabel");

        verticalLayout_5->addWidget(errorlabel);


        verticalLayout->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        registerButton = new QPushButton(RegisterWidget);
        registerButton->setObjectName("registerButton");

        horizontalLayout->addWidget(registerButton);

        jumpButton = new QPushButton(RegisterWidget);
        jumpButton->setObjectName("jumpButton");

        horizontalLayout->addWidget(jumpButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QCoreApplication::translate("RegisterWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("RegisterWidget", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWidget", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWidget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        errorlabel->setText(QString());
        registerButton->setText(QCoreApplication::translate("RegisterWidget", "\346\263\250\345\206\214", nullptr));
        jumpButton->setText(QCoreApplication::translate("RegisterWidget", "\345\267\262\346\234\211\350\264\246\346\210\267\357\274\237\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H

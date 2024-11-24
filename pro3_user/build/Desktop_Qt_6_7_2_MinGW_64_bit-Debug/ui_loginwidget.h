/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

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

class Ui_LoginWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *uidEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *errorLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *jumpButton;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName("LoginWidget");
        LoginWidget->resize(599, 303);
        verticalLayout_2 = new QVBoxLayout(LoginWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(LoginWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        uidEdit = new QLineEdit(LoginWidget);
        uidEdit->setObjectName("uidEdit");
        uidEdit->setMaxLength(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, uidEdit);

        label_2 = new QLabel(LoginWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        passwordEdit = new QLineEdit(LoginWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setMaxLength(30);
        passwordEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        errorLabel = new QLabel(LoginWidget);
        errorLabel->setObjectName("errorLabel");

        horizontalLayout_2->addWidget(errorLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        loginButton = new QPushButton(LoginWidget);
        loginButton->setObjectName("loginButton");

        horizontalLayout->addWidget(loginButton);

        jumpButton = new QPushButton(LoginWidget);
        jumpButton->setObjectName("jumpButton");

        horizontalLayout->addWidget(jumpButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoginWidget", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWidget", "\345\257\206\347\240\201", nullptr));
        errorLabel->setText(QString());
        loginButton->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        jumpButton->setText(QCoreApplication::translate("LoginWidget", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H

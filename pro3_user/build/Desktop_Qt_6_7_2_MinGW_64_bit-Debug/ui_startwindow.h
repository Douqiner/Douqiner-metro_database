/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *mainLayout;

    void setupUi(QWidget *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(400, 160);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/img/day.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        StartWindow->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(StartWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        mainLayout = new QVBoxLayout();
        mainLayout->setObjectName("mainLayout");

        horizontalLayout->addLayout(mainLayout);


        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QWidget *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H

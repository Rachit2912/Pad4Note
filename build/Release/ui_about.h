/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(265, 241);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(About->sizePolicy().hasHeightForWidth());
        About->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(About);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(About);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic")});
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;}\n"
"\n"
"QLabel:hover {\n"
"    text-decoration: underline; \n"
"    color: aqua;\n"
"background-color:black;              \n"
"border-radius:15;\n"
"}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(About);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rage")});
        font1.setPointSize(18);
        font1.setItalic(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;}\n"
"\n"
"QLabel:hover {\n"
"    text-decoration: underline; \n"
"    color: aqua;\n"
"background-color:black;              \n"
"border-radius:15;\n"
"}"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignmentFlag::AlignHCenter);

        label_3 = new QLabel(About);
        label_3->setObjectName("label_3");
        label_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}\n"
"\n"
"QLabel:hover {\n"
"\n"
"    text-decoration: underline; \n"
"text-decoration-color:aqua;\n"
"    color: aqua;\n"
"background-color:black;                \n"
"border-radius:15;\n"
"}"));

        verticalLayout->addWidget(label_3, 0, Qt::AlignmentFlag::AlignHCenter);

        pushButton = new QPushButton(About);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("About", "Pad4Note", nullptr));
        label_2->setText(QCoreApplication::translate("About", "Rachit Joshi ", nullptr));
        label_3->setText(QCoreApplication::translate("About", "https://github.com/Rachit2912", nullptr));
        pushButton->setText(QCoreApplication::translate("About", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H

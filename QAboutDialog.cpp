#include "QAboutDialog.h"

QAboutDialog::QAboutDialog()
{
    QVBoxLayout *Layout = new QVBoxLayout(this);
    QLabel *author = new QLabel(this);
    QLabel *email = new QLabel(this);
    QLabel *ver = new QLabel(this);
    QLabel *explanation = new QLabel(this);
    QPushButton *ok = new QPushButton(tr("OK"),this);

    author->setText(tr("author: huwenbo"));
    email->setText(tr("email: huwenbo518@163.com"));
    ver->setText(tr("ver: 0.1"));
    explanation->setText(tr("This is a beta version, some function not complete.\nIf you have any problem please send email to me."));


    author->setAlignment(Qt::AlignCenter);
    email->setAlignment(Qt::AlignCenter);
    ver->setAlignment(Qt::AlignCenter);

    Layout->addWidget(author);
    Layout->addWidget(email);
    Layout->addWidget(ver);
    Layout->addWidget(explanation);
    Layout->addWidget(ok);
    connect(ok,SIGNAL(clicked()),this,SLOT(close()));
}

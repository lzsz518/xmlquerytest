#include "QHelpDialog.h"

QHelpDialog::QHelpDialog()
{
    QVBoxLayout *Layout = new QVBoxLayout(this);
    QLabel *step1 = new QLabel(this);
    QLabel *step2 = new QLabel(this);
    QLabel *step3 = new QLabel(this);
    QLabel *step4 = new QLabel(this);
    QPushButton *ok = new QPushButton(tr("OK"),this);

    step1->setText(tr("step1: Open a xml file."));
    step2->setText(tr("step2: Input XQuery in the XPath/XQuery edit box."));
    step3->setText(tr("step3: Selected ExecQuery menu."));
    step4->setText(tr("step4: Brows result with Output edit box."));

    Layout->addWidget(step1);
    Layout->addWidget(step2);
    Layout->addWidget(step3);
    Layout->addWidget(step4);
    Layout->addWidget(ok);
    connect(ok,SIGNAL(clicked()),this,SLOT(close()));
}
